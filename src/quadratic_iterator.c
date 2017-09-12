
#include "../lib/libft/libft.h"

// calculates the term z(k+1) = z(k)^2 + c
t_complex	quadratic_iterator(t_complex zk, t_complex c)
{
	return (cadd(cmul(zk, zk), c));
}

