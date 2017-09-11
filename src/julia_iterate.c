
#include "../lib/complex_math/inc/complex_math.h"

// calculates the term z(k+1) = z(k)^2 + c
t_complex	julia_iterate(t_complex zk, t_complex c)
{
	return (cadd(cmul(zk, zk), c));
}

