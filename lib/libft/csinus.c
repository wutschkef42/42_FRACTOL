
#include "libft.h"
#include <math.h>

t_complex   csinus(t_complex c)
{
	t_complex res;
	double re;
	double im;

	re = c.re;
	im = c.im;

    res.re = exp(re) * cos(im);
    res.im = exp(re) * sin(im);

    return (res);
}
