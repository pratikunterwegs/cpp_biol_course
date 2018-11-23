/* a program for arterial branching */

#include <iostream>
#include <string>
#include <algorithm>
#include <boost/algorithm/string/replace.hpp> //using boost
#include <fstream>
#include <cmath>

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
    int n;
};

//write a turtleplot function
void turtlePlot(const string &symbol, turtle &myTurtle,
                turtle &memoryTurtle, double &turnAngle){
    //calculate turnAngle/360
    double turnAngleCirc = 2 * pi * (turnAngle/360.0);

    //initialise the turtles with x, y, alpha, and iteration
    memoryTurtle = myTurtle = {0, 0, 0, 0};

    //say where turtle starts
    cout << "step 0: this is your turtle standing by at 0,0...\n";
    cout << "the command sequence is "
         << symbol << endl;

    //run through loop of length symbol.length()
    for(int i = 0; i < symbol.length(); ++i){

        //set turtle iterator
        myTurtle.n = i;
        //output symbol read
        cout << "received " << symbol[i] << ": \n";
        //operate switch on instruction at symbol[i]
        switch (symbol[i]) {
        case 'A': case 'B':
            //get the next coordinate
            myTurtle.x += cos(myTurtle.alpha);
            myTurtle.y += sin(myTurtle.alpha);
            //output new position
            cout << "step " << i+1 << "...turtle moved to "
                 << myTurtle.x << "," << myTurtle.y
                 << endl;
            break;
        //if case L, save turtle position as the other turtle and turn L
            //here, set alpha, the turn angle, to
            // 2*pi*(40/360)
        case 'L':
            memoryTurtle = myTurtle;
            cout << "turtle saved position at step " << i << endl;
            myTurtle.alpha += turnAngleCirc;
            cout << "step " << i+1
                 << " turtle turned " << turnAngle << "° left\n";
            break;
        //restore previous turtle and change turning angle to R
        case 'R':
            myTurtle = memoryTurtle;
            cout << "step " << i+1
                 << " turtle restored position and heading to step "
                 << memoryTurtle.n << endl;
            myTurtle.alpha -= turnAngleCirc;
            cout << "step " << i+1 << " turtle turned " << turnAngle
                 << "° right\n";
            //then set alpha to
            break;
        default: cerr << "unrecognised command, turtle quits.\n\n";
            exit(EXIT_FAILURE);
        }
        //open output stream and write turtle position, command, iteration
        //warning, this ofstream appends to a pre-existing file!
         ofstream ofs("../data_turtle_pos_p01_pratik.csv",
                      ofstream::out | ofstream::app);
         //check if not open, then produce error
         if(!ofs.is_open()){
             cerr << "output stream for turtle positions could not be opend"
                  << endl;
             exit(EXIT_FAILURE);
         }
         else {
             if(i ==0){
                 //write column names, hardcode start
                 ofs << "x,y,angle,step,command" << endl;
                 ofs << "0,0,0,0,NA" << endl;
             }
             //write positions
             ofs << myTurtle.x << "," << myTurtle.y << ","
                 << myTurtle.alpha << ","
                 << i+1 << "," << symbol[i] << endl;
         }
         //close ofstream
         ofs.close();
    cout << endl;
    }

}

//main function

int main()
{
    //define start sequence "A"
    string symbol ("A");
    //define turning angle; sparse trees likely result from smaller angles
    double turnAngle = 40.0;
    //generate sequences
    generateSequence(symbol, 6);
    //make turtles
    turtle myTurtle, memoryTurtle;
    //plot turtle positions
    turtlePlot(symbol, myTurtle, memoryTurtle, turnAngle);
    return 0;
}

