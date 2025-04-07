#include "../include/fractol.h"

void	help(void)
{
	p_error("How to use ??\n");
	p_error("You have two choice, like :\n");
	p_error("\t\t\t\t./fractol Mandelbrot\n");
	p_error("\t\t\t\t./fractol Julia real_number imaginary_number\n");
}

void	p_error(char *s)
{
	while (*s)
		write(2, s++, 1);
}
