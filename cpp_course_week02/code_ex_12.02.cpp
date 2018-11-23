#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

const int iOffspring = 1000; //max pop size
const double s = 0.01; //selection ceoff
const double mu = 0.1; //mutation rate

struct Individual
{
    bool isWTAllele, isAlive;
};

vector<Individual> population(iOffspring, {true, true});

void mutation()
{
    for(int i = 0; i < population.size(); ++i)
        if(!population[i].isWTAllele && rand() < mu * RAND_MAX)
            population[i].isWTAllele = false;
}

void selection()
{
    //indivs with deleterious mut die with prob s
    for (int i = 0; i < population.size(); ++i)
        if(!population[i].isWTAllele && rand() < s * RAND_MAX)
            population[i].isAlive = false;
        else
            population[i].isAlive = true;
}

void removeDeadInviduals()
{
    for(int i = 0; i < population.size(); ++i){
        if(population[i].isAlive == false){
            //replace indiv by last indiv
            population[i] = population.back();
            population.pop_back();

            //another way of removing dead indivs
//            population.erase((population.begin() + i));
//            --i;
        }
    }
}

void produceOffspring()
{
    assert(population.size() > 0);
    vector<Individual> offspring;
    for(int i = 0; i < iOffspring; ++i){
        //select parent for offsrping i
        const int j = i % population.size();
        assert(population[j].isAlive);
        offspring.push_back(population[j]);
    }
    //replace parents by offspring
    population = offspring;
}

void showData(int t)
{
    int cnt = 0;
    for(int i = 0; i < population.size(); ++i){
        if(population[i].isWTAllele == false)
            ++cnt;
    }

    cout << t << ' ' << cnt/population.size() << "\n";
}

int main()
{
    //seed random number generator
    srand(127264);

    //start sim
    for(int t = 1; t < 1000; ++t){
        mutation();
        selection();
        //removeDeadInviduals();
        produceOffspring();
        showData(t);
    }
    return 0;
}
