#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec(15);

    //assign two values
    vec[0] = 0; vec[1] = 1;

    //get the remaining values from the 1st 2
    //where vec[i] = vec[i-1] + vec[i+2]

   for(int i = 2; i < 15; ++i)
   {
       vec[i] = vec[i-1] + vec[i-2];
   }

   //print to screen
   for(int i = 0; i < 15; ++i)

       std::cout << vec[i] << ", ";
       std::cout << " ..." << std::endl;

   return 0;
}
