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
