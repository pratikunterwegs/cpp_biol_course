/*
 * a program to grow some protofilaments
 *
 * first, make an empty vector
 * draw the first element of the vector as the "base"
 * this could also be 0, the first element, easier.
 *
 * add a dimer: the distance to the barrier will now
 * be 0 nm for this protofil.
 * relative to the previous element, the next
 * dimer's position is now h/13 lower/higher = or 8/13 lower/higher.
 * the distance to the barrier for this next protofil
 * is thus h/13. the next (3rd) PF is 2h/13 lower or higher than the first,
 * and equally far from the barrier.
 * make a vector of 13 such PFs.
 *
 * at each step, choose a random PF. check if it's distance
 * to the barrier is < 8nm, one dimer length.
 * implement the probability of attaching or detaching
 * another dimer there. -- increasing or decreasing position by 8 nm.
 *
 * Mt = microtubule; Pf = protofilament
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <random>
#include <chrono>
#include <algorithm>
#include <cmath>
std::mt19937_64 rng;

using namespace std;

//system parameters
const int nFils = 13; //pfs in an mt
const double dimerLength = 8.0; //dimer length in nm (1e-9)
const double offset = dimerLength / 13.0; //offset length in nM (1e-9)
const double tMax = 100.0; //time limit for the Gillespie loop
const double Temp = 298.0; //temp in K
const double kB = 1.3806485e-23;
const int nEvents = nFils + 1; //implemet 2 events - dimer on or off
double force = 1.0e-12; //force starts at 1 piconewton
const double kOn = 200.0; //rate of elongation per minute
const double kOff = 50.0; //rate of contraction

//sim params
const int nSims = 200; //how many runs

//initial Mt vector
vector<double> tubule (nFils, 0);

//length vector
vector<int> lengthMt (nFils, 1);

//function to make first level of the tubule
void initialMt(vector<double> &tubule)
{
    //set up random number generator
    chrono::high_resolution_clock::time_point tp =
                        chrono::high_resolution_clock::now();
    unsigned seed = static_cast<unsigned> (tp.time_since_epoch().count());
    //write seed to log
    clog << "random seed : " << seed << "\n";
    //create rng and assign seed
    rng.seed(seed);

    //initial Mt config
    for(int i = 0; i < nFils; ++i)
    {
        tubule[i] = dimerLength -  static_cast<double> (i) * offset;
    }

}

//function to choose a position and grow/shrink protofilament
void updateMt(vector<double> &tubule)
{
    vector<double> vecRates (nFils);
    //cout << "made vecrates vector" << endl;
    for(double t = 0.0; t < tMax;)
    {

        //get the current max length - the barrier is here
        double maxTubule = *max_element(tubule.begin(), tubule.end());
        //cout << "maxtubule length is " << maxTubule << endl;
        //a vector to hold the rates of addition of each Pf

        for(int j = 0; j < nFils; ++j)
        {   //cout << "getting attachment rates"<< endl;
            //get deltaX: how much the barrier would have to expand
            double diffBarrier = maxTubule - tubule[j];
            //cout << "diff barrier " << j << " is " << diffBarrier << endl;
            double deltaX = dimerLength - diffBarrier;
            //cout << "delta x" << j << " is " << deltaX << endl;
            double attach = deltaX > 0.0 ? kOn * exp(-(force * deltaX * 1e-9) / (kB * Temp)): kOn;
            //cout << "attachment rate " << j << "is " << attach << endl;
            vecRates[j] = attach;
            //cout << vecRates[j];

        }
        //choose a random event to occur -  the events are
        //the addition of dimers to any tubule, and the removal from any pf
        //make rates vector
        vecRates.push_back(kOff); // this is the detachment rate

        //get wait time to the next event
        double sum = 0.0;
        for(int i = 0; i < nEvents - 1; i++)
        {
            sum += vecRates[i];
        }
        //quit if the sum of rates < 0
        if(sum <= 0.0)
            cerr << "unable to draw wait time!\n";

        //draw a waitTime from an exponential distr
        exponential_distribution<double> waitTime(sum);
        const double dt = waitTime(rng); //decide time increment

        //randomly choose between dimer on (*13) or off
        discrete_distribution<int> drawEvent(vecRates.begin(),
                                             vecRates.end());
        const int event = drawEvent(rng);

        if(event < nFils - 1){
            ++tubule[event]; ++lengthMt[event];
        }
        else{
            //choose a random pf to reduce
            uniform_int_distribution<int> pfPicker(0, nFils - 1);
            int randPf = pfPicker(rng);
            --tubule[event]; --lengthMt[event];
        }

        t += dt; //increment timestep
        //delete vecrates
        vecRates.clear();

    }
}


//function to print microtubule
void printMt(const vector<double> &tubule)
{
    //print height of Pfs
    cout << "Pf locs = " << endl;
    for(int i = 0; i < nFils; ++i)
    {
        cout << tubule[i] << ", ";
    }
    cout << endl;

    //print distanc to barrier
    cout << "\nthe distance to barrier is\n\n";
    for(int i = 0; i < nFils; ++i)
    {
        cout << *max_element(tubule.begin(), tubule.end()) - tubule[i]
             << ", ";
    }
    cout << endl;

    //print the deltaX
    cout << "\nto accommodate another dimer, the barrier must move\n\n";
    for(int i = 0; i < nFils; ++i)
    {
        double diffBarrier = (*max_element(tubule.begin(), tubule.end()) - tubule[i]);
        cout << ((diffBarrier < dimerLength) ? diffBarrier - dimerLength : 0)
             << ", ";
    }
    cout << "\n\n";
}

//main function
int main()
{
    //open ofstream
    ofstream ofs("../data_p03_pratik.csv");
    //exit if not opened
    if(!ofs.is_open())
    {
        cerr << "could not open output stream...exiting...\n\n";
        exit(EXIT_FAILURE);
    }
    else
        cout << "output stream opened...\n\n";
    //write column names
    ofs << "sim, force, length_start, length_final, time_steps\n";
    for(double forceIt = 1.0e-12; forceIt < 12.0e-12; forceIt+=1.0e-12)
    {

        for(int sim = 0; sim < 10; sim++){
            cout << "force = " << force << ", iteration = " << sim << endl;
            ofs << sim << ", " << force << ",";
            //initialise the new microtubule
            initialMt(tubule);
            //cout << "intial tubule" << endl;
            //getLengthMt(tubule, lengthMt);
            ofs << *max_element(lengthMt.begin(), lengthMt.end()) * 8e-9 << ",";
            //run the Gillespie loop until tMax = 200
            updateMt(tubule);
            //getLengthMt(tubule, lengthMt);
            ofs << *max_element(lengthMt.begin(), lengthMt.end()) * 8e-9 << "," << tMax
                << endl;
        }
        force = forceIt;
    }

    cout << "\n\nsimulations run...\n"
         << "\nMove to R code to summarise and plot!\n"
         << endl;

    //close the ofstream
    ofs.close();
    return 0;
}
