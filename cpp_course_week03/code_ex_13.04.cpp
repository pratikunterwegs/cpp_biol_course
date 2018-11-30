/* a program for action potentials */

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

//declare parameters
const int nvar = 4; //three variables, m, h, n and V
const double dt = 0.01; //set increment size
const double tMax = 150.0; //set maximum run size
const double pi = 3.14159;

//function to update the m, h, n, and V
void rhs(const double &t, const vector<double> &x, vector<double> &dxdt){

    //define stimulus
    double stimulus = //10.0 * (1 - cos(2.0 * pi * t / 150.0));
    t > 50.0 && t < 100.0 ? 10.0 : 0.0;
    const double m = x[0]; const double h = x[1]; const double n = x[2];
    const double V = x[3];

    //for V
    dxdt[3] = -(120.0 * pow(m, 3) * h * (V + 115.0) +
            (36.0 * pow(n, 4) * (V - 12.0)) +
            (0.3 * (V + 10.5989)) +
            stimulus);

    //for m
    dxdt[0] = 0.1 * (1.0 - m) * (V + 25.0) / (exp((0.1 * V) + 2.5) - 1.0) -
            (4.0 * m * exp(V / 18.0));
    //for h
    dxdt[1] = (0.07 * (1.0 - h) * exp(V / 20.0)) -
            (h / (exp((0.1 * V) + 3.0) + 1.0));
    //for n
    dxdt[2] = (0.01 * (1.0 - n) * (V + 10.0)) / (exp(0.1 * V + 1.0) - 1.0) -
            (0.125 * n * exp(V / 80.0));

}

//runge kutta integration function
void eulerStepper(double &t, vector<double> &x, const double &h)
{
    //compute gradient
    vector<double> dxdt(nvar);
    rhs(t, x, dxdt);

    //advance solution
    for(int i = 0; i < nvar; ++i)
        x[i] +=h * dxdt[i];
    t += h;
}

// main

int main()
{
    //set initial conditions
    vector<double> x{0.05, 0.59, 0.32, 0.0}; //set initial values of m, h, n and V

    //open ofstream
    ofstream ofs ("../data_code_ex_13.04_step_stimulus.csv");
    if(!ofs.is_open()){
        cerr << "could not open output\n";
        exit(EXIT_FAILURE);
    }
    else
        cout << "output opened...\n";

    //print column headings to ofstream
        ofs << "time, m, h, n, V\n";

    //start integration and write to file
    for(double t = 0.0, tsav = 0.025; t < tMax;){
        eulerStepper(t, x, dt);

        //print values at 1.0 ms timesteps
        if(t > tsav){
            cout << t << "," << x[0] << "," << x[1] << "," << x[2] << ","
                 << x[3] << endl;
            ofs << t << "," << x[0] << "," << x[1] << "," << x[2] << ","
                << x[3] << endl;
        }
    }
   return 0;
}
