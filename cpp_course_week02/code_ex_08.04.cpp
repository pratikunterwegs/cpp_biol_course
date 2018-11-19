#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// function to print codons
void codons(const string &rna){
    //find start codon
    const int startRNA = rna.find("AUG", 0);

    cout << "Coding starts at " << startRNA+1 << endl;

    string codon;
    cout << "The codons are: ";
    for(int i = startRNA; i < rna.size(); i+=3){
        //print codons
        codon = rna.substr(i, 3);
        cout << codon << " ";

        //break if stop codon found
        if(codon == "UAG" || codon == "UGA" || codon == "UAA"){
            cout << "\nStop codon " << codon <<  " reached.\n"
                 << "This RNA has " << i/3 << " codons."
                 << endl;
            break;
        }

     }
}


using namespace std;
int main()
{
    string rna;
    //ask and get RNA seq
    cout << "Enter an RNA deq (5' -- 3'):" << endl;
    cin >> rna;

    //return the start codon, codons in between, and stop codon:
    codons(rna);
    return 0;
}
