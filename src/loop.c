#include "../include/fractol.h"

int	mouse_hook(int how, t_data *data);

void	loop(t_data *data)
{
	mlx_hook(data->win->win, 02, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win->win, 17, 0, &to_close, data);
	mlx_mouse_hook(data->win->win, &mouse_hook, data);
	mlx_loop_hook(data->win->ptr, &render, data);
	mlx_loop(data->win->ptr);
}

int	mouse_hook(int how, t_data *data)
{
	if (data)
		ft_printf("data adress :: %p\n", data);
	if (data->x_area)
		ft_printf("data->x_area adress :: %p\n", data->x_area);
	if (how == 4)
		ft_printf("Up\n");
	else if (how == 5)
		ft_printf("Down\n");
	return (0);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		close_window(data, 0);
	if (key == XK_Up)
	{
		data->x_area -= ADD_AREA;
		data->y_area -= ADD_AREA;
		data->x_start += (ADD_AREA / 2);
		data->y_start += (ADD_AREA / 2);
	}
	else if (key == XK_Down)
	{
		data->x_area += ADD_AREA;
		data->y_area += ADD_AREA;
		data->x_start -= (ADD_AREA / 2);
		data->y_start -= (ADD_AREA / 2);
	}
	else if (key == XK_Left)
		data->x_start -= (ADD_AREA / 2);
	else if (key == XK_Right)
		data->x_start += (ADD_AREA / 2);
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
	// if (data->zoom_in && data->x_area > ADD_AREA && data->y_area > ADD_AREA)
	// {
	// 	data->x_area -= ADD_AREA;
	// 	data->y_area -= ADD_AREA;
	// 	data->x_start += (ADD_AREA / 2);
	// 	data->y_start += (ADD_AREA / 2);
	// }
	// if (data->zoom_out)
	// {
	// 	data->x_area += ADD_AREA;
	// 	data->y_area += ADD_AREA;
	// 	data->x_start -= (ADD_AREA / 2);
	// 	data->y_start -= (ADD_AREA / 2);
	// }
	draw(data);
	return (0);
}
