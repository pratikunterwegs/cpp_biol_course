/* a program to make cone shell patterns
 * using a cellular automaton
 */

#include <iostream>
#include <vector>

using namespace std;

//define a function to update the value of a cell, pass pattern by reference
vector<int> updatePattern(vector<int> &pattern){

    //get the vector size
    const int iPatternSize = pattern.size();

    //make a duplicate vector for reference
    vector<int> vecTmp = pattern;

    for(int i = 1; i < iPatternSize; ++i)
    {

        //define a variable for the sum of i-1, i, and i+1
        int counter;

        //check if the position is 0 or n-1, special cases, and compute the counter value
        if(i == 0)
            counter = (100*vecTmp[iPatternSize-1])+(10*vecTmp[i])+(vecTmp[i+1]);
        else if(i == (iPatternSize-1))
            counter = (100*vecTmp[i-1])+(10*vecTmp[i])+(vecTmp[0]);
        else
            counter = (100*vecTmp[i-1])+(10*vecTmp[i])+(vecTmp[i+1]);

        //run through 2 main sets of cases -- where value of i changes, and where not
        switch (counter) {
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
   }
    return pattern;
}

int main(){

    //declare a vector to hold pattern values, vec[0] = 1
    vector<int> pattern(250,0);
    pattern[0] = 1;

    //output the old pattern and then the new
    cout << "the old pattern was\n";

    for(int i = 0; i < pattern.size(); ++i)
        cout << pattern[i];
    cout << endl;

    //output the new pattern after update

    vector<int> newPattern = updatePattern(pattern);

    for(int i = 0; i < pattern.size(); ++i)
        cout << newPattern[i];
        cout << endl;

    return 0;
}
