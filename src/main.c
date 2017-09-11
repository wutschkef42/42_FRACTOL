
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include "./inc/fractol.h"
#include "../lib/complex_math/inc/complex_math.h"
#include <stdio.h>
#include <math.h>


void    plot_point(char **data_addr, int sl, int x, int y, int color)
{
    int     *addr;

    if (!data_addr)
        return ;
    addr = (int*)(*data_addr);
    *(addr + x + sl*y) = color;       
}   


int     main(int argc, char **argv)
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *data_addr;

    int i;
    int j;
    int k;

    int bpp = 32;
    int sl = WIDTH; 
    int ed = 1;

    t_complex z;
    t_complex c;

    double zabsmax = 10.0;
    double x_min = -1.5;
    double x_max = 1.5;
    double y_min = -1.5;
    double y_max = 1.5;
    double xwidth = x_max - x_min;
    double yheight = y_max - y_min;
 
    c.re = -0.75;
    c.im = -0.2;

    if (argc != 2)
    {
        ft_putstr("Usage: ./fractol [set_identifier]\n");
        return (0);
    }
    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "FRACTOL");
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    data_addr = mlx_get_data_addr(img, &bpp, &sl, &ed);

    i = 0;
    while (i++ < WIDTH)
    {
        j = 0;
        while (j++ < HEIGHT)
        {
            z.re = ((float) i) / WIDTH * xwidth + x_min;
            z.im = ((float) j) / HEIGHT * yheight + y_min; 
            printf("%f | %f\n", z.re, z.im);
            k = 0;
            while ( cabsv(z) < zabsmax && k++ < NITMAX)
            {
                z = julia_iterate(z, c);
            }
            if (k >= NITMAX)
            {
                plot_point(&data_addr, HEIGHT, i, j, 0x00ffffff);
            }
        }
    }

    // fill image with fractal and put to screen

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);

    return (0);
}
