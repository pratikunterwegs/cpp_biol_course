#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    //open file
    ifstream ifs("/home/pratik/git/cpp_biol_course/measurements.txt");

    if(!ifs.is_open()){
        cerr << "error: file not found blah blah\n";
        exit(EXIT_FAILURE);
    }/*
    else {
        cout << "file opened\n";
    }*/

    //read the input vals
    //create vec to store
    vector<double> vec(20);

    //run loop to read
    for(int i = 0;;){
        double x; //temp container
        ifs >> x;
        vec[i] = x; //add value to vector
        cout << "value read\n";
        //increment counter
        ++i;

        if(ifs.eof()){
            break;
        }
    }

    //ifs.close(); //close file after loop terminates, ideally after 20 vals

    cout << "the file had the values --- \n";
    //print to screen
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ", ";
    cout << endl;
    return 0;
}
