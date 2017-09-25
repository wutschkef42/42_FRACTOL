
#include "./inc/fractol.h"

int	colorize(int k)
{
	double relative_escape_time;

	relative_escape_time = ((float)k) / NITMAX;

	return ((int) START_COLOR * relative_escape_time);
}