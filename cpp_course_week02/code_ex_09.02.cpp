#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    //ask for filename as a string
    cout << "enter the full path of a file to read in: \n"
         << "eg. /home/pratik/git/cpp_biol_course/filename.filetype"
         << endl;
    string filename;
    //get user filename
    cin >> filename;

    //open user file
    ifstream ifs(filename.c_str());
    //error if file not opened
    if(!ifs.is_open()){
        cerr << "error: file not found blah blah\n";
        exit(EXIT_FAILURE);
    }
    //print to confirm open
    else {
        cout << "file opened\n";
    }

    //read the input vals
    //create vec to store
    vector<double> vec;

    //run loop to read
    for(int i = 0;;){
        double x; //temp container
        ifs >> x;
        //read data only if found not fail ie double
        if(!ifs.fail()){
            vec[i] = x; //add value to vector
            ++i; //increment counter here rather than end
        }
        //clear error and ignore next char
        else{
            ifs.clear(); ifs.ignore();
            vec[i] = -999;
        }

        //terminate if end of file
        if(ifs.eof())
            break;
    }

    //ifs.close(); //close file after loop terminates, ideally after 20 vals

    cout << "the file had the values --- missing values are -999 \n";
    //print to screen
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ", ";
    cout << endl;
    return 0;
}
