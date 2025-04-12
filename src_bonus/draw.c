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
	sidebar(data);
	while (++ y < HEIGTH - 1)
	{
		x = data->ssd->width;
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

void	sidebar(t_data *data)
{
	int	i;
	int	y;
	int	pix;

	y = -1;
	while (++ y < data->ssd->heigth && y < HEIGTH)
	{
		i = -1;
		while (++ i < data->ssd->width && i < WIDTH)
		{
			pix = get_texture_pixel(data->ast->sid, i, y);
			put_pixel_in_image(data->img, i, y, pix);
		}
	}
	hover(data);
}

void	hover(t_data *data)
{
	int	x;
	int	y;
	int	end;
	int	pix;

	x = 150;
	y = get_start(data);
	if (!y)
		return ;
	end = y + 45;
	while (++ y < end)
	{
		x = 150;
		while (++ x < 248)
		{
			if (!data->flg->click)
				pix = get_texture_pixel(data->ast->hov, x, y);
			else
				pix = get_texture_pixel(data->ast->clk, x, y);
			put_pixel_in_image(data->img, x, y, pix);
		}
	}
}

int	get_start(t_data *data)
{
	if (data->flg->bt1_hover)
		return (180);
	if (data->flg->bt2_hover)
		return (243);
	if (data->flg->bt3_hover)
		return (303);
	if (data->flg->bt4_hover)
		return (363);
	if (data->flg->bt5_hover)
		return (420);
	if (data->flg->bt6_hover)
		return (481);
	if (data->flg->bt7_hover)
		return (543);
	return (0);
}

int	fractal_point(int x, int y, t_data *data)
{
	int		i;
	double	z_re;
	double	z_im;
	double	tmp;

	i = 0;
	x -= (WIDTH - HEIGTH + data->ssd->width) / 2;
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
