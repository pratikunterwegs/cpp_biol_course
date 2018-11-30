#include <iostream>
#include <vector>
#include <chrono>
#include <random>

//load namespace
using namespace std;

//write permutation function
vector<int> vecPermute(const int &vecSize){

    //create holding vector of length vecSize
    vector<int> vecPos;

    //populate with position values
    for(int i = 0; i < vecSize; ++i){
        vecPos.push_back(i);
    }

    //set up rng system
    std::mt19937_64 rng;

      for(int i = vecSize; i > 0;){

          //pick random number
          std::uniform_int_distribution<int> randPicker(0, vecSize);
          int j = randPicker(rng);
          //swap positions
          int temp = vecPos[i]; vecPos[i] = vecPos[j]; vecPos[j] = temp;
          --i;
      }
        //return the vector of positions: this exercise actually ends here
      return vecPos;
}

//main function
int main()
{
    //declare a vector of any type
    vector<string> sentence {"this","is","a","sentence"};
    //permute the vector
    vector<int> permutedPos = vecPermute(sentence.size());

    //print permuted vector
    for(int i = 0; i < permutedPos.size(); ++i){
        cout << sentence[permutedPos[i]] << " ";
    }
    cout << endl;

    return 0;
}
