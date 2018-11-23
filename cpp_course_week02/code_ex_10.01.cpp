#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //declare pair obj of char and int
    pair<char, int> myPair;

    //declare struct obj
    struct anotherPair
    {
        char first; int second;
    };

    //ask user for input and populate obj
    cout << "Enter a character and interger pair separated by space\n";
    char myChar; int myInt;
    cin >> myChar >> myInt;

    //enter user input to pair and struct
    myPair.first = myChar; myPair.second = myInt;
    anotherPair myStruct = {myChar, myInt};

    //print obj to screen
    cout << "the pair is " << myPair.first << " " << myPair.second
         << endl
         << "the struct is " << myStruct.first << " " << myStruct.second
         << endl;
    return 0;
}
