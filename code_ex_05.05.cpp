/* descriptive stats with entered positive numbers */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
    //prep to store mean
    double dMean; double dSD;
    //read numbers from screen
    vector<double> vec;
    cout << "Enter positive numbers on prompt, or a negative number to stop entry" << endl;

    //take entries
    for(;;){
        cout << "Next number: ";
        double dInput;
        cin >> dInput;

        //terminate entry on negative number
        if(dInput < 0.0){
            cout << "You have terminated entry.\n";
            break;
        }
        else {
            vec.push_back(dInput); //add new entry to end of vector
        }
    }

    if(vec.size() <= 1){
        cout << "You have entered too few numbers for summary stats"
             << endl;
        return 0;
    }

    //calculate mean in this scope
    {
        double dSum;
        for(int i = 0; i < vec.size(); ++i){
            dSum += vec[i];
        }
        //store the mean
        dMean = dSum/vec.size();
        cout << "The mean of your entries is = "
             << dMean
             << endl;

    }

    //sd in this scope
    {
        double dDiffSum;
        for(int i = 0; i < vec.size(); ++i){
            dDiffSum += pow((vec[i] - dMean), 2);

        }
        //get the difference in sums squared divided by sample size under root for SD
        dSD = sqrt(dDiffSum/vec.size());
        cout << "and the standard deviation is = "
             << dSD
             << endl;
    }

    return 0;
}
