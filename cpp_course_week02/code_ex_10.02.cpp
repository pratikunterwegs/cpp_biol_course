#include <iostream>
#include <vector>

using namespace std;

//define a class with public function and private vars
class anotherPair
{
private:
    char first; int second;
public:
    void processEntry(char, int);
};

//define the function to enter and print data
void anotherPair::processEntry(char myChar, int myInt){
    first = myChar; second = myInt;

    cout << "this class contains the char and int pair "
         << first << " " << second
         << endl;
}

int main()
{


    //ask user for input and populate obj
    cout << "Enter a character and interger pair separated by space\n";
    char myChar; int myInt;
    cin >> myChar >> myInt;

    anotherPair somePair;
    somePair.processEntry(myChar, myInt);
    return 0;
}
