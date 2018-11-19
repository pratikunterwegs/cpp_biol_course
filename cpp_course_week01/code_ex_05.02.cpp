/*program for the ricker model
    ricker modl population size nt = nt-1 * e^(1-nt-1)
    for r = -0.05, 0.5, 2.0, 2.5, 3.0;
    n0 = 0.001;
    tmax = 100;
    store pops n0...n100 in a vector
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //create constant timesteps tmax
    const int iTmax = 100;
    //create vector using some non-standard method; see included library
    vector<double> vecR{-0.05, 0.5, 2.0, 2.5, 3.0};

    //check to see if vector creation is good
    {
        cout << "The intrinsic growth rates are: ";
    for(int i = 0; i < vecR.size(); ++i){
       cout <<  vecR[i] << ", ";
        }
    cout << "" << endl;
    }

    //run the ricker model for each growth rate
    {
        for(int i = 0; i < 5; ++i){

            //create vector of pop size of a fixed size and assign start pop size 0.001
            vector<double> vecPopsize(100);
            vecPopsize[0] = 0.001;
            for(int j = 1; j < iTmax; ++j){
                vecPopsize[j] = vecPopsize[j-1]*(exp(vecR[i]*(1.0-vecPopsize[j-1])));

            }
            cout << "The growth rate is " << vecR[i] << " and the pop size is ";
            for (double x : vecPopsize){
                  cout << x << " ";}
            cout << endl;
        }
    }

    return 0;
}
