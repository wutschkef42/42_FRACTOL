

#ifndef _FRACTOL_H
# define _FRACTOL_H


# define SCALE		0.6
# define WIDTH		1200
# define HEIGHT 	1200
# define NITMAX		65

# include "../../lib/complex_math/inc/complex_math.h"

// store environment variables for graphics environment
typedef struct	s_env
{
	int bpp;
	int sl;
	int ed;	
}				t_env;


t_complex   *iterate(t_complex in, t_complex const);
t_complex	quadratic_iterator(t_complex zk, t_complex c);
t_complex	sin_iterator(t_complex zk, t_complex c);
t_complex	cos_iterator(t_complex zk, t_complex c);
void    	plot_point(char **data_addr, int sl, int x, int y, int color);
void		mandelbrot(char **data_addr);
void		quadratic_julia(char **data_addr);
void		sin_julia(char **data_addr);
int			generate_fractal(char *id, char **data_addr);
int			colorize(int k);
int			fractal_exists(char *id);
void		print_man(void);



#endif