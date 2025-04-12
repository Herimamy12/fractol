/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:24:28 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/09 12:24:30 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	loop(t_data *data)
{
	mlx_hook(data->win->win, 17, 0, &to_close, data);
	mlx_hook(data->win->win, 6, 1L << 6, &mouse_move, data);
	mlx_hook(data->win->win, 4, 1L << 2, &mouse_press, data);
	mlx_hook(data->win->win, 5, 1L << 3, &mouse_release, data);
	mlx_hook(data->win->win, 2, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win->win, 3, 1L << 1, &handle_keyrelease, data);
	mlx_loop_hook(data->win->ptr, &render, data);
	mlx_loop(data->win->ptr);
}

void	close_window(t_data *data, int status)
{
	destroy_data(data);
	exit(status);
}

int	to_close(t_data *data)
{
	return (handle_keypress(XK_Escape, data));
}

int	render(t_data *data)
{
	app_flag(data);
	draw(data);
	data->flg->zoom_in = 0;
	data->flg->zoom_out = 0;
	return (0);
}

void	app_flag(t_data *data)
{
	if (data->flg->zoom_in)
		zoom("IN", data);
	if (data->flg->zoom_out)
		zoom("OUT", data);
	if (data->flg->shift_d)
		data->y_start += SHIFT * data->y_area;
	if (data->flg->shift_l)
		data->x_start -= SHIFT * data->x_area;
	if (data->flg->shift_r)
		data->x_start += SHIFT * data->x_area;
	if (data->flg->shift_u)
		data->y_start -= SHIFT * data->y_area;
	btn_flag(data);
}
