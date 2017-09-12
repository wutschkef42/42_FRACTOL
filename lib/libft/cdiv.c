
#include "libft.h"

// to divide 2 complex numbers, multiply with conjugate
// of denominator
t_complex   cdiv(t_complex c1, t_complex c2)
{
    double      tmp;
    double      denom;
    t_complex   res;

    res.re = 0;
    res.im = 0;
    // DIVIDE BY 0 CATCH!
    denom = (c2.re * c2.re) + (c2.im * c2.im);
    if (!denom)
        return (res);
    tmp = (c1.re * c2.re) + (c1.im * c2.im);
    tmp /= denom;
    res.re = tmp;
    tmp = (c1.im * c2.re) - (c1.re * c2.im);
    tmp /= denom;
    res.im = tmp;
    return (res);
}