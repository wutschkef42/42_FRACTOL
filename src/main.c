
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include "./inc/fractol.h"
#include <stdio.h>
#include <math.h>


int     main(int argc, char **argv)
{
    t_env   *env;

    if (argc != 2 || !(fractal_exists(argv[1])))
    {
        print_man();
        return (1);
    }


    env = init_env();
    env->fractal_name = argv[1];
    set_constant(env, argv[1]);

    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FRACTOL");
    env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
    env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->ed);
    generate_fractal(argv[1], env);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    mlx_key_hook(env->win, zoom_quadrant, (void*)(env));
    mlx_mouse_hook(env->win, mouse_hook, (void*)(env));
    mlx_loop(env->mlx); 


    return (0);
}
