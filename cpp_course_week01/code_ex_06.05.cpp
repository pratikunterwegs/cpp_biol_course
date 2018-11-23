/* removing duplicates from a vector */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//more comments!
void removeDup(vector<double> &vec){

    sort( vec.begin(), vec.end() );
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
}

int main()
{

    vector<double> vec {1e3,2,3,4,5,6,4,3,1,1,1,1,1};

    removeDup(vec);

    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " " <<
     endl;

    return 0;
}
