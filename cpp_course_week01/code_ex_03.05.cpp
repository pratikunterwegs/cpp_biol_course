#include <iostream>
#include <cmath>

int main()
{
    double a; double b; double c;

    std::cout << "Enter a, the coefficient of x^2 : \n";
    std::cin >> a;
    std::cout << "\nEnter b, the coefficient of x : \n";
    std::cin >> b;
    std::cout << "\nEnter c, the constant : \n";
    std::cin >> c;

    if ((b*b) - (4*a*c) < 0)
    {
        std::cout << "The equation has no real roots"
                  << std::endl;
        return 0;
    }

    double root_01 = (-b + sqrt((b*b) - (4*a*c)))/(2*a);
    double root_02 = (-b - sqrt((b*b) - (4*a*c)))/(2*a);

    std::cout << "The roots are : " << root_01 << " and " << root_02
              << std::endl;

    return 0;
}
