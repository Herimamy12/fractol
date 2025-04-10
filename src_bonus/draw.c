/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:24:14 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/09 12:24:16 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	draw(t_data *data)
{
	int	x;
	int	y;
	int	div;

	y = 0;
	while (++ y < HEIGTH - 1)
	{
		x = 261;
		while (++ x < WIDTH - 1)
		{
			data->color = DEFAULT_COLOR * data->x_color;
			div = fractal_point(x, y, data);
			data->color /= ++ div;
			if (-- div == data->iter_mx || !div)
				data->color = 0x2D2D2D;
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
	x -= (WIDTH - HEIGTH + 261) / 2;
	z_re = (x / (double)HEIGTH) * data->x_area + data->x_start;
	z_im = (y / (double)HEIGTH) * data->y_area + data->y_start;
	if (data->type == 1 || data->type == 3)
	{
		z_re = 0;
		z_im = 0;
		data->c_re = (x / (double)HEIGTH) * data->x_area + data->x_start;
		data->c_im = (y / (double)HEIGTH) * data->y_area + data->y_start;
	}
	while (z_re * z_re + z_im * z_im < 4 && i < data->iter_mx && ++ i)
	{
		tmp = z_re * z_re - z_im * z_im + data->c_re;
		z_im = data->bonus * 2 * z_re * z_im + data->c_im;
		z_re = tmp;
	}
	return (i);
}
