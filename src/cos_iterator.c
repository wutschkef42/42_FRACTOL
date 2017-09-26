
#include "../lib/libft/libft.h"

// calculates the term z(k+1) = c * cos(z(k)) note this is a complex sine
t_complex	cos_iterator(t_complex zk, t_complex c)
{
	return (cmul(c, ccosinus(zk)));
}

