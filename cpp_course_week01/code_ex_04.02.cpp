#include <iostream>
#include <cmath>

int main()
{
    const bool isInputA = true; const bool isInputB = true;

    if(isInputA^isInputB){
        std::cout << "Hurrah!"
                  << std::endl;
    }
    else {
        std::cout << "Boo!"
                  << std::endl;
    }

    return 0;
}
