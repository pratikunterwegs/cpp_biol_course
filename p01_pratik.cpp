/* a program to make cone shell patterns
 * using one of two cellular automaton models
 * written 16 Nov 2018 pratik gupte
 * p.r.gupte@rug.nl
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//define a function to update the value of the entire pattern at once
vector<int> updatePattern(vector<int> &pattern, int &iRuleChoice){

    //get the vector size
    const int iPatternSize = pattern.size();

    //make a duplicate vector for reference
    vector<int> vecTmp = pattern;

    //iterate along the elements
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

        /* add the choice of rule to follow as another switch*/

        switch(iRuleChoice){
         case 1:
            /*run through 2 main sets of cases for values of iLocalSum --
            where value of i changes, and where not*/
            switch (iLocalSum) {
            case 111:
                pattern[i] = 0;
                break;
            case 110:
                pattern[i] = 0;
                break;
            case 100:
                pattern[i] = 1;
                break;
            case 1:
                pattern[i] = 1;
                break;
            case 11: case 10:
            case 101: case 0:
                break;
            }
            break;
         case 2:
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

   }
    //return the pattern vector
    return pattern;
}

//begin the main function
int main(){

    //ask for which rule to follow
    cout << "Which rule, 30 or 110, do you want the cellular automaton to follow?"
         << "\n\n"
         << "Enter your choice, 1 for rule 30, 2 for rule 110.\n"
         << endl;

    int iRuleChoice;
    cin >> iRuleChoice;

    //quit if the choice is neither 1 nor 2
    if(iRuleChoice != 1 && iRuleChoice != 2)
      {
        cout << "You have entered an invalid choice, exiting now." << endl;
        return 0;
    }

    //inform user of their choice
    cout << "You chose rule " << (iRuleChoice == 1? "30": "110") << endl;

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
