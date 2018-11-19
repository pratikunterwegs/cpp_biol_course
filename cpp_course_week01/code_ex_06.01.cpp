/* program for the ricker model but with a function
 * for pop size at t given pop size at t-1
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//define the function to return pop at time t
double computeNextPopulationDensity(double N, const double r){

    double popNt = N * (exp(r*(1-N)));
    return popNt;
}

//define main function
int main(){

    //get input
    cout << "Enter population at time t-1 and the intrinsic growth rate. \n";
    double N; double r;
    cin >> N >> r;

    //run function and output
    cout << "Pop size at time t was "
         << N << " and became "
         << computeNextPopulationDensity(N, r)
         << " with a growth rate of "
         << r
         << ".\n";

    return 0;
}
