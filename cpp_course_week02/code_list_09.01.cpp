/* there are ways to read in CSV files line by line,
 * but these are best used only when really necessary.
 * it's easier to modify the outputs of usual functions such as
 * write_csv or write_delim from r
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;
int main()
{
    //open file with measurement data
    ifstream ifs("/home/pratik/git/cpp_biol_course/measurements.txt");
    if(!ifs.is_open()){
        cerr << "error: unable to open data file\n";
        exit(EXIT_FAILURE);
    }
    else
        cout << "file opened" << endl;

    //read input data
    double dAvg = 0.0, dStdDev = 0.0;
    int iN;
    for(iN = 0;;){
        //read from file
        double x;
        ifs >> x;

        //add data point
        ++iN;
        dAvg += x; //temp store sum of data values
        dStdDev += x * x; //temp store sum of squares

        if(ifs.eof()){ //get summary stats and exit at end of file
            if(iN < 2) exit(EXIT_SUCCESS); //exit if N < 2
            dAvg /= iN;
            dStdDev = sqrt((dStdDev - iN * dAvg * dAvg) / (iN - 1));
            break;
        }
    }
    ifs.close(); //manually close file

    //open output file
    ofstream ofs;
    ofs.open("/home/pratik/git/cpp_biol_course/summary_stats.txt");
    if(!ofs.is_open()){
        cerr << "error: unable to open output file\n";
        exit(EXIT_FAILURE);
    }

    //write summary stats to file
    ofs << "N = " << iN << '\n'
        << "mean = " << dAvg << '\n'
        << "stdev = " << dStdDev << '\n';
    return 0;
}
