
#include "../lib/libft/libft.h"
#include "./inc/fractol.h"

void	julia(char **data_addr)
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

    c.re = -0.7;
    c.im = -0.3;
	
    i = 0;
    while (i++ < WIDTH)
    {
        j = 0;
        while (j++ < HEIGHT)
        {
        
            z.re = ((float) i) / WIDTH * xwidth + x_min;
            z.im = ((float) j) / HEIGHT * yheight + y_min; 
            k = 0;
            while ( cabsv(z) < zabsmax && k++ < NITMAX)
            {
                z = quadratic_iterator(z, c);
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

    