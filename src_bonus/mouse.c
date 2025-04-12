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
	hover_flag(x, y, data);
	if (!data->flg->mouse_press)
		return (1);
	if (x > WIDTH || y > HEIGTH || x < data->ssd->width || y < 0)
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

void	hover_flag(int x, int y, t_data *data)
{
	if (x < 155 || x > 243 || !data->ssd->width || !data->ssd->heigth)
		reset_hover_flag(data);
	else if (y > 183 && y < 205)
		data->flg->bt1_hover = 1;
	else if (y > 246 && y < 284)
		data->flg->bt2_hover = 1;
	else if (y > 306 && y < 343)
		data->flg->bt3_hover = 1;
	else if (y > 366 && y < 403)
		data->flg->bt4_hover = 1;
	else if (y > 423 && y < 450)
		data->flg->bt5_hover = 1;
	else if (y > 484 && y < 510)
		data->flg->bt6_hover = 1;
	else if (y > 544 && y < 570)
		data->flg->bt7_hover = 1;
	else
		reset_hover_flag(data);
	return ;
}

void	reset_hover_flag(t_data *data)
{
	data->flg->bt1_hover = 0;
	data->flg->bt2_hover = 0;
	data->flg->bt3_hover = 0;
	data->flg->bt4_hover = 0;
	data->flg->bt5_hover = 0;
	data->flg->bt6_hover = 0;
	data->flg->bt7_hover = 0;
}

int	mouse_release(int btn_clk, int x, int y, t_data *data)
{
	if (btn_clk != 1)
		return (1);
	data->flg->click = 0;
	data->flg->shift_l = 0;
	data->flg->shift_r = 0;
	data->flg->shift_u = 0;
	data->flg->shift_d = 0;
	data->flg->bt1_click = 0;
	data->flg->bt2_click = 0;
	data->flg->bt3_click = 0;
	data->flg->bt4_click = 0;
	data->flg->bt5_click = 0;
	data->flg->bt6_click = 0;
	data->flg->bt7_click = 0;
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
	if (btn_clk == 1 && x > data->ssd->width)
		data->flg->mouse_press = 1;
	set_button_click(btn_clk, data);
	data->mus->x = x;
	data->mus->y = y;
	return (0);
}
