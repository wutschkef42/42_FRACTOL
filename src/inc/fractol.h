

#ifndef _FRACTOL_H
# define _FRACTOL_H

# define SCALE		1.0
# define WIDTH		500
# define HEIGHT 	500
# define NITMAX		200
# define ED 		1
# define BPP 		50
# define ZABSMAX 	10.0
# define X_MIN 		-2.0
# define X_MAX 		2.0
# define Y_MIN 		-2.0
# define Y_MAX 		2.0

#define START_COLOR 0x00ffffff


# include "../../lib/complex_math/inc/complex_math.h"

// store environment variables for graphics environment
typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	char		*fractal_name;
	
	int 		bpp;
	int 		sl;
	int 		ed;	

	int 		nitmax;
	float		zabsmax;
	float		x_min;
	float		x_max;
	float 		y_min;
	float		y_max;
	float		scale;
	t_complex	c;	
}				t_env;


t_complex   *iterate(t_complex in, t_complex const);
t_complex	quadratic_iterator(t_complex zk, t_complex c);
t_complex	sin_iterator(t_complex zk, t_complex c);
t_complex	cos_iterator(t_complex zk, t_complex c);
void    	plot_point(char **data_addr, int sl, int x, int y, int color);
void		mandelbrot(t_env *env);
void		quadratic_julia(t_env *env);
void		burningship(char **data_addr);
void		sin_julia(char **data_addr);
void		cos_julia(char **data_addr);
int			generate_fractal(char *id, t_env *env);
int			colorize(int k);
int			fractal_exists(char *id);
void		print_man(void);

int     	key_hook(int keycode, void *param);
int     	mouse_hook(int button, int x, int y, void *param);
int  	  	zoom_quadrant(int keycode, void *param);

void		julia(t_complex (*iter)(t_complex zk, t_complex c), t_env *env);

int 		set_constant(t_env *env, char *id);



t_env		*init_env();


#endif