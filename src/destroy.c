#include "../include/fractol.h"

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	delete_img(data->img, data->win);
	delete_win(data->win);
	free (data);
}

void	delete_star(void **ptr)
{
	void	**tmp;

	if (!ptr)
		return ;
	tmp = ptr;
	while (*ptr)
		free(*ptr++);
	free(tmp);
}

void	delete_win(t_win *win)
{
	if (!win || !win->ptr || !win->win)
		return ;
	mlx_destroy_window(win->ptr, win->win);
	mlx_destroy_display(win->ptr);
	free(win->ptr);
	free(win);
}

void	delete_img(t_img *img, t_win *win)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(win->ptr, img->img);
	free (img);
}
