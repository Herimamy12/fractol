/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:33:58 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/12 17:33:59 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	set_button_click(int btn_clk, t_data *data)
{
	if (btn_clk != 1)
		return ;
	data->flg->mouse_press = 1;
	if (data->flg->bt1_hover)
		data->flg->bt1_click = 1;
	else if (data->flg->bt2_hover)
		data->flg->bt2_click = 1;
	else if (data->flg->bt3_hover)
		data->flg->bt3_click = 1;
	else if (data->flg->bt4_hover)
		data->flg->bt4_click = 1;
	else if (data->flg->bt5_hover)
		data->flg->bt5_click = 1;
	else if (data->flg->bt6_hover)
		data->flg->bt6_click = 1;
	else if (data->flg->bt7_hover)
		data->flg->bt7_click = 1;
	if (data->flg->bt1_click || data->flg->bt2_click || data->flg->bt3_click
		|| data->flg->bt4_click || data->flg->bt5_click
		|| data->flg->bt6_click || data->flg->bt7_click)
		data->flg->click = 1;
}

void	btn_flag(t_data *data)
{
	if (!data->flg->mouse_press || !data->flg->click)
		return ;
	data->mus->x = 640;
	data->mus->y = 360;
	if (data->flg->bt1_click)
		data->x_color ++;
	if (data->flg->bt2_click && data->iter_mx < 999)
		data->iter_mx ++;
	if (data->flg->bt3_click && data->iter_mx > 11)
		data->iter_mx --;
	if (data->flg->bt4_click)
		zoom("IN", data);
	if (data->flg->bt5_click)
		zoom("OUT", data);
	if (data->flg->bt6_click)
		reset(data);
	if (data->flg->bt7_click)
		handle_keypress(XK_Escape, data);
}
