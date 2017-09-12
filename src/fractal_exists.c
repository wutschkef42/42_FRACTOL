
#include "../lib/libft/libft.h"

int 	fractal_exists(char *id)
{
	if (ft_strcmp(id, "julia") == 0 ||
		ft_strcmp(id, "mandelbrot") == 0)
		return (1);
	return (0);
}
