

#ifndef _FRACTOL_H
# define _FRACTOL_H

# define DIM_X 600
# define DIM_Y 400

# define SCALE		0.6
# define WIDTH		1200
# define HEIGHT 	1200
# define NITMAX		65

# include "../../lib/complex_math/inc/complex_math.h"


t_complex   *iterate(t_complex in, t_complex const);
t_complex	quadratic_iterator(t_complex zk, t_complex c);
void    	plot_point(char **data_addr, int sl, int x, int y, int color);
void		mandelbrot(char **data_addr);
void		julia(char **data_addr);




#endif