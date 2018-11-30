#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <random>
#include <chrono>

using namespace std;

//**model parameters
const int nEvents = 3; //3 cases
const double rateBirth = 2.0;
const double rateDeath = 1.0;
const double rateCompt = 0.001;
const double tMax = 50.0;
const double dtSav = 1.0;

//**simulation

int main()
{
    //run through try to catch exceptions
    try{
        //open ofstream
        ofstream ofs("../data_code_ex_14.03.csv");
        //check if opne
        if(!ofs.is_open())
            throw runtime_error("unable to open file, error...\n");

        //write column name
        ofs << "time, popsize, sim\n";

        for(int sim = 1; sim < 11;){
            //get randnumber seed
            chrono::high_resolution_clock::time_point tp =
                    chrono::high_resolution_clock::now();
            unsigned seed = static_cast<unsigned> (tp.time_since_epoch().count());
            //write seed to log
            clog << "random seed : " << seed << "\n";
            //create rng and assign seed
            mt19937_64 rng; rng.seed(seed);

            //initialise the population
            int nA = 5;

            //sim loop
            for(double t = 0.0, tSav = 0.0; t < tMax;){
                //no density dependence here
                //in the code listing, sim ends when all patches are occupied

                //calc rates for events in a doubles vector; one entry per event
                vector<double> vecRates(nEvents);
                //explicitly state the rates, but with small numbers of processes
                //could also be coded directly. not advised but anyway
                vecRates[0] = rateBirth * nA;
                vecRates[1] = rateDeath * nA;
                vecRates[2] = rateCompt * nA * nA;

                //get wait time to next event
                double sum = 0.0;
                for(int i = 0; i < nEvents; ++i){
                    sum += vecRates[i];
                }
                //sum the rates and if 0 or less quit with error
                if(sum <= 0.0)
                    throw runtime_error("unable to draw wait time, rate sum < 0\n");

                //draw a random number from an exponential distribution
                exponential_distribution<double> waitTime(sum);
                const double dt = waitTime(rng);

                //sample the next event
                discrete_distribution<int> drawEvent(vecRates.begin(), vecRates.end());
                const int event = drawEvent(rng);

                //update population
                t += dt;
                switch (event) {
                case 0: ++nA; break; // birth event
                case 1: --nA; break; // death due to external cause
                case 2: --nA; break; // death from competition
                default: throw logic_error("unknown event occurred!"); //no break
                }

                //write output
                if(t > tSav){
                    ofs << t << "," << nA << "," << sim << "\n";
                    //write to screen
                    //cout << t << "," << nA << "\n";
                    //increment tsav
                    tSav += dtSav;
                }

        }
            ++sim;
    }
  }
    //handle errors thrown above
    catch(exception &error){
        cerr << error.what();
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
