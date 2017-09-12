
#include "./inc/fractol.h"
#include "../lib/libft/libft.h"

int	generate_fractal(char *id, char **data_addr)
{
	if (ft_strcmp(id, "julia") == 0)
	{
		julia(data_addr);
	}	
	else if (ft_strcmp(id, "mandelbrot") == 0)
	{
		mandelbrot(data_addr);
	}
	else
	{
		ft_putstr("Usage: ./fractol [fractal_name]\n\nAvailable fractals include:\n-> julia\n-> mandelbrot\n");
		return (-1);
	}
	return (1);
}