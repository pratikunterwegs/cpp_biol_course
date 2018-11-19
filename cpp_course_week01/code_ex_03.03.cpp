#include <iostream>
#include <cmath>

int main()
{
    //get the variables, some of which are constants
    double size_time_t; const double size_t_0 = 0.01; const double size_max = 1.0;
    const double alpha = 0.2;
    double time_t;

    //ask for input in days
    std::cout << "Enter a time in days : "; std::cin >> time_t;

    //calculate the size
    size_time_t = size_max * (exp(log(size_t_0/size_max) * exp(-(alpha*time_t))));

    //return output and give days at which 95% is reached

    std::cout << "The size of the tumour is : " << size_time_t << " units "
              << " and it (will) reach(-ed) 95% of size at "
              << (0.95 * time_t)/size_time_t
              << " days "
              << std::endl;

    return 0;
}
