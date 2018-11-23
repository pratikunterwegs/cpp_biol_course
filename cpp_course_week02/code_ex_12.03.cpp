/* This program iterates a Leslie matrix population
model and computes the stable age distribution
and the long−term geometric growth rate of the
population .

By adjusting the specification of the transition
matrix in the function initialise () , the same
code can be used to find the leading eigenvalue
and corresponding eigenvector for any kind of
linear discrete −time model

x_{t+1} = M x_{t}

for any kind of transition matrix M
Written on 14−11−2016 by Master Yoda. */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <exception>

//*** iteration algorithm *****************************

void iterateMatrixModel(const std::vector<std::vector<double> > &transitionMatrix,
std::vector<double> &vecv, double &lambda)
// iterates matrix population model to find the stable age distribution
// (which will be stored in vecv) and the long-term geometric growth
// rate (which will be stored in lambda).
{
// constants
const double epsilon = 1.0e-12;
const int itMax = 9999;

// prepare for iteration
const int iA = transitionMatrix.size();
if(iA == 0) // throw exception if number of age classes is zero
throw std::logic_error("transition matrix is empty.\n");

std::vector<double> vecn(iA, 1.0 / iA);
vecv = std::vector<double>(iA);

// iterate until convergence
int it;
for(it = 0; it < itMax; ++it) {
// execute matrix-vector multiplication to obtain next state
lambda = 0.0;
for(int i = 0; i < iA; ++i) {
vecv[i] = 0.0;
for(int j = 0; j < iA; ++j)
vecv[i] += transitionMatrix[i][j] * vecn[j];
lambda += vecv[i];
}
// renormalise next state vector and quantify change in age distribution
double delta = 0.0;
for(int i = 0; i < iA; ++i) {
vecv[i] /= lambda;
double tmp = vecv[i] - vecn[i];
delta += tmp * tmp;
}
// check convergence criterion
if(delta < epsilon * epsilon)
break;
// update population state
vecn = vecv;
}

if(it == itMax)
throw std::runtime_error("slow convergence in function iterateMatrixModel().\n");

std::clog << "iteration in function iterateMatrixModel() converged after " << it << "steps.\n";
}

//*** main program ************************************

int main()
{
  // prototypes of auxiliary functions
  void initialise(std::vector<std::vector<double> >&);
  void show(const std::vector<std::vector<double> >&);
  void show(const std::vector<double>&, const double);

  try {
    // initialise transition matrix and show it on screen
    std::vector<std::vector<double> > transitionMatrix;
    initialise(transitionMatrix);
    show(transitionMatrix);

    // calculate stable age distribution and growth rate
    std::vector<double> stableAgeDistribution;
    double longTermGeometricGrowthRate;

    iterateMatrixModel(transitionMatrix, stableAgeDistribution,
    longTermGeometricGrowthRate);

    // show result
    show(stableAgeDistribution, longTermGeometricGrowthRate);
  }
  catch(std::exception &error)
  {
    std::cerr << "error: " << error.what() << '\n';
    exit(EXIT_FAILURE);
  }
  return 0;
}

//*** auxiliary functions *****************************

void initialise(std::vector<std::vector<double> > &matL)
// initialises the transition matrix
{
// create a matrix of the desired size and initialise with zeroes
  const int iA = 10; // number of age classes
  matL = std::vector<std::vector<double> >(iA, std::vector<double>(iA, 0.0));

  // set fecundities (values below are an arbitrary example)
  matL[0][2] = 0.2;
  matL[0][3] = 0.4;
  matL[0][4] = 1.2;
  matL[0][5] = 1.5;
  matL[0][6] = 1.5;
  matL[0][7] = 1.4;
  matL[0][8] = 1.1;
  matL[0][9] = 0.6;

  //set survival probabilities (values below are an arbitrary example)
  matL[1][0] = 0.4;
  matL[2][1] = 0.9;
  for(int i = 3; i < iA; ++i)
  matL[i][i-1] = 0.95 * matL[i - 1][i - 2];
}

void show(const std::vector<std::vector<double> > &matL)
// shows transition matrix on the screen
{
std::cout << "transition matrix: \n";
const int iA = matL.size();
for(int i = 0; i < iA; ++i) {
for(int j = 0; j < iA; ++j)
std::cout << ' ' << std::left << std::setw(6) << std::setprecision(3) <<
matL[i][j];
std::cout << '\n';
}
std::cout << '\n';
}

void show(const std::vector<double> &vecv, const double lambda)
// shows stable age distribution and growth rate on the screen
{
std::cout << "\nstable age distribution: \n";
for(int i = 0; i < vecv.size(); ++i)
std::cout << ' ' << std::left << std::setw(6) << std::setprecision(3) << vecv[i];
std::cout << '\n';

std::cout << "\nlong-term geometric growth rate: \n"
<< lambda << '\n';
}
