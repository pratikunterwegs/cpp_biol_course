#include <iostream>

int main()
{
    double dWeightCaffeine;
    const double dWeightC = 12.011, dWeightH = 1.008,
                 dWeightN = 14.007, dWeightO = 15.999;

    dWeightCaffeine = 8 * dWeightC + 10 * dWeightH + 4 * dWeightN + 2 * dWeightO;

    std::cout << "1,3,7-Trimethylpurine-2,6-dione (caffeine) weighs: "
              << dWeightCaffeine << " g/mol."
              << std::endl;

    return 0;
}
