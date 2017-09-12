
#include "../lib/libft/libft.h"
#include "./inc/fractol.h"
#include <math.h>


/* 
** constants for the sin julia set
** c = 1.0 + 0.1j          # electric christmas tree tops
*/
void	sin_julia(char **data_addr)
{
	int	i;
	int j;
	int k;
	t_complex z;
	t_complex c;

	double zabsmax = 50.0;
    double x_min = -1.5;
    double x_max = 1.5;
    double y_min = -1.5;
    double y_max = 1.5;
    double xwidth = x_max - x_min;
    double yheight = y_max - y_min;

    c.re = 1.0;
    c.im = 0.1;
	
    i = 0;
    while (i++ < WIDTH)
    {
        j = 0;
        while (j++ < HEIGHT)
        {
        
            z.re = ((float) i) / WIDTH * xwidth + x_min;
            z.im = ((float) j) / HEIGHT * yheight + y_min; 
            k = 0;
            while ( fabs(z.im) < zabsmax && k++ < NITMAX)
            {
                z = sin_iterator(z, c);
            }
            if (k >= NITMAX)
            {
                plot_point(data_addr, HEIGHT, i, j, 0x00000000);
            }
            else
            {
                plot_point(data_addr, HEIGHT, i-1, j-1, colorize(k));
            }
        }
    }
}

    