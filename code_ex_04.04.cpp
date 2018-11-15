#include <iostream>
#include <cmath>

int main()
{
   //declare var, ask for vars and assign input to vars
   double a; double b; double c;

   std::cout << "Enter a, the coefficient of x^2 : \n";
   std::cin >> a;

   std::cout << "\nEnter b, the coefficient of x : \n";
   std::cin >> b;

   //test for case where solution == 0
   if(a == 0 && b != 0){
   std::cout << "The equation has the single solution 0."
             << std::endl;
   return 0;
       }

   std::cout << "\nEnter c, the constant : \n";
   std::cin >> c;

   //calculate b^2 - 4ac
   const double coeff_comb = (b*b) - (4*a*c);


           //solution is imaginary
           if (coeff_comb < 0){
           std::cout << "The equation has no real roots"
                     << std::endl;
       }
           //solution is two real roots, provide roots
           else if(coeff_comb > 0){
           std::cout << "The roots are : " << (-b + sqrt((b*b) - (4*a*c)))/(2*a) << " and " << (-b - sqrt((b*b) - (4*a*c)))/(2*a)
                     << std::endl;
       }
           //solution is a single non-zero root
           else if(coeff_comb == 0){
           std::cout << "The single root is : " << -b/(2*a)
                     << std::endl;
       }
   return 0;
}
