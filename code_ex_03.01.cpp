#include <iostream>

int main()
{
    {
        int i = 7; i %= 3;
        std::cout << "The value of integer i was 7, and after i %= 3 is : " << i
                << std::endl;

    }

    {
        int i = 7, j = i *=2;
        std::cout << "The value of integer i was 7, and after j = i *= 2 the value of i is : " << i << " and the value of j is : " << j
                  << std::endl;
    }

    {
        int i, j;
        j *= (i = 2, j = 4);
        std::cout << "The value of integers i and j after j = (2 * (++i)++) / (3 + 2) is : " << i << " and " << j
                  << std::endl;
    }

    return 0;
}
