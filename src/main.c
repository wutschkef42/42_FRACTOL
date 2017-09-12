
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
    t_env   env;

    env.bpp = 32;
    env.sl = WIDTH; 
    env.ed = 1;

    if (argc != 2)
    {
        ft_putstr("Usage: ./fractol [fractal_name]\n");
        return (1);
    }
    
    if (!(fractal_exists(argv[1])))
    {
        print_man();
        return (2);
    }

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "FRACTOL");
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    data_addr = mlx_get_data_addr(img, &env.bpp, &env.sl, &env.ed);
    generate_fractal(argv[1], &data_addr);
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx); 
    return (0);
}
