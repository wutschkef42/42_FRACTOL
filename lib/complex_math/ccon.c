
#include "inc/complex_math.h"

// complex conjugate
t_complex   ccon(t_complex c)
{
    c.im *= -1; 
    return (c);
}