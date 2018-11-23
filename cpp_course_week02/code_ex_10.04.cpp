t/* program to operate on complex numbers
 */

#include <iostream>
#include <cmath>

using namespace std;

//define a struct complex number
struct ComplexNumber
{
    float a, b;
};

//define functions
//function to print
void printComplexNumber(ComplexNumber z){
    cout << "z = " << z.a << " + " << z.b << "i\n\n";
}

//function to get norm
float normComplexNumber(ComplexNumber z){
    const float normZ = sqrt((z.a * z.a) + (z.b * z.b));
    return normZ;
}

//function to get conjugate
ComplexNumber conjugateComplexNumber(ComplexNumber z){
    const ComplexNumber conjZ = {z.a, -z.b};
    return conjZ;
}

//function for a second complex number
void productComplexNumber(ComplexNumber z){

    cout << "Enter the parts of another complex number z2\n\n";
    ComplexNumber z2;
    cin >> z2.a >> z2.b;

    cout << "z1 * z2 = "
         << ((z.a * z2.a) - (z.b * z2.b)) << " + " << ((z.a * z2.b) + (z.b * z2.a))
         << "i\n";
}

//function for ratio
void ratioComplexNumber(){
    cout << "This is complex number division\n"
         << "Enter the parts of a complex number z1\n\n";
    ComplexNumber z1;
    cin >> z1.a >> z1.b;

    cout << "Enter the parts of another complex number z2\n\n";
    ComplexNumber z2;
    cin >> z2.a >> z2.b;

    //temp norm
    const float normZ2 = pow(sqrt((z2.a * z2.a) + (z2.b * z2.b)), 2);

    //temp complex number for z̅
    ComplexNumber conjZ = {z2.a, -(z2.b)};
    //output
    cout << "z1 / z2 = "
         << ((z1.a * conjZ.a) - (z1.b * conjZ.b))
         << "/" << normZ2
         << " + "
         << ((z1.a * conjZ.b) + (z1.b * conjZ.a))
         << "/" << normZ2
         << "i" << endl;

}


//main function
int main()
{
    //ask for complex number parts from user
    cout << "enter the real and imaginary parts of a complex number\n";
    ComplexNumber myComplexNumber;
    cin >> myComplexNumber.a >> myComplexNumber.b;

    //print comlpex number
    printComplexNumber(myComplexNumber);
    //print norm
    cout << "the norm of the complex number z = " << normComplexNumber(myComplexNumber) << endl;
    //print conjugate
    ComplexNumber conjMyComplexNumber = conjugateComplexNumber(myComplexNumber);
    cout << "the conjugate of the complex number z = " <<  conjMyComplexNumber.a << " + " << conjMyComplexNumber.b << "i" << endl;
    //multiply two complex numbers
    productComplexNumber(myComplexNumber);

    //get ratio of two complex numbers
    ratioComplexNumber();

    return 0;
}
