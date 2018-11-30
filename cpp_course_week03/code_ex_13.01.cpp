#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <cstdlib>

using namespace std;

//*** parameters of the integration algorithm

const int nvar = 2; //number of variables
const double tEnd = 200.0; //simulation time
const double dt = 0.05; //step size
const double dtsav = 0.5;


//***model spec

const double r = 2.0; //max exponential growth rate of prey
const double K = 0.32; //carrying capacity of prey
const double a = 1.0; //predator attack rate
const double H = 0.1; //half-saturation constant of predator function response
const double c = 0.2; //#predator produced per consumed prey
const double d = 0.1; //death rate of the predator


void rhs(const double &t, const vector<double> &x, vector<double> &dxdt)
//definition of the right hand side of the ode model
//t is the current time
//vector x contains the current values of the vars
//vector dxdt is filled with the values of the drivs dsx/dt
{
    double aux = a * x[1] * x[0]; //consumption fo prey by predator

    dxdt[0] = r * x[0] - aux; //prey equation
    dxdt[1] = c * aux - d * x[1]; //predator equation
}

//***ODE integration routine by euler method
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
        //open data file
        ofstream ofs("../data_code_ex_13.01_rungekutta_method.csv");
        if(!ofs.is_open())
            throw runtime_error("unable to open file.\n");

        //set initial conditions
        vector<double> x(nvar, 0.05);

        //hard-code start conditions
        x = {0.4, 2.0};

        //always output column names!!!
        ofs << "time, prey, predator\n";


        //start numerical integration
        for(double t = 0.0, tsav = 0.0; t < tEnd;) {
            rungeKuttaStepper(t, x, dt);

            if(t > tsav) {
                cout << t << ", " << x[0] << ", " << x[1] << "\n";
                ofs << t << ", " << x[0] << ", " << x[1] << "\n";
                tsav += dtsav;
            }
        }
        ofs.close();
    }
    catch(exception &error){
        cerr << "error: " << error.what();
        exit(EXIT_FAILURE);
    }
    return 0;
}
