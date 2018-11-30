///*abandoned due to being annoying and having poor logical flow */

//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <cmath>

//using namespace std;

////declare parameters
//const int nvar = 2; //two variables, one for protein, one mRNA
//const double dt = 0.01; //set arbit increment size
//double a; //assign the value of a later from 0.2 to 1.2
//double b = 0.5; //assign a value of the constant b

////function to update the 2 element vector of protein and mRNA
//void rhs(const double &t, const vector<double> &x, vector<double> &dxdt){

//    //change protein concentration or derivative of it or something
//    dxdt[0] = -a * x[0] + x[1];
//    //change mRNA concentration
//    dxdt[1] = pow(x[0], 2)/(1 + pow(x[0], 2)) - (b * x[1]);
//}

////euler stepper
//void eulerStepper(double &t, vector<double> &x, const double &h)
//{
//    //compute gradient
//    vector<double> dxdt(nvar);
//    rhs(t, x, dxdt);

//    //advance solution
//    for(int i = 0; i < nvar; ++i)
//        x[i] += h * dxdt[i];
//    //here, h is dt passed to the function
//    t += h;
//}

//// main function. here, while the values of protein and mrna fluctuate, run the
//// next step. otherwise, stop. take y0, the initial mrna concentration as
//// a user input.

//int main()
//{
//    //ask for initial mRNA
//    cout << "enter initial mRNA concentration: \n";
//    double startMRNA;
//    cin >> startMRNA;


//    return 0;
//}
