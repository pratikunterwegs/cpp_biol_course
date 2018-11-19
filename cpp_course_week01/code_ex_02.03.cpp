#include <iostream>

int main()
{

    int i; double j;
    std::cout << "Enter an int, i : "; std::cin >> i;
    std::cout << "Enter a double, j : "; std::cin >> j;

    std::cout << "Converting " << j << " to int = " << static_cast<int>(j) << std::endl;
    std::cout << "Converting " << i << " to double = " << static_cast<double>(i) << std::endl;

    return 0;
}

// doubles converted to int are floored, not rounded
