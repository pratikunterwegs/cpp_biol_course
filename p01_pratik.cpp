/* a program to make cone shell patterns
 * using one of two cellular automaton models
 * written 16 Nov 2018 pratik gupte
 * p.r.gupte@rug.nl
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>

using namespace std;

//define a function to update the value of the entire pattern at once
vector<int> updatePattern(vector<int> &pattern, bitset<8> rule){

    //get the vector size
    const int iPatternSize = pattern.size();
    //make a duplicate vector for reference
    vector<int> vecTmp = pattern;

    //iterate along the elements
    for(int i = 0; i < iPatternSize; ++i)
    {
        //define iLeft, iRight, and iFocal
        int iFocal = vecTmp[i];
        int iLeft = i == 0 ? vecTmp[iPatternSize - 1] : vecTmp[i - 1];
        int iRight = i == 249 ? vecTmp[0] : vecTmp[i + 1];

        //define a variable for the sum of i-1, i, and i+1
        int iLocalSum = (4 * iLeft) + (2 * iFocal) + (iRight);

        //update the pattern
        pattern[i] = rule[iLocalSum];

   }
    //return the pattern vector
    return pattern;
}

//begin the main function
int main(){

    //ask for rule
    cout << "Enter the cellular automaton rule (1 -- 256):\n"
         << endl;
    //get rule choice
    int iRuleChoice; cin >> iRuleChoice;

    //define the rule output
    bitset<8> rule = iRuleChoice;

    //quit if the choice is higher than 256
    if(iRuleChoice > 256)
      {
        cout << "You have entered an invalid choice, exiting now." << endl;
        return 0;
    }

    //inform user of their choice
    cout << "You chose rule " << iRuleChoice << endl;

    //declare a vector to hold pattern values, set vec[0] = 1
    vector<int> pattern(250,0);
    pattern[0] = 1;

    /*run through 3N/2 iterations
     * force the number to be an integer*/
    const int iterations = static_cast<int>(pattern.size()*1.5);

    //output each new pattern after updating 3N/2 times
    /*prep to write to file*/
    ofstream myOutputFileStream("/home/pratik/git/cpp_biol_course/p01_pratik_data.csv");

    //update through 3N/2 iterations
    for(int i = 0; i < iterations; ++i){

        //run the update function on the pattern vector
        pattern = updatePattern(pattern, iRuleChoice);
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
    //close the output stream
    myOutputFileStream.close();
    return 0;


}
