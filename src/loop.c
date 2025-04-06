#include "../include/fractol.h"

void	loop(t_data *data)
{
	draw(data);
	mlx_hook(data->win->win, 02, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win->win, 17, 0, &to_close, data);
	mlx_loop(data->win->ptr);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		close_window(data, 0);
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
