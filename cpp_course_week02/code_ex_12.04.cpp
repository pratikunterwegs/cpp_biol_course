/* a program for the breeder's equation */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <cmath>

using namespace std;

//write a function to initialise the matrix as per code listing 12.04
void initialiseMatrixG(vector<vector<double> > &matrixG)
// initialises the transition matrix
{
    // create a matrix of size 4 and initialise with 0.0
    const int iA = 2; // number of rows and cols
    matrixG = vector<vector<double> >(iA, vector<double>(iA, 0.0));

    //set the matrix values with variances (0,0 and 1,1) and covariance (others)
    //initial values are vt = vp = 0.1 and cpt = 0.02;
    matrixG[0][0] = matrixG[1][1] = 0.1;
    matrixG[0][1] = matrixG[1][0] = 0.06;

    //constrain covariance to be less than root of variance product
    if(abs(matrixG[0][1]) > sqrt(matrixG[0][0] * matrixG[1][1]))
        cerr << "covariance must be less than sqrt(vt * vp)!, exiting\n";

    //print matrix
    cout << "initialised genetic var-covar matrix: \n" << endl;

    for(int i = 0; i < iA; ++i){
        for(int j = 0; j < iA; ++j){
            cout << matrixG[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//create a struct to hold trait values
struct traits
{
    double p, t;
};

//create a struct for selection gradient
struct selectionGrad
{
    double betaT, betaP;
};

//set inital trait values by reference to a custom traits strcuture
void initialTrait(traits &vecTraits){

    vecTraits.t = 0;
    vecTraits.p = 0.05;

}

//function to iterate the model
//takes as args the genetic variance-covariance matrix
void selectionGradient(selectionGrad &Beta, traits &vecTraits){

    //set the more or less global (hence static) ct and cp values
    static double cT = 0.5; static double cP = 0.02;
    //compute selection gradient vector at one timestep
        Beta.betaT = vecTraits.p - cT * vecTraits.t;
        Beta.betaP = vecTraits.p * -cP;
}

//function for vector - matrix multiplication
traits nextTraits(selectionGrad &Beta,
                                 const vector<vector<double> > &matrixG,
                  traits &vecTraits){

    //output is a 2 element float struct of type traits
    traits vecNextTraits;
    vecNextTraits.t = vecTraits.t + ((Beta.betaT * matrixG[0][0]) + (Beta.betaT * matrixG[0][1]));
    vecNextTraits.p = vecTraits.p + ((Beta.betaP * matrixG[1][0]) + (Beta.betaP * matrixG[1][1]));

    //also change vecTraits
    vecTraits.t = vecNextTraits.t; vecTraits.p = vecNextTraits.p;

    return vecNextTraits;
}

int main(int argc, char *argv[])
{
    //test run 01 for initial step
    vector<vector<double> > matrixG;
    initialiseMatrixG(matrixG);

    //initialise trait values and print
    traits vecTraits;
    initialTrait(vecTraits);

    cout << "initial trait values p and t are " << vecTraits.p << " and " << vecTraits.t
         << endl << endl;

    //get the first selection gradient vector
    selectionGrad Beta;
    selectionGradient(Beta, vecTraits);

    cout << "initial selection grad ßp and ßt is \n"
         << Beta.betaP << " and " << Beta.betaT << endl << endl;

    //make a vector of trait values of length 1e3
    vector<traits> modelValues (1e3);

    //update trait values
    for(int iterator = 0; iterator < modelValues.size(); ++iterator){
        //assign to ith element the results of nextTraits
        modelValues[iterator] = nextTraits(Beta, matrixG, vecTraits);
    }

    //write data
    ofstream ofs("../data_ex_12.04_covariance" + to_string(matrixG[0][1]) + ".csv");
    //check if ostream opens the file
    if(!ofs.is_open()){
        cerr << "couldn't open output filepath, check code!\n";
        exit(EXIT_FAILURE);
    }
    else
        cout << "output file opened, writing\n";

    cout << "trait values over time are: \n";
    //output new trait values
    for(int i = 0; i < 1000; ++i){
        //print to screen
        cout << "p = " << modelValues[i].p << " "
             << "t = " << modelValues[i].t << "\n";
        //print to file
        if(i == 0)
            ofs << "preference" << "," << "trait" << "," << "time" << endl;
        ofs << modelValues[i].p << "," << modelValues[i].t << "," << i+1 << endl;
    }

    cout << "values written to file, closing output stream" << endl;
    //close output stream
    ofs.close();

    return 0;
}
