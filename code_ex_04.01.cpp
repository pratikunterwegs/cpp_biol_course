//a program to determine insect taxonomy
#include <iostream>
#include <cmath>

int main()
{
    //assign values
    const int iNumberOfLegs = 80; const bool doesFly = false;

    //determine taxonomy
    if(doesFly == true){
            std::cout << "Answer: It's an insect.\n";
    }
                         else if(iNumberOfLegs == 8){
                         std::cout << "Answer: It's a spider.\n";
}
                                      else if(iNumberOfLegs == 6){
                                      std::cout << "Answer: It's an insect.\n";
            }
            else if(iNumberOfLegs == 0){
                std::cout << "Answer: It's a worm or a larva.\n";
            }
            else
                std::cout << "Answer: It might be a millipede.\n";

    return 0;
}

