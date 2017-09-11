

#include <math.h>
#include "inc/complex_math.h"

double		cabsv(t_complex c)
{
	return (sqrt(pow(c.re, 2) + pow(c.im, 2)));
}
