
#include "libft.h"
#include <math.h>

//WRONG
t_complex   ccosinus(t_complex c)
{
	t_complex res;
	double re;
	double im;

	re = c.re;
	im = c.im;

    res.re = cos(re) * cosh(im);
    res.im = (-1) * sin(re) * sinh(im);

    return (res);
}
