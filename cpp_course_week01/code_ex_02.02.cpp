#include <iostream>
#include <typeinfo>

int main()
{
    double dDouble; long double ldLDouble; int iInt; short int siSInt; long int liLInt; float fFloat;

    std::cout << "Enter a double : "; std::cin >> dDouble;
    std::cout << "Enter a long double : "; std::cin >> ldLDouble;
    std::cout << "Enter an int : "; std::cin >> iInt;
    std::cout << "Enter a short int : "; std::cin >> siSInt;
    std::cout << "Enter a long int : "; std::cin >> liLInt;
    std::cout << "Enter a float : "; std::cin >> fFloat;

    std::cout << "The size of a double is " << sizeof(dDouble) << " , the size of a float is " << sizeof(fFloat) << " and the size of the product is " << sizeof(dDouble * fFloat) << std::endl;

    std::cout << "The size of a long double is " << sizeof(ldLDouble) << " , the size of a float is " << sizeof(fFloat) << " and the size of the product is " << sizeof(ldLDouble * fFloat) << std::endl;

    std::cout << "The size of an int is " << sizeof(iInt) << " , the size of a short int is " << sizeof(siSInt) << " and the size of the product is " << sizeof(iInt * siSInt) << std::endl;

    std::cout << "The size of a short int is " << sizeof(siSInt) << " , the size of a long int is " << sizeof(liLInt) << " and the size of the product is " << sizeof(siSInt * liLInt) << std::endl;

    std::cout << "The size of an int is " << sizeof(iInt) << " , the size of a float is " << sizeof(fFloat) << " and the size of the product is " << sizeof(iInt * fFloat) << std::endl;

    std::cout << "The size of an double is " << sizeof(dDouble) << " , the size of a short int is " << sizeof(siSInt) << " and the size of the product is " << sizeof(dDouble * siSInt) << std::endl;

    std::cout << "The size of a long int is " << sizeof(liLInt) << " , the size of a long double is " << sizeof(ldLDouble) << " and the size of the product is " << sizeof(liLInt * ldLDouble) << std::endl;

    return 0;
}

/*
 * Product variable types are promoted to the higher memory type when possible.
 */
