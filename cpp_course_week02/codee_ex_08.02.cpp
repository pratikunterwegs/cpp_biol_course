#include <iostream>

char convertCase(const char &letter){

    const int letterNum = static_cast<int>(letter);
    return  letterNum > 64 && letterNum < 91 ? static_cast<char>(letterNum + 32) : static_cast<char>(letterNum - 32);
}

using namespace std;
int main()
{
    cout << "Enter a letter in the English alphabet : ";
    char letter;
    cin >> letter;

    cout << "The letter in the opposite case is " << convertCase(letter) <<
            endl;

    return 0;
}
