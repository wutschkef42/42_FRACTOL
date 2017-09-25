

#include "./inc/fractol.h"
#include "../lib/libft/libft.h"


void	mandelbrot(t_env *env)
{
	int	i;
	int j;
	int k;
	t_complex z;
    t_complex c;

	i = 0;
    while (i++ < WIDTH)
    {
        j = 0;
        while (j++ < HEIGHT)
        {

            z.re = 0;
            z.im = 0;
            c.re = ((float) i) / WIDTH * (env->x_max - env->x_min) + env->x_min;
            c.im = ((float) j) / HEIGHT * (env->y_max - env->y_min) + env->y_min; 
            k = 0;
            while ( cabsv(z) < env->zabsmax && k++ < env->nitmax)
            {
                z = quadratic_iterator(z, c);
            }
            if (k >= env->nitmax)
            {
                plot_point(&env->data_addr, HEIGHT, i, j, 0x00000000);
            }
            else
            {
                plot_point(&env->data_addr, HEIGHT, i-1, j-1, colorize(k));
            }
        }
    }
}

    