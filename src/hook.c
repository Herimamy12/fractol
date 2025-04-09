#include "../include/fractol.h"

int	mouse_hook(int scroll, int x, int y, t_data *data)
{
	if (scroll == 4)
		data->flg->zoom_in = 1;
	if (scroll == 5)
		data->flg->zoom_out = 1;
	return (0);
	(void)x;
	(void)y;
}

void	zoom(char *state, t_data *data, int mouse_x, int mouse_y)
{
	double	zoom_factor;
	double	zoom_center_x;
	double	zoom_center_y;

	zoom_factor = 0.1;
	zoom_center_x = (mouse_x / (double)WIDTH) * data->x_area + data->x_start;
	zoom_center_y = (mouse_y / (double)HEIGTH) * data->y_area + data->y_start;
	if (!ft_strcmp(state, "IN"))
	{
		data->x_area *= (1 - zoom_factor);
		data->y_area *= (1 - zoom_factor);
		data->x_start = zoom_center_x - (mouse_x / (double)WIDTH) * data->x_area;
		data->y_start = zoom_center_y - (mouse_y / (double)HEIGTH) * data->y_area;
	}
	else if (!ft_strcmp(state, "OUT"))
	{
		data->x_area /= (1 - zoom_factor);
		data->y_area /= (1 - zoom_factor);
		data->x_start = zoom_center_x - (mouse_x / (double)WIDTH) * data->x_area;
		data->y_start = zoom_center_y - (mouse_y / (double)HEIGTH) * data->y_area;
	}
}
