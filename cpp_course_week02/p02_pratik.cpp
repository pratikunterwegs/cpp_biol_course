/* a program for arterial branching */

#include <iostream>
#include <string>
#include <algorithm>
#include <boost/algorithm/string/replace.hpp> //using boost
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

//a rough approximation of pi
const double pi = 3.142;

//define function to replace A with BLARA
void generateSequence(string &symbol, int n){

    //open output stream to write sequence, seq length, and i to csv
    ofstream ofs("../data_blara_seq_p02_pratik.csv");

    if(!ofs.is_open()){
        cerr << "output stream failed to open, exiting here" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        cout << "opened output stream successfully" << endl;
    }

    //set a check to default yes
    char sureRun = 'y';

    //iterate through n runs, where n mostly less than 6
    //warn user that n runs is too high
    if(n > 6){
        cout << "you have asked for " << n << " iterations of control sequence generation...\n \ndo you want to continue with this value of runs?\n"
             << "enter Y/y or N/n for yes or no..."
             << endl;
        cin >> sureRun;
    }
    else {
        cout << "You asked for " << n << " iterations of control seq generation.\n";
    }

    switch (sureRun) {
    case 'Y': case 'y':
        cout << "you chose to continue with "
             << n << " control seq generation runs\n"
             << "on your head be it!\n";

                //iterate through 0 -  n
                for(int i = 0; i <= n; ++i){

                    //optional step to write column names in csv
                    if(i == 0){
                        ofs << "i," << "seq_length," << "seq\n";
                    }
                    else{
                        //replace A with BLARA
                        boost::replace_all(symbol, "A", "BLARA");
                    }
                    //write output to file, first row will be 0, A, 1
                    ofs << i << ","
                        << symbol << ","
                        << symbol.length() << endl;
                    cout << "written seq S" << i << "...\n";
        }
        cout << "all " << n << " sequences written to csv\n\n";
        break;
    case 'N': case 'n':
        cout << "you've thought better of your actions, fair enough. exiting.\n";
        exit(EXIT_SUCCESS);
    }
    //close ofs manually
    ofs.close();

}

//make a turtle structure
struct turtle
{
    double x, y, alpha;
    int n, bifurcations;
};

//write a turtleplot function
void turtlePlot(const string &symbol, turtle &myTurtle, double &turnAngle, vector<turtle> &memoryTurtle){
    //calculate turnAngle/360
    double turnAngleCirc = 2 * pi * (turnAngle/360.0);

    //initialise the turtle with x, y, alpha, and iteration
    myTurtle = {0.0, 0.0, 0.0, 0, 0};
    //set memory turtle
    memoryTurtle.push_back(myTurtle);

    //say where turtle starts
    cout << "step 0: this is your turtle standing by at 0,0...\n";
    cout << "the command sequence is "
         << symbol << endl;

    //open an ofstream
    ofstream ofs("../data_turtle_pos_p02_pratik.csv");
    //run through loop of length symbol.length()
    for(int i = 0; i < symbol.length(); ++i){

        //define command
        char command = symbol[i];

        //here, write the turtle pos to file
        //this is the start point of the segment
        //
        //check if not open, then produce error
         if(!ofs.is_open()){
             cerr << "output stream for turtle positions could not be opend"
                  << endl;
             exit(EXIT_FAILURE);
         }
         //if open write the initial position to file
         else{
             if(i == 0)
                 ofs << "x,y,angle,step,command\n";
             //write position
             ofs << myTurtle.x << "," << myTurtle.y << ","
                 << myTurtle.alpha << ","
                 << i << "," << command << endl;
         }

        //set turtle iterator
        myTurtle.n = i;
        //output symbol read
        cout << "received " << command << ": \n";
        //operate switch on instruction at symbol[i]
        switch (symbol[i]) {
        case 'A': case 'B':

            //get the next coordinate implementing 20% reduction
            myTurtle.x += cos(myTurtle.alpha) *
                    pow(0.8, myTurtle.bifurcations);
            myTurtle.y += sin(myTurtle.alpha) *
                    pow(0.8, myTurtle.bifurcations);

            //output new position
            cout << "step " << i+1 << "...turtle moved to "
                 << myTurtle.x << "," << myTurtle.y
                 << endl;
            break;

        //save pos and turn left
        case 'L':
            //save current position
            memoryTurtle.push_back(myTurtle);
            cout << "turtle saved position at step " << i << endl;
            //turn left
            myTurtle.alpha += turnAngleCirc;

            //increase bifurcation count
            ++ myTurtle.bifurcations;
            cout << "step " << i+1
                 << " turtle turned " << turnAngle << "° left\n";
            break;

        //restore previous turtle and turn right
        case 'R':
            //restore most recent position
            myTurtle = memoryTurtle.back();
            //forget most recent saved pos
            memoryTurtle.pop_back();
            cout << "step " << i+1
                 << " turtle restored position and heading to step "
                 << myTurtle.n << endl;
            //reduce bifurcation count
            ++ myTurtle.bifurcations;
            //turn right
            myTurtle.alpha -= turnAngleCirc;
            cout << "step " << i+1 << " turtle turned " << turnAngle
                 << "° right\n";
            //then set alpha to
            break;
        default: cerr << "unrecognised command, turtle quits.\n\n";
            exit(EXIT_FAILURE);
        }
            //the ofstream is still open!
            //write positions
            ofs << myTurtle.x << "," << myTurtle.y << ","
                 << myTurtle.alpha << ","
                 << i << "," << command << endl;
       }
       //close ofstream after loop
       cout << "written to file...\n" << endl;
       ofs.close();
    cout << endl;
}

//main function

int main()
{
    //define start sequence "A"
    string symbol ("A");
    //define turning angle; sparse trees likely result from smaller angles
    double turnAngle = 40.0;
    //generate sequences
    generateSequence(symbol, 7);
    //make turtle
    turtle myTurtle;
    //create a memory turtle, a vector of positions to hold saved vals
    vector<turtle> memoryTurtle;
    //plot turtle positions
    turtlePlot(symbol, myTurtle, turnAngle, memoryTurtle);
    return 0;
}

