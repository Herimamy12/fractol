/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:14:33 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/09 12:25:00 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

t_img	*new_img(t_win *win)
{
	t_img	*img;

	img = ft_calloc(sizeof(t_img), 1);
	if (!img)
		return (p_error("Alloc image error\n"), NULL);
	img->img = mlx_new_image(win->ptr, WIDTH, HEIGTH);
	if (!img->img)
		return (free(img), p_error("mlx new img error\n"), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (delete_img(img, win), p_error("Get data addr error\n"), NULL);
	return (img);
}

void	put_pixel_in_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_texture_pixel(t_img *img, int x, int y)
{
	int	pixel_index;

	if (x < 0 || x > img->width || y < 0 || y > img->heigth)
		return (0);
	pixel_index = (y * img->line_length + x * (img->bpp / 8));
	return (*(unsigned int *)(img->addr + pixel_index));
}

t_img	*get_sidebar(t_data *data, char *name)
{
	t_img	*sid;

	sid = ft_calloc(sizeof(t_img), 1);
	if (!sid)
		return (p_error("Alloc sidebar error\n"), NULL);
	sid->img = mlx_xpm_file_to_image(data->win->ptr,
			name, &sid->width, &sid->heigth);
	if (!sid->img)
	{
		data->ssd->width = 0;
		data->ssd->heigth = 0;
		return (sid);
	}
	sid->addr = mlx_get_data_addr(sid->img,
			&sid->bpp, &sid->line_length, &sid->endian);
	if (ft_strcmp(name, "./.assets/.sidebar.xpm"))
		return (sid);
	data->ssd->width = sid->width;
	data->ssd->heigth = sid->heigth;
	return (sid);
}
