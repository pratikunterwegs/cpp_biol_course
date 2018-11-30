#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <cmath>

using namespace std;

//*** parameters of the integration algorithm

const int nvar = 2; //number of variables
const double tEnd = 1.0; //simulation time
double dt = 1e-5; //step size
const double dtsav = 1.0;
const double b = 1e3;
const double epsilon = 4.0;


void rhs(const double &t, const vector<double> &x, vector<double> &dxdt)
//definition of the right hand side of the ode model
//t is the current time
//vector x contains the current values of the vars
//vector dxdt is filled with the values of the drivs dsx/dt
{
    //double aux = a * x[1] * x[0]; //auxiliary part of the equation

    dxdt[0] = x[1]; //dxdt  = y(t)
    dxdt[1] = (-epsilon * x[1]) + (-b * x[0]); //dydt = some formula
}

//***ODE integration routine by euler method
void eulerStepper(double &t, vector<double> &x, const double &h)
{
    //compute gradient
    vector<double> dxdt(nvar);
    rhs(t, x, dxdt);

    //advance solution
    for(int i = 0; i < nvar; ++i)
        x[i] += h * dxdt[i];
    // here, h is dt passed to the function
    t += h;
}

//*** ODE integration by runge-kutta method
void rungeKuttaStepper(double &t, vector<double> &x, const double &h){
    //step 1
    vector<double> dxdt1(nvar);
    rhs(t, x, dxdt1);

    //step 2
    vector<double> xtmp(nvar);
    for(int i = 0; i < nvar; ++i)
        xtmp[i] = x[i] + 0.5 * h * dxdt1[i];
    vector<double> dxdt2(nvar);
    rhs(t + 0.5 * h, xtmp, dxdt2);

    //step 3
    for(int i = 0; i < nvar; ++i)
        xtmp[i] = x[i] + 0.5 * h * dxdt2[i];
    vector<double> dxdt3(nvar);
    rhs(t + 0.5 * h, xtmp, dxdt3);

    //step 4
    for(int i = 0; i < nvar; ++i)
        xtmp[i] = x[i] + h * dxdt3[i];
    vector<double> dxdt4(nvar);
    rhs(t + h, xtmp, dxdt4);

    //advance solution
    for(int i = 0; i < nvar; ++i)
        x[i] += h * (dxdt1[i] + 2.0 * dxdt2[i] + 2.0 * dxdt3[i] + dxdt4[i]) /6.0;
    t += h;
}



//***main function

int main()
{
    try{

        //set initial conditions
        vector<double> x(nvar, 0);

        //hard-code start conditions
        x = {1.0, 0.0};

        //get omega
        double omega = sqrt(b - (epsilon * epsilon)/4);
        //get true solution
        double trueSolution = (exp(-epsilon / 2 * tEnd)) * (cos(omega * tEnd) + ((epsilon / (2 * omega)) * sin(omega * tEnd)));

        //start numerical integration
        for(double t = 0.0, tsav = 0.0; t < tEnd;) {
            eulerStepper(t, x, dt);

            if(t > tsav) {
                cout << t << ", " << x[0] << ", " << x[1] << " " << trueSolution << "\n";
                //ofs << t << ", " << x[0] << ", " << x[1] << "\n";
                tsav += dtsav;
            }
        }
    }
    catch(exception &error){
        cerr << "error: " << error.what();
        exit(EXIT_FAILURE);
    }
    return 0;
}
