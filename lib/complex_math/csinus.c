
#include "libft.h"
#include <math.h>

t_complex   csinus(t_complex c)
{
	t_complex res;
	double re;
	double im;

	re = c.re;
	im = c.im;

    res.re = sin(re) * cosh(im);
    res.im = cos(re) * sinh(im);

    return (res);
}
