
#include "./inc/fractol.h"
#include "../lib/libft/libft.h"

int	generate_fractal(char *id, t_env *env)
{
	if (ft_strcmp(id, "julia") == 0)
	{
		quadratic_julia(env);
	}	
	else if (ft_strcmp(id, "mandelbrot") == 0)
	{
		mandelbrot(env);
	}
	else if (ft_strcmp(id, "burningship") == 0)
	{
		burningship(&env->data_addr);
	}
	else if (ft_strcmp(id, "sinjulia") == 0)
	{
		sin_julia(&env->data_addr);
	}
	else if (ft_strcmp(id, "cosjulia") == 0)
	{
		cos_julia(&env->data_addr);
	}
	return (1);
}