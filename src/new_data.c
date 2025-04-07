#include "../include/fractol.h"

t_data	*new_data(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (p_error("Alloc t_data error\n"), NULL);
	data->type = set_type(argc, argv);
	if (!data->type)
		return (destroy_data(data), NULL);
	data->win = new_win();
	data->img = new_img(data->win);
	data->color = 0;
	data->z_re = 0;
	data->z_im = 0;
	data->c_re = 0;
	data->c_im = 0;
	set_julia(data, argv);
	return (data);
}

void	set_julia(t_data *data, char **argv)
{
	if (data->type == 1)
		return ;
	data->c_re = ft_atoi(argv[2]);
	data->c_im = ft_atoi(argv[3]);
}

int	set_type(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
		return (help(), 0);
	if (ft_strcmp(argv[1], "Mandelbrot") && ft_strcmp(argv[1], "Julia"))
		return (help(), 0);
	if (!ft_strcmp(argv[1], "Mandelbrot") && argc != 2)
		return (help(), 0);
	else if (!ft_strcmp(argv[1], "Julia") && argc != 4)
		return (help(), 0);
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		return (1);
	return (2);
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
