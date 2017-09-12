

#include <math.h>
#include "libft.h"

double		cabsv(t_complex c)
{
	return (sqrt(pow(c.re, 2) + pow(c.im, 2)));
}
