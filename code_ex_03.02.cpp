#include <iostream>

int main()
{
    {
        int i, j;
        j = (4*(i%=(3*2))/5); // get variables by original formula
        int i_02, j_02;
        j_02 = 4 * (i_02 %= (3 * 2)) /5; //  formula with fewer brackets

        // output the comparison
        std::cout << "(a) The value of i and j with the full number of brackets is : " << i << " and " << j
                  << " and the expression can be written : j = 4 * (i %= 3*2) / 5 \n to return the same values "
                  << i_02 << " and " << j_02
                  << std::endl;
    }

//    //new scope
//    {
//        int i; int j;
//        (j = (5 * (-(i += 5)))); // original formula
//        int i_02; int j_02;
//        //(j_02 = 5 * (-(i_02 += 5)));
//        (j_02 = i_02);

//        // output the comparison
//        std::cout << "(b) The value of i and j with the full number of brackets is : " << i << " and " << j
//                  << " and the expression can be written : j = 5 * (-(i_02 += 5)) \n to return the same values "
//                  << i_02 << " and " << j_02 << std::endl;
//    }

    return 0;


}
