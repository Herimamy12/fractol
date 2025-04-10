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

#include "../include/fractol_bonus.h"

void	zoom(char *state, t_data *data)
{
	double	ms_x;
	double	ms_y;
	double	zoom_center_x;
	double	zoom_center_y;

	ms_y = data->mus->y;
	ms_x = data->mus->x - (WIDTH - HEIGTH + 268) / 2;
	zoom_center_x = (ms_x / (double)HEIGTH) * data->x_area + data->x_start;
	zoom_center_y = (ms_y / (double)HEIGTH) * data->y_area + data->y_start;
	if (!ft_strcmp(state, "IN"))
	{
		data->x_area *= ZOOM_FACTOR;
		data->y_area *= ZOOM_FACTOR;
		data->x_start = zoom_center_x - (ms_x / (double)HEIGTH) * data->x_area;
		data->y_start = zoom_center_y - (ms_y / (double)HEIGTH) * data->y_area;
	}
	else if (!ft_strcmp(state, "OUT"))
	{
		data->x_area /= ZOOM_FACTOR;
		data->y_area /= ZOOM_FACTOR;
		data->x_start = zoom_center_x - (ms_x / (double)HEIGTH) * data->x_area;
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
	if (key == XK_Shift_L)
		data->flg->shift_sh = 1;
	if (data->flg->shift_sh)
		set_shift_key(key, data);
	return (0);
}

void	set_shift_key(int key, t_data *data)
{
	if (key == XK_c)
		data->x_color += 5;
	if (key == XK_KP_Add && data->iter_mx < 999)
		data->iter_mx += 5;
	if (key == XK_KP_Subtract && data->iter_mx > 10)
		data->iter_mx -= 5;
	if (key == XK_r)
		reset(data);
}

void	reset(t_data *data)
{
	data->x_color = 1;
	data->iter_mx = 20;
	data->x_area = 4.0;
	data->y_area = 4.0;
	data->x_start = -2.0;
	data->y_start = -2.0;
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
	if (key == XK_Shift_L)
		data->flg->shift_sh = 0;
	return (0);
}
