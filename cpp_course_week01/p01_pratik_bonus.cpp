/* a program to make cone shell patterns
 * using a cellular automaton model
 * this automaton is rule 110.
 * in this model i changes in only 3 cases
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//define a function to update the value of the entire pattern at once
vector<int> updatePattern(vector<int> &pattern){

    //get the vector size
    const int iPatternSize = pattern.size();

    //make a duplicate vector for reference
    vector<int> vecTmp = pattern;

    for(int i = 0; i < iPatternSize; ++i)
    {

        //define a variable for the sum of i-1, i, and i+1
        int iLocalSum;

        /*check if the position is 0 or n-1, special cases,
         * and compute the iLocalSum value.
         * this could have been a switch, but meh...it works */

        if(i == 0)
            iLocalSum = (100*vecTmp[iPatternSize-1])+(10*vecTmp[i])+(vecTmp[i+1]);
        else if(i == (iPatternSize-1))
            iLocalSum = (100*vecTmp[i-1])+(10*vecTmp[i])+(vecTmp[0]);
        else
            iLocalSum = (100*vecTmp[i-1])+(10*vecTmp[i])+(vecTmp[i+1]);

        /*run through 2 main sets of cases for values of iLocalSum --
        where value of i changes, and where not*/
        switch (iLocalSum) {
        case 111:
            pattern[i] = 0;
            break;
        case 101:
            pattern[i] = 1;
            break;
        case 1:
            pattern[i] = 1;
            break;
        case 11: case 10:
        case 100: case 0:
        case 110:
            break;
        }
   }
    //return the pattern vector
    return pattern;
}

//begin the main function
int main(){

    //declare a vector to hold pattern values, set vec[0] = 1
    vector<int> pattern(250,0);
    pattern[0] = 1;

    /*run through 3N/2 iterations
     * not accounting for
     * 3N/2 being a non decimal number
     * implicit type conversion yes, but never mind*/
    const int iterations = pattern.size()*1.5;

    //output original pattern
    for(int i = 0; i < pattern.size(); ++i)
        cout << pattern[i];
    cout << "\n\n" << endl;

    //output each new pattern after updating 3N/2 times
    /*prep to write to file
     * remove </home/pratik/git/ccp_biol_course/> to run on your PC
     */
    ofstream myOutputFileStream("/home/pratik/git/cpp_biol_course/p01_pratik_data_rule110.csv");

    //update through 3N/2 iterations
    for(int i = 0; i < iterations; ++i){

        //run the update function on the pattern vector
        pattern = updatePattern(pattern);
        //output values from N/2 (125) iterations to file
        for(int j = 1; j < pattern.size(); ++j)
            if(i >= 125)
                myOutputFileStream << pattern[j] << ",";
            //cout << pattern[i];
        myOutputFileStream << endl;

        //print the first 50 cells, ie, cols to screen to check
        for(int k = 0; k < 50; ++k)
            cout << pattern[k];
        cout << endl;

    }
    myOutputFileStream.close();
    return 0;


}
