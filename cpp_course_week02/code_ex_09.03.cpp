/*program to read in values from a file
 * and replace them with some transformation
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

//define a function to read in values from a user defined file
vector<double> readVals(string filename){
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
    //read the input vals, create vec to store
    vector<double> vec;

    cout << "empty vector made\n";

    //run loop to read
    for(int i = 0;;){
        cout << "vector pos " << i << "...\n";
        double x; //temp container
        ifs >> x;
        //read data only if found not fail ie double
        if(!ifs.fail()){
            ++i; //increment counter
            vec.push_back(x); //add value to vector
        cout << "assigned value " << i << "...\n";

        }
        //clear error and ignore next char
        else{
            ifs.clear(); ifs.ignore();
            //vec.push_back(-999.0);
            cout << "vector pos " << i << "failed, skipping\n";
        }

        //terminate if end of file
        if(ifs.eof()){
            cout << "end of file reached\n";
            break;
        }
    }
    cout << "file read and NAs replaced by  -999\n";

//    //remove -999 or missing vals from vec
//    for(int j = 0; j < vec.size();++j){
//        if(vec[j] == -999){
//            vec.erase(vec.begin()+j);
//            --j;
//        }
//    }

    //return vec
    return vec;
}

//function to scale values
void valScale(vector<double> &vec){

    //get min and max
    double minVec = *min_element(vec.begin(), vec.end());
    double maxVec = *max_element(vec.begin(), vec.end());

    //transform
    for(int i = 0; i < vec.size(); ++i){
        vec[i] = (vec[i] - minVec)/(maxVec - minVec);
    }
}

//function to write to file
void writeVals(vector<double> &vec){
    //open output stream
    ofstream ofs("/home/pratik/git/cpp_biol_course/fileOut.txt");

    if(!ofs.is_open()){
        cerr << "could not open output file, error\n";
        exit(EXIT_FAILURE);
    }
    else
        cout << "out file opened\n";

    for(int i = 0; i < vec.size(); ++i){
        ofs << vec[i] << ", ";
    }
    cout << endl;
    //close the output stream
    ofs.close();
}

//main function
int main()
{
    //ask for filename as a string
    cout << "enter the full path of a file to read in: \n"
         << "eg. /home/pratik/git/cpp_biol_course/filename.filetype"
         << endl;
    string filename;
    //get user filename
    cin >> filename;
    //apply readin func to filenames
    vector<double> vec = readVals(filename);

    cout << "the file had the values ... missing values are removed";
    //print input to screen
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ", ";
    cout << endl;

    //scale values
    valScale(vec);

    //write to file
    writeVals(vec);

    return 0;
}
