
#ifndef _COMPLEX_MATH
# define _COMPLEX_MATH

/*
** represent complex numbers
** in real and imaginary part
*/
typedef struct  s_complex
{
    double  re;             // real
    double  im;             // imaginary 
}               t_complex;

t_complex   cadd(t_complex c1, t_complex c2);
t_complex   csub(t_complex c1, t_complex c2);
t_complex   cmul(t_complex c1, t_complex c2);
t_complex   cdiv(t_complex c1, t_complex c2);
t_complex   ccon(t_complex c);
double		cabsv(t_complex c);
t_complex	csinus(t_complex c);
t_complex	ccosinus(t_complex c);
t_complex	cexpo(t_complex c);


#endif