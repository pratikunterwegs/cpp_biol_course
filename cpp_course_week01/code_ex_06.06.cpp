/* function to write a running mean using static variables and while */
#include <iostream>

using namespace std;

//function to calc and write mean
void writeWeightMean(const double &weight){
    static double weightSum = 0.0;
    static int measures = 0;

    weightSum += weight;
    ++measures;

    cout << "The running mean of measures is\n"
         << weightSum/measures << endl;

}

//function to identify if user wants to continue
bool isContinue(){
    cout << "Enter next value : ";
    double weight;
    cin >> weight;

    if(weight < 0.0)
        return false;
    else{
      //run the write rnnning mean function if valid input
        writeWeightMean(weight);
        return true;
    }
}

//main function checking if isContinue is true
int main()
{
    cout << "Enter a series of weight measurements, or a negative value to stop."
         << endl;

    while (isContinue());
    //end
    return 0;
}
