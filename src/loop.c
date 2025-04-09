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

#include "../include/fractol.h"

void	loop(t_data *data)
{
	mlx_hook(data->win->win, 02, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win->win, 17, 0, &to_close, data);
	mlx_mouse_hook(data->win->win, &mouse_hook, data);
	mlx_loop_hook(data->win->ptr, &render, data);
	mlx_loop(data->win->ptr);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		close_window(data, 0);
	else if (key == XK_Left)
		data->x_start -= SHIFT * data->x_area;
	else if (key == XK_Right)
		data->x_start += SHIFT * data->x_area;
	return (0);
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
	if (data->flg->zoom_in)
		zoom("IN", data, 640, 360);
	if (data->flg->zoom_out)
		zoom("OUT", data, 640, 360);
	draw(data);
	data->flg->zoom_in = 0;
	data->flg->zoom_out = 0;
	return (0);
}
