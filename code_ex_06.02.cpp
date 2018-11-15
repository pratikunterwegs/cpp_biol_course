/* program for the ricker model but with a function
 * for pop size at t given pop size at t-1
*/

#include <iostream>

using namespace std;

int main(){
    int i = 0;
    int &j = i;

    cout << "i = " << i << "; j = " << j << endl;

    ++j;

    cout << "i = " << i << "; j = " << j << endl;

    ++i;

    cout << "i = " << i << "; j = " << j << endl;

 return 0;

}
