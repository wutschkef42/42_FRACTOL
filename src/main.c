
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
    if (keycode == 126)
    {

        env->scale = env->scale * 0.9;
        env->x_min = env->x_min * env->scale;
        env->x_max = env->x_max * env->scale;
        env->y_min = env->y_min * env->scale;
        env->y_max = env->y_max * env->scale;
        printf("ok\n");
        generate_fractal(env->fractal_name, &env->data_addr, env);
        mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    }
    if (keycode == 125)
    {

        env->scale = (env->scale * 1.1 >= 1 ? 1 : env->scale * 1.1);
        env->x_min = -2.0;
        env->x_max = 2.0;
        env->y_min = -2.0;
        env->y_max = 2.0;
        printf("ok\n");
        generate_fractal(env->fractal_name, &env->data_addr, env);
        mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    }
    return(keycode);


}

int     mouse_hook(int button, int x, int y, void *param)
{
    t_env *env;
    t_complex c;

    float xwidth;
    float yheight;

    env = (t_env*)param;
    
    xwidth = env->x_max - env->x_min;
    yheight = env->y_max - env->y_min;

    
    (env->c).re = ((float) x) / WIDTH * xwidth + env->x_min;
    (env->c).im = ((float) y) / HEIGHT * yheight + env->y_min; 
    printf("x: %d, y: %d, button: %d\n", x, y, button);
    generate_fractal(env->fractal_name, &env->data_addr, env);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    return (0);

}

int     main(int argc, char **argv)
{
    t_env   *env;

    t_complex c;
    c.re = -0.75;
    c.im = -0.2; 
    env = malloc(sizeof(t_env));
    
    env->c = c;
    env->bpp = 32;
    env->sl = WIDTH; 
    env->ed = 1;


    env->zabsmax = 10.0;
    env->scale = 1.0;
    env->x_min = -2.0;
    env->x_max = 2.0;
    env->y_min = -2.0;
    env->y_max = 2.0;



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
    generate_fractal(argv[1], &env->data_addr, env);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    mlx_key_hook(env->win, key_hook, (void*)(env));
    mlx_mouse_hook(env->win, mouse_hook, (void*)(env));
    mlx_loop(env->mlx); 


    return (0);
}
