#include <iostream>
#include <vector>
#include <chrono>
#include <random>

//load namespace
using namespace std;

//function to pick a position
int pickRand(const int &vecSize){

    //call the rng
    std::mt19937_64 rng;
    //get seed
    std:chrono::high_resolution_clock::time_point tp =
            std::chrono::high_resolution_clock::now();
    unsigned seed = static_cast<unsigned>(tp.time_since_epoch().count());
    //set seed
    clog << "random seed: " << seed << "\n";
    rng.seed(seed);
    //get distribution
    std::uniform_int_distribution<int> randPicker(0, vecSize);

    int randPos = randPicker(rng);

    return randPos;

}

//main function
int main(int argc, char *argv[])
{
    //make a vector
    vector<int> vec {1,2,3,4,5,6,7,8,23,23,3434,436,6464,232};

    //print a random element
    cout << "a random element is: " << vec[pickRand(vec.size())] << "\n";
    return 0;
}
