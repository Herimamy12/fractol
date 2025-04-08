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
			div = fractal_point(x, y, data);
			data->color /= ++ div;
			if (-- div == ITER_MAX || !div)
				data->color = 0X0;
			put_pixel_in_image(data->img, x, y, data->color);
		}
	}
	mlx_put_image_to_window(data->win->ptr,
		data->win->win, data->img->img, 0, 0);
}

int	fractal_point(int x, int y, t_data *data)
{
	int		i;
	double	z_re;
	double	z_im;
	double	tmp;

	i = 0;
	z_re = (x / (double)WIDTH) * data->x_area - data->x_start;
	z_im = (y / (double)HEIGTH) * data->y_area - data->y_start;
	if (data->type == 1)
	{
		z_re = 0;
		z_im = 0;
		data->c_re = (x / (double)WIDTH) * data->x_area - data->x_start;
		data->c_im = (y / (double)HEIGTH) * data->y_area - data->y_start;
	}
	while (z_re * z_re + z_im * z_im < 4 && i < ITER_MAX && ++ i)
	{
		tmp = z_re * z_re - z_im * z_im + data->c_re;
		z_im = 2 * z_re * z_im + data->c_im;
		z_re = tmp;
	}
	return (i);
}
