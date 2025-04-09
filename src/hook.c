/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:24:21 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/09 12:24:22 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_hook(int scroll, int x, int y, t_data *data)
{
	if (scroll == 4)
		data->flg->zoom_in = 1;
	if (scroll == 5)
		data->flg->zoom_out = 1;
	data->mus->x = x;
	data->mus->y = y;
	return (0);
}

void	zoom(char *state, t_data *data, int ms_x, int ms_y)
{
	double	zoom_center_x;
	double	zoom_center_y;

	zoom_center_x = (ms_x / (double)WIDTH) * data->x_area + data->x_start;
	zoom_center_y = (ms_y / (double)HEIGTH) * data->y_area + data->y_start;
	if (!ft_strcmp(state, "IN"))
	{
		data->x_area *= ZOOM_FACTOR;
		data->y_area *= ZOOM_FACTOR;
		data->x_start = zoom_center_x - (ms_x / (double)WIDTH) * data->x_area;
		data->y_start = zoom_center_y - (ms_y / (double)HEIGTH) * data->y_area;
	}
	else if (!ft_strcmp(state, "OUT"))
	{
		data->x_area /= ZOOM_FACTOR;
		data->y_area /= ZOOM_FACTOR;
		data->x_start = zoom_center_x - (ms_x / (double)WIDTH) * data->x_area;
		data->y_start = zoom_center_y - (ms_y / (double)HEIGTH) * data->y_area;
	}
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		close_window(data, 0);
	if (key == XK_Left)
		data->flg->shift_l = 1;
	if (key == XK_Right)
		data->flg->shift_r = 1;
	if (key == XK_Up)
		data->flg->shift_u = 1;
	if (key == XK_Down)
		data->flg->shift_d = 1;
	return (0);
}

int	handle_keyrelease(int key, t_data *data)
{
	if (key == XK_Left)
		data->flg->shift_l = 0;
	if (key == XK_Right)
		data->flg->shift_r = 0;
	if (key == XK_Up)
		data->flg->shift_u = 0;
	if (key == XK_Down)
		data->flg->shift_d = 0;
	return (0);
}
