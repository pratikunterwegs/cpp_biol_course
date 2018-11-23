#include <iostream>
#include <fstream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //open file
    ifstream ifs("../patientData.txt");
    if(!ifs.is_open()){
        cerr << "error: unable to open file\n";
        exit(EXIT_FAILURE);
    }

    //read data from file
    vector<pair<string, double> > patientRecords;
    for(;;){
        string patientID;
        ifs >> patientID;

        if(ifs.fail())
            break;

        double dBP;
        ifs >> dBP;

        pair<string, double> record(patientID, dBP);
        patientRecords.push_back(record);
    }

    //show on screen
    for(int i = 0; i < patientRecords.size(); ++i)
        cout << "patient " << patientRecords[i].first
             << " has BP " << patientRecords[i].second
             << endl;
    return 0;
}

