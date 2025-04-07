#include "../include/fractol.h"

t_data	*new_data(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (p_error("Alloc t_data error\n"), NULL);
	data->fract_type = set_type(argc, argv);
	if (!data->fract_type)
		return (destroy_data(data), NULL);
	data->win = new_win();
	data->img = new_img(data->win);
	data->pnt = new_pnt(data->fract_type, argv);
	return (data);
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

/*
	For now let this function like that
	Don't forget to remove the (type == 2) in if statement next time
	It's work with Mandelbrot only for now
*/
t_pnt	*new_pnt(int type, char **argv)
{
	t_pnt	*pnt;

	pnt = ft_calloc(sizeof(t_pnt), 1);
	if (!pnt)
		return (p_error("Alloc point error\n"), NULL);
	if (type == 1 || type == 2)
	{
		pnt->real = 0;
		pnt->img = 0;
	}
	return (pnt);
	(void)argv;
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
