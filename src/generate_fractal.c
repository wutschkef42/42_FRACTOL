
#include "./inc/fractol.h"
#include "../lib/libft/libft.h"

int	generate_fractal(char *id, t_env *env)
{
	if (ft_strcmp(id, "julia") == 0)
	{
		julia(&quadratic_iterator, env);
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
		julia(&sin_iterator, env);
	}
	else if (ft_strcmp(id, "cosjulia") == 0)
	{
		julia(&cos_iterator, env);
	}
	return (1);
}