#include <iostream>

using namespace std;

string transcribe(const string &dna){

    //prep empty rna string
    string rna;
    for(int i = dna.size(); i >= 0; ){

        switch (dna[i]) {
            case 'A': rna.push_back('U'); break;
            case 'T': rna.push_back('A'); break;
            case 'G' : rna.push_back('C'); break;
            case 'C' : rna.push_back('G'); break;
        default:
            cout << "Not a base." << endl;
            break;

        }
    --i;
    }
    return rna;
}


int main()
{
    //ask for input
    cout << "Enter a DNA strand (5' -- 3')\n";
    string dna;
    cin >> dna;

    //run function and output value
    cout << "The RNA (5' -- 3') is " << transcribe(dna) <<
            endl;

    return 0;
}
