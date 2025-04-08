#include "../include/fractol.h"

void	loop(t_data *data)
{
	mlx_hook(data->win->win, 02, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win->win, 17, 0, &to_close, data);
	mlx_mouse_hook(data->win->win, &mouse_hook, data);
	mlx_loop_hook(data->win->ptr, &render, data);
	mlx_loop(data->win->ptr);
}

int	mouse_hook(int scroll, int x, int y, t_data *data)
{
	ft_printf("x :: %d\ny :: %d\nscroll :: %d\n", x, y, scroll);
	if (scroll == 4)
		ft_printf("Up\n");
	else if (scroll == 5)
		ft_printf("Down\n");
	return (0);
	(void)x;
	(void)y;
	(void)data;
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
	draw(data);
	return (0);
}
