
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include "./inc/fractol.h"


#include <stdio.h>

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
        generate_fractal(env->fractal_name, env);
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
        generate_fractal(env->fractal_name, env);
        mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    }
    return (keycode);


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
    generate_fractal(env->fractal_name, env);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    return (0);

}


/*
**  Press number keys 1 through for to zoom into respective quarants
**
**      1   |   2
**          |
**      ---------
**          |
**      3   |   4 
*/

int     zoom_quadrant(int keycode, void *param)
{
    t_env   *env;
    float   xwidth;
    float   yheight;

    env = (t_env*)param;    
    xwidth = env->x_max - env->x_min;
    yheight = env->y_max - env->y_min;
        
    // first quadrant, decrease y_max, decrease x_max
    if (keycode == 18)
    {
        env->x_max -= xwidth / 2;
        env->y_max -= yheight / 2;
    } 
    // second quadrant, decrease y_max, increase x_min
    else if (keycode == 19)
    {
        env->x_min = env->x_max - xwidth / 2;   
        env->y_max -= yheight / 2;  
    } 
    // third quadrant, increase y_min, decrease x_max
    else if (keycode == 20)
    {
        env->x_max -= xwidth / 2;
        env->y_min = env->y_max - yheight / 2; 
    } 
    // fourth quadrant, increase y_min, increase x_min
    else if (keycode == 21)
    {
        env->x_min = env->x_max - xwidth / 2;
        env->y_min = env->y_max - yheight / 2; 
    }
    env->nitmax += 20;
    printf("mitmax: %d\n", env->nitmax);
    generate_fractal(env->fractal_name, env);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    return (0);   
}