#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

//parameters
const int gridSize = 20;
const int nFood = 10;
mt19937_64 rng; //random number generator
const int nEvents = 4;
const int Up = 0.1;
const int Dw = 0.6;
const int Rt = 0.1;
const int Lf = 0.1;
const int Nc = 0.1;
const double tMax = 5.0;

//make a landscape

void makeGrid(vector<vector<int> > &grid)
{
    //make grid, populate bottom with coral
    vector<int> base (gridSize, 2);
    grid[gridSize - 1] = base;

    //set seed
    chrono::high_resolution_clock::time_point tp = chrono::high_resolution_clock::now();
    unsigned seed = static_cast<unsigned> (tp.time_since_epoch().count());
    //write seed
    clog << "random seed " << seed << endl;;
    rng.seed(seed);

    //nFood food in random pos
    uniform_int_distribution<int> x (0, gridSize - 1);
    uniform_int_distribution<int> y (0, gridSize - 2);

    for(int i = 0; i < nFood;)
    {
        const int xCoord = x(rng); const int yCoord = y(rng);

        switch (grid[xCoord][yCoord]) {
        case 0: ++grid[xCoord][yCoord]; ++i; break;
        case 1: case 2: ; break;
        default:
            break;
        }
    }
}

//coords structure
struct coords {int x, y;};

void plotGrid(const vector<vector<int> > &grid)
{
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < gridSize; ++j){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    vector<vector<int> > grid (gridSize, vector<int> (gridSize));
    makeGrid(grid);
    plotGrid(grid);

    cout << endl;
    cout << "updated grid..." << endl;
    for(int counter = 0; counter < 10; counter++){
        //simulate Gillespie loop
        for(double t = 0.0; t < tMax;)
        {
            vector<coords> foodLocs (0);
            //gather food
            for(int i = 0; i < gridSize - 1; ++i)
            {
                for(int j = 0; j < gridSize - 1; ++j)
                {
                    if(grid[i][j] == 1)
                        foodLocs.push_back({i,j});
                }
            }
            //pick a random food item
            uniform_int_distribution<int> randPicker(0, foodLocs.size());
            int j = randPicker(rng);
            coords focalFood = foodLocs[j];
            //calc rates for events in a doubles vector; one entry per event
            vector<int> vecRates(nEvents);
            //make rates
            vecRates[0] = Up;
            vecRates[1] = Dw;
            vecRates[2] = Rt;
            vecRates[3] = Lf;
            vecRates[4] = Nc;

            //get wait time to next event
            double sum = 0.0;
            for(int i = 0; i < nEvents; ++i)
            {
                sum += vecRates[i];
            }
            //sum the rates and if 0 or less quit with error
            if(sum < 0.0)
                throw runtime_error("unable to draw wait time, rate sum < 0\n");

            //draw a random number from an exponential distribution
            exponential_distribution<double> waitTime(sum);
            const double dt = waitTime(rng);

            //sample the next event
            discrete_distribution<int> drawEvent(vecRates.begin(), vecRates.end());
            const int move = drawEvent(rng);
            //cout << "chose an event... " << move << " ...\n\n";

            t += dt;

            //choose a move
            switch (move)
            {
            case 0:
                grid[focalFood.x][focalFood.y] = 0;
                while (grid[focalFood.x][focalFood.y + 1] != 0)
                {++grid[focalFood.x][focalFood.y + 1];}
                break; // move up
            case 1:
                grid[focalFood.x][focalFood.y] = 0;
                while (grid[focalFood.x][focalFood.y - 1] != 0)
                {++grid[focalFood.x][focalFood.y - 1];}
                break; // move down
                //do {--foodLocs[i].y;} while (foodLocs[i].y < 0);
            case 2:
                grid[focalFood.x][focalFood.y] = 0;
                while (grid[focalFood.x - 1][focalFood.y] != 0)
                {++grid[focalFood.x - 1][focalFood.y];}
                break; // move left
            case 3: //move right
                grid[focalFood.x][focalFood.y] = 0;
                while (grid[focalFood.x + 1][focalFood.y] != 0);
            {++grid[focalFood.x + 1][focalFood.y];}
                break;
            case 4: break; //no change
            default: throw logic_error("unknown event occurred!");
                exit(EXIT_FAILURE);//no break

            }
        }
    }
    plotGrid(grid);

}



