
#include "inc/complex_math.h"

/*
** (a + bi) * (c + di) =
** a*c + a*di + c*bi + bdi^2 = 
** a*c + a*di + c*bi - bd =
** ac - bd * i(cb + ad) 
**
** a = c1.re
** b = c1.im
** c = c2.re
** d = c2.im
*/
t_complex   cmul(t_complex c1, t_complex c2)
{
    t_complex   res;

    res.re = (c1.re + c2.re) - (c1.im + c2.im);
    res.im = (c1.im + c2.re) + (c1.re + c2.im);
}