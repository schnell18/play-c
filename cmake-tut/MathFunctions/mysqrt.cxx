#include <iostream>
#include "TutorialConfig.h"
#include "Table.h"
#if defined(USE_EXP_LOG) && defined(HAVE_LOG) && defined(HAVE_EXP)
#include <math.h>
#endif

double mysqrt(double x)
{
    if (x <= 0) {
        return 0;
    }
    double result = x;
    if (x >= 1 && x < 10) {
        std::cout << "Using pre-computed result" << std::endl;
        result = sqrtTable[static_cast<int>(x)];
        return result;
    }

#if defined(USE_EXP_LOG) && defined(HAVE_LOG) && defined(HAVE_EXP)
    result = exp(log(x)*0.5);
    std::cout << "Computing sqrt using exp() and log()" << std::endl;
#else

    for (int i = 0; i < 10; ++i) {
        if (result <= 0) {
            result = 0.1;
        }
        double delta = x - (result * result);
        result = result + 0.5 * delta / result;
        std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
    }
#endif
    return result;
}
