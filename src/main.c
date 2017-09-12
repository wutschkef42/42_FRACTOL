
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include "./inc/fractol.h"
#include <stdio.h>
#include <math.h>

int     key_hook(int keycode, void *param)
{
    t_env *env;    
    
    printf("ESC code: %d\n", keycode);
    env = (t_env*)param;
    if (keycode == 53)
    {
        mlx_destroy_image(env->mlx, env->img);
        mlx_destroy_window(env->mlx, env->win);
    }
    return(keycode);
}

int     mouse_hook(int button, int x, int y, void *param)
{
    t_env *env;
    t_complex c;


    double zabsmax = 10.0;
    double x_min = -1.5;
    double x_max = 1.5;
    double y_min = -1.5;
    double y_max = 1.5;
    double xwidth = x_max - x_min;
    double yheight = y_max - y_min;
    

    c.re = ((float) x) / WIDTH * xwidth + x_min;
    c.im = ((float) y) / HEIGHT * yheight + y_min; 
    env = (t_env*)param;
    printf("x: %d, y: %d, button: %d\n", x, y, button);
    generate_fractal(env->fractal_name, &env->data_addr, c);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    return (0);

}

int     main(int argc, char **argv)
{
    t_env   *env;

    t_complex c;
    c.re = 0.1;
    c.im = 0.2; 
    env = malloc(sizeof(t_env));
    
    env->bpp = 32;
    env->sl = WIDTH; 
    env->ed = 1;
    env->fractal_name = argv[1];
    if (argc != 2)
    {
        print_man();
        return (1);
    }
    
    if (!(fractal_exists(argv[1])))
    {
        print_man();
        return (2);
    }

    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FRACTOL");
    env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
    env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->ed);
    generate_fractal(argv[1], &env->data_addr, c);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    mlx_key_hook(env->win, key_hook, (void*)(env));
    mlx_mouse_hook(env->win, mouse_hook, (void*)(env));
    mlx_loop(env->mlx); 


    return (0);
}
