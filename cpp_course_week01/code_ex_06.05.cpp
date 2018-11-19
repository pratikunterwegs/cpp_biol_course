/* removing duplicates from a vector */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> removeDup(vector<double> &vec){

    sort( vec.begin(), vec.end() );
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() );

    return vec;
}

int main()
{

    vector<double> vec {1e3,2,3,4,5,6,4,3,1};

    vector<double> anotherVec = removeDup(vec);

    for(int i = 0; i < anotherVec.size(); ++i)
        cout << anotherVec[i] << " " <<
     endl;

    return 0;
}
