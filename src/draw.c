#include "../include/fractol.h"

void	draw(t_data *data)
{
	int	x = 0;
	int	y = 0;
	int	div;
	int	color = 0;

	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			// if (julia(x, y))
			// 	put_pixel_in_image(data->img, x, y, 0x0);
			// else
			// 	put_pixel_in_image(data->img, x, y, 0xFFF);

			// div = julia(x, y);
			div = mandelbrot(x, y);
			if (div > 255)
				div = div % 255;
			if (div == 0)
				div = 1;
			color = (0xAF / div << 16 | 0xC0 / div << 8 | 0xD0);
			put_pixel_in_image(data->img, x, y, color);

			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->win->ptr, data->win->win, data->img->img, 0, 0);
}

int	mandelbrot(double x, double y)
{
	int		iter = 0;
	int		iter_max = 5500;
	double	zx = 0;
	double	zy = 0;
	double	temp;

	double	x_complex = (x / (double)WIDTH) * 4 - 2;
	double	y_complex = (y / (double)HEIGTH) * 4 - 2;

	while (zx * zx + zy * zy < 4 && iter < iter_max)
	{
		temp = zx * zx - zy * zy + x_complex;
		zy = 2 * zx * zy + y_complex;
		zx = temp;
		iter++;
	}
	// if (iter == iter_max)
	// 	return 1;
	// return 0;
	return (iter);
}

int julia(double x, double y)
{
	int		iter = 0;
	int		iter_max = 1050;
	double	zx = (x / (double)WIDTH) * 4 - 2;
	double	zy = (y / (double)HEIGTH) * 4 - 2;
	double	temp;

	double	c_re = 0.285;
	double	c_im = 0.01;

	while (zx * zx + zy * zy < 4 && iter < iter_max)
	{
		temp = zx * zx - zy * zy + c_re;
		zy = 2 * zx * zy + c_im;
		zx = temp;
		iter++;
	}
	// if (iter == iter_max)
	// 	return 1;
	// return 0;
	return (iter);
}
