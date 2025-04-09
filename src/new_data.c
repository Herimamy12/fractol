/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:24:51 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/09 12:24:52 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_data	*new_data(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (p_error("Alloc t_data error\n"), NULL);
	data->type = set_type(argc, argv);
	if (!data->type || !set_julia(data, argv))
		return (destroy_data(data), NULL);
	data->win = new_win();
	data->img = new_img(data->win);
	data->flg = new_flag();
	data->mus = new_mouse();
	data->color = 0;
	data->x_area = 4.0;
	data->y_area = 4.0;
	data->x_start = -2.0;
	data->y_start = -2.0;
	return (data);
}

t_win	*new_win(void)
{
	t_win	*win;

	win = ft_calloc(sizeof(t_win), 1);
	if (!win)
		return (p_error("Alloc win struct error\n"), NULL);
	win->ptr = mlx_init();
	if (!win->ptr)
		return (delete_win(win), p_error("mlx init error\n"), NULL);
	win->win = mlx_new_window(win->ptr, WIDTH, HEIGTH, "ART FRACTAL");
	if (!win->win)
		return (delete_win(win), p_error("mlx new window error\n"), NULL);
	return (win);
}

t_flg	*new_flag(void)
{
	t_flg	*flg;

	flg = ft_calloc(sizeof(t_flg), 1);
	if (!flg)
		return (p_error("Alloc t_flg error\n"), NULL);
	flg->shift_d = 0;
	flg->shift_l = 0;
	flg->shift_r = 0;
	flg->shift_u = 0;
	flg->zoom_in = 0;
	flg->zoom_out = 0;
	return (flg);
}

t_mus	*new_mouse(void)
{
	t_mus	*mus;

	mus = ft_calloc(sizeof(t_mus), 1);
	if (!mus)
		return (p_error("Alloc t_mus error\n"), NULL);
	mus->x = 0;
	mus->y = 0;
	return (mus);
}
