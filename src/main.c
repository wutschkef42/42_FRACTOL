
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include "./inc/fractol.h"
#include "../lib/complex_math/inc/complex_math.h"
#include <stdio.h>
#include <math.h>

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


    if (argc != 2)
    {
        ft_putstr("Usage: ./fractol [set_identifier]\n");
        return (0);
    }

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "FRACTOL");
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    data_addr = mlx_get_data_addr(img, &bpp, &sl, &ed);
    julia(&data_addr);
    // fill image with fractal and put to screen
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);

    return (0);
}
