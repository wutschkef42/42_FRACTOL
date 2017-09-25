

#include "./inc/fractol.h"
#include <stdlib.h>

t_env   *init_env()
{
    t_env   *env;
    
    if (!(env = malloc(sizeof(t_env))))
        return (NULL);


    t_complex c;

    c.re = -0.7;
    c.im = -0.2;

    env->c = c;
    env->bpp = BPP;
    env->sl = WIDTH; 
    env->ed = ED;
    env->zabsmax = ZABSMAX;
    env->nitmax = NITMAX;
    env->scale = SCALE;
    env->x_min = X_MIN;
    env->x_max = X_MAX;
    env->y_min = Y_MIN;
    env->y_max = Y_MAX;    
    return (env);
}