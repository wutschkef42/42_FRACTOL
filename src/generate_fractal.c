
#include "./inc/fractol.h"
#include "../lib/libft/libft.h"

int	generate_fractal(char *id, char **data_addr, t_env *env)
{
	if (ft_strcmp(id, "julia") == 0)
	{
		quadratic_julia(data_addr, env);
	}	
	else if (ft_strcmp(id, "mandelbrot") == 0)
	{
		mandelbrot(data_addr);
	}
	else if (ft_strcmp(id, "burningship") == 0)
	{
		burningship(data_addr);
	}
	else if (ft_strcmp(id, "sinjulia") == 0)
	{
		sin_julia(data_addr);
	}
	else if (ft_strcmp(id, "cosjulia") == 0)
	{
		cos_julia(data_addr);
	}
	return (1);
}