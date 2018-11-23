#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//define the function for which to find roots
//this program only hands mnotonic functions
double f(double x){
    return x*x - 2;
}

//define the findroot function
double findRoot(double a, double b, int iterations){
    //define step for increments
    const double epsilon = 1.0e-6;

    //evaluate the function at a and b and check if f(a) and f(b) have the same sign;
    double fa = f(a); double fb = f(b);

    //check for sign equivalence
    if(fa * fb > 0) {
        cerr << "unable to locate root between bracket points\n";
        exit(EXIT_FAILURE);
    }
    else {
        //check if the function is a decreasing one, if so swap
        if(fa > 0.0) swap(a, b);
        //as long as abs(a-b) is less than the min value to increment
        int i = 1;
        while(fabs(a - b) > epsilon && i <= iterations){
            ++i;
            if(i == iterations){
                cerr << "not found after " << iterations << " tries\n";
                exit(EXIT_FAILURE);
            }
            //find the midpoint
            double c = 0.5 * (a + b);

            //find func value at midpoint
            double fc = f(c);

            //cout << c << " " << fc << "\n";

            //update bracket points
            if(fc <= 0.0)
                a = c;
            else
                b = c;

        }

    }
    return 0.5 * (a + b);
}

int main(int argc, char *argv[])
{
    cout << "the root of f(x) is " << findRoot(0, -3.0, 7) << '\n';
    return 0;
}
