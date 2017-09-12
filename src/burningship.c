
#include "../lib/libft/libft.h"
#include "./inc/fractol.h"
#include <math.h>


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
void	burningship(char **data_addr)
{
	int	i;
	int j;
	int k;
	t_complex z;
	t_complex c;

	double zabsmax = 10.0;
    double x_min = -1.5;
    double x_max = 1.5;
    double y_min = -1.5;
    double y_max = 1.5;
    double xwidth = x_max - x_min;
    double yheight = y_max - y_min;

    c.re = -0.3;
    c.im = 0.2;
	
    i = 0;
    while (i++ < WIDTH)
    {
        j = 0;
        while (j++ < HEIGHT)
        {
            z.re = fabs(((float) i) / WIDTH * xwidth + x_min);
            z.im = fabs(((float) j) / HEIGHT * yheight + y_min); 
            k = 0;
            while ( cabsv(z) < zabsmax && k++ < NITMAX)
            {
                z.re = fabs(z.re);
                z.im = fabs(z.im);
                z = quadratic_iterator(z, c);
            }
            if (k >= NITMAX)
            {
                plot_point(data_addr, HEIGHT, i-1, j-1, 0x00000000);
            }
            else
            {
                plot_point(data_addr, HEIGHT, i-1, j-1, colorize(k));
            }
        }
    }
}

    