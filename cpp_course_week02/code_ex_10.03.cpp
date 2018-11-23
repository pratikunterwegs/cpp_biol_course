#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //read in values from file
    ifstream ifs("../phonedirectory.txt");
    if(!ifs.is_open()){
        cerr << "error: directory not opened\n";
        exit(EXIT_FAILURE);
    }
    //print if open
    else{
        cout << "directory opened\n";
    }

    //define structure
    struct phoneDir
    {
        string strName; int iNumber;
    };

    // read data to the directory
    vector<phoneDir> PGCPPPHD;
    for(;;){
        string strPerson;
        ifs >> strPerson;

        if(ifs.fail()) break;

        int iExtension;
        ifs >> iExtension;

        phoneDir record = {strPerson, iExtension};
        PGCPPPHD.push_back(record);
    }
    cout << "directory loaded..." << endl;

    //ask user for a name
    cout << "Welcome to the PGCPPPHD; enter a name to get an extension\n";
    string strLookup;
    cin >> strLookup;

    //loop through PGCPPPHD.strName looking for a match
    for(int i = 0; i < PGCPPPHD.size() - 1; ++i){
        if(strLookup == PGCPPPHD[i].strName){
            cout << PGCPPPHD[i].strName << " can be reached at "
                 << PGCPPPHD[i].iNumber << endl;
            break;
        }
        //output not found if not found
        else //(i == PGCPPPHD.size()){
            cout << strLookup << " could not be found.\n";
        //}
    }

    return 0;
}
