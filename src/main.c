
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include "./inc/fractol.h"

int     main(int argc, char **argv)
{
    void    *mlx;
    void    *win;
    void    *img;
    char    **data_addr;

    if (argc != 2)
    {
        ft_putstr("Usage: ./fractol [set_identifier]\n");
        return (0);
    }
    mlx = mlx_init();
    win = mlx_new_window(mlx, DIM_X, DIM_Y, "Fractol");
    img = mlx_image_new(mlx, win, DIM_X, DIM_Y);

    // fill image with fractal and put to screen

    mlx_loop();

    return (0);
}