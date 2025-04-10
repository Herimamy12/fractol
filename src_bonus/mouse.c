/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:23:56 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/10 10:23:57 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	mouse_move(int x, int y, t_data *data)
{
	if (!data->flg->mouse_press)
		return (1);
	if (x > WIDTH || y > HEIGTH || x < 268 || y < 0)
	{
		data->flg->mouse_press = 0;
		return (2);
	}
	data->x_start += (data->mus->x - x) / (double)HEIGTH * data->x_area;
	data->y_start += (data->mus->y - y) / (double)HEIGTH * data->y_area;
	data->mus->x = x;
	data->mus->y = y;
	return (0);
}

int	mouse_release(int btn_clk, int x, int y, t_data *data)
{
	if (btn_clk != 1)
		return (1);
	data->flg->shift_l = 0;
	data->flg->shift_r = 0;
	data->flg->shift_u = 0;
	data->flg->shift_d = 0;
	data->flg->mouse_press = 0;
	data->mus->x = x;
	data->mus->y = y;
	return (0);
}

int	mouse_press(int btn_clk, int x, int y, t_data *data)
{
	if (btn_clk == 4)
		data->flg->zoom_in = 1;
	if (btn_clk == 5)
		data->flg->zoom_out = 1;
	if (btn_clk == 1)
		data->flg->mouse_press = 1;
	data->mus->x = x;
	data->mus->y = y;
	return (0);
}
