/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:28:36 by nherimam          #+#    #+#             */
/*   Updated: 2025/03/04 10:28:39 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"

# define WIDTH 1280
# define HEIGTH 720

# define ITER_MAX 50
# define SHIFT 0.05
# define ZOOM_FACTOR 0.75

typedef struct s_win
{
	void	*ptr;
	void	*win;
}			t_win;

typedef struct s_img
{
	int		bpp;
	int		endian;
	int		line_length;
	void	*img;
	char	*addr;
}			t_img;

typedef struct s_flg
{
	int	shift_u;
	int	shift_d;
	int	shift_l;
	int	shift_r;
	int	zoom_in;
	int	zoom_out;
}		t_flg;

typedef struct s_mus
{
	int	x;
	int	y;
}		t_mus;

typedef struct s_data
{
	int		type;
	int		color;
	double	c_re;
	double	c_im;
	double	x_area;
	double	y_area;
	double	x_start;
	double	y_start;
	t_win	*win;
	t_img	*img;
	t_flg	*flg;
	t_mus	*mus;
}			t_data;

// 
// print && debug && print error
// 
void	help(void);
void	p_error(char *s);

// 
// check map error
// 

// 
// delete
// 
void	destroy_data(t_data *data);
void	delete_star(void **ptr);
void	delete_win(t_win *win);
void	delete_img(t_img *img, t_win *win);

// 
// init && new && && create
// 
t_data	*new_data(int argc, char **argv);
int		set_type(int argc, char **argv);
t_win	*new_win(void);
t_img	*new_img(t_win *win);
void	put_pixel_in_image(t_img *img, int x, int y, int color);
void	set_julia(t_data *data, char **argv);
t_flg	*new_flag(void);
t_mus	*new_mouse(void);

// 
// loop
// 
void	loop(t_data *data);
int		handle_keypress(int key, t_data *data);
void	close_window(t_data *data, int status);
int		to_close(t_data *data);

// 
// event
// 
int		mouse_hook(int scroll, int x, int y, t_data *data);
void	zoom(char *state, t_data *data, int mouse_x, int mouse_y);

// 
// render
// 
void	draw(t_data *data);
int		fractal_point(int x, int y, t_data *data);
int		render(t_data *data);

#endif
