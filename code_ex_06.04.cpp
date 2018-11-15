/* removing duplicates from a vector */

#include <iostream>
//#include <cmath>
#include <vector>

using namespace std;

double removeDup (vector<double> &vec){

    double dMax = vec[0];
    for(int i = 0; i < vec.size(); ++i){

        if(vec[i] > dMax)
            dMax = vec[i];
    }
    return dMax;
}

int main(){

    //create two vectors of the same size, one empty as a holder
    vector<double> vec {2,3,4,3,4,1,1e10};
    //vector<double> anotherVec(vec.size());

    double dMax = removeDup(vec);


    cout << "Largest value is: " << dMax
         << endl;

}
