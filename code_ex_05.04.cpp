#include <iostream>

int main()
{
    for (int iPrimeCandidate = 2, iFactor; iPrimeCandidate < 1000; ++iPrimeCandidate){
        for(iFactor = 2; iFactor <= (iPrimeCandidate / iFactor); ++iFactor){
            if(!(iPrimeCandidate % iFactor))
                break;
        }
        if(iFactor > (iPrimeCandidate / iFactor))
            std::cout << iPrimeCandidate << " is prime" << std::endl;

    }
    return 0;
}
