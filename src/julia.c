
#include "../lib/libft/libft.h"
#include "./inc/fractol.h"


/* 
** constants for the quadratic julia set
** c = 1j              # dentrite fractal
** c = -0.123 + 0.745j # douady's rabbit fractal
** c = -0.750 + 0j     # san marco fractal
** c = -0.391 - 0.587j # siegel disk fractal
** c = -0.7 - 0.3j     # NEAT cauliflower thingy
** c = -0.75 - 0.2j    # galaxies
** c = -0.75 + 0.15j   # groovy
** c = -0.7 + 0.35j    # frost
*/
void	julia(t_complex (*iter)(t_complex zk, t_complex c), t_env *env)
{
	int	       i;
	int        j;
	int        k;
	t_complex  z;

    i = 0;
    while (i++ < WIDTH)
    {
        j = 0;
        while (j++ < HEIGHT)
        {
        
            z.re = ((float) i) / WIDTH * (env->x_max - env->x_min) + env->x_min;
            z.im = ((float) j) / HEIGHT * (env->y_max - env->y_min) + env->y_min; 
            k = 0;
            while ( cabsv(z) < env->zabsmax && k++ < env->nitmax)
            {
                z = iter(z, env->c);
                                     
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

    