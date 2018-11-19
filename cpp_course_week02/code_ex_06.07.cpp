#include <iostream>

using namespace std;
//write recursive function for factorial, basically n *= n-1
int funcFactorial(const int &iNumber){

    return iNumber == 0 ? 1 : iNumber * funcFactorial(iNumber - 1);
}

int main()
{
    cout << "Enter a number for factorial : \n";
    int iNumber;
    cin >> iNumber;

    cout << "The factorial of " << iNumber << " is = " << funcFactorial(iNumber) <<
            endl;

    return 0;
}
