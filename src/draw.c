#include "../include/fractol.h"

void	draw(t_data *data)
{
	int	x;
	int	y;
	int	div;

	y = -1;
	while (++ y < HEIGTH)
	{
		x = -1;
		while (++ x < WIDTH)
		{
			data->color = 0x3A3AFF;
			if (data->type == 1)
				div = mandelbrot(x, y, data);
			else
				div = julia(x, y, data);
			data->color /= ++ div;
			if (-- div == ITER_MAX || !div)
				data->color = 0X0;
			put_pixel_in_image(data->img, x, y, data->color);
		}
	}
	mlx_put_image_to_window(data->win->ptr, data->win->win, data->img->img, 0, 0);
}

int	fractal_point(int x, int y, t_data *data)
{
	int		i;
	double	z_re;
	double	z_im;
	double	tmp;

	i = 0;
	z_re = 0;
	z_im = 0;
	if (data->type == 1)
	{
		data->c_re = (x / (double)WIDTH) * 4 - 2;
		data->c_im = (y / (double)HEIGTH) * 4 - 2;
	}
	else
	{
		z_re = (x / (double)WIDTH) * 4 - 2;
		z_im = (y / (double)HEIGTH) * 4 - 2;
	}
	while (z_re * z_re + z_im * z_im < 4 && iter < ITER_MAX)
	{
		temp = z_re * z_re - z_im * z_im + data->c_re;
		z_im = 2 * z_re * z_im + data->c_im;
		z_re = temp;
	}
	return (i);
}

int	mandelbrot(double x, double y, t_data *data)
{
	int		iter;
	double	z_re;
	double	z_im;
	double	temp;

	iter = 0;
	z_re = 0;
	z_im = 0;
	data->c_re = (x / (double)WIDTH) * 4 - 2;
	data->c_im = (y / (double)HEIGTH) * 4 - 2;
	while (z_re * z_re + z_im * z_im < 4 && iter < ITER_MAX)
	{
		temp = z_re * z_re - z_im * z_im + data->c_re;
		z_im = 2 * z_re * z_im + data->c_im;
		z_re = temp;
		iter++;
	}
	return (iter);
}

int julia(double x, double y, t_data *data)
{
	int		iter;
	double	z_re;
	double	z_im;
	double	temp;

	iter = 0;
	z_re = (x / (double)WIDTH) * 4 - 2;
	z_im = (y / (double)HEIGTH) * 4 - 2;
	while (z_re * z_re + z_im * z_im < 4 && iter < ITER_MAX)
	{
		temp = z_re * z_re - z_im * z_im + data->c_re;
		z_im = 2 * z_re * z_im + data->c_im;
		z_re = temp;
		iter++;
	}
	return (iter);
}
