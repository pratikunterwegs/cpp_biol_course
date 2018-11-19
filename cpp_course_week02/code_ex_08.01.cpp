//write letters of the alphabet

#include <iostream>

using namespace std;
int main()
{
    for(int i = 65; i < 90; ++i)
        cout << static_cast<char>(i) << " " << static_cast<char>(i+32) <<
                endl;
    cout << endl;
    return 0;
}
