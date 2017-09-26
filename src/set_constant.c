
#include "./inc/fractol.h"
#include "../lib/libft/libft.h"


int 		set_constant(t_env *env, char *id)
{
	t_complex	c;


	c.re = 0;
	c.im = 0;
	if (ft_strcmp(id, "julia") == 0)
	{

		/* 
		** constants for the quadratic julia set
		** c = 1j              # dentrite fractal
		** c = -0.123 + 0.745j # douady's rabbit fractal
		** c = -0.750 + 0j     # san marco fractal
		** c = -0.391 - 0.587j # siegel disk fractal
		** c = -0.7 - 0.3j     # NEAT cauliflower thingy
		** c = -0.75 - 0.2j    # galaxies
		** c = -0.75 + 0.15j   # groovy
		** c = -0.7 + 0.35j    # frost
		*/
		c.re = -0.75;
		c.im = -0.2;
	}
	else if (ft_strcmp(id, "sinjulia") == 0)
	{
		/* 
		** constants for the sin julia set
		** c = 1.0 + 0.1j          # electric christmas tree tops
		*/
		c.re = 1.0;
		c.im = 0.1;
	}
	else if (ft_strcmp(id, "cosjulia") == 0)
	{
		/* 
		** constants for the cos julia set
		** c = 1.0 - 0.5j        # probably has good colors
		** c = pi/2*(1.0 + 0.6j) # sort of cool - dendrites
		** c = pi/2*(1.0 + 0.4j) # same deal 
		** c = pi/2*(2.0 + 0.25j)  # fuzzy spots
		** c = pi/2*(1.5 + 0.05j)  # batlef
		*/
		c.re = 1.0;
		c.im = -0.5;
	}	
	else if (ft_strcmp(id, "burningship") == 0)
	{
		/* 
		** constants for the quadratic julia set
		** c = 1j              # dentrite fractal
		** c = -0.123 + 0.745j # douady's rabbit fractal
		** c = -0.750 + 0j     # san marco fractal
		** c = -0.391 - 0.587j # siegel disk fractal
		** c = -0.7 - 0.3j     # NEAT cauliflower thingy
		** c = -0.75 - 0.2j    # galaxies
		** c = -0.75 + 0.15j   # groovy
		** c = -0.7 + 0.35j    # frost
		*/
		c.re = -0.75;
		c.im = -0.2;
	}
	env->c = c;
	return (1);

}