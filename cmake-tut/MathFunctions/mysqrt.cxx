#include <iostream>
#include "TutorialConfig.h"
#if defined(USE_EXP_LOG) && defined(HAVE_LOG) && defined(HAVE_EXP)
#include <math.h>
#endif

double mysqrt(double x)
{
    if (x <= 0) {
        return 0;
    }
#if defined(USE_EXP_LOG) && defined(HAVE_LOG) && defined(HAVE_EXP)
    double result = exp(log(x)*0.5);
    std::cout << "Computing sqrt using exp() and log()" << std::endl;
#else
    double result = x;

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
