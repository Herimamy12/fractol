/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:48:30 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/10 15:48:31 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <sys/stat.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"

# define WIDTH 1280
# define HEIGTH 720

# define SHIFT 0.025
# define ZOOM_FACTOR 0.75
# define DEFAULT_COLOR 0x3A3AFF

typedef struct s_win
{
	void	*ptr;
	void	*win;
}			t_win;

typedef struct s_img
{
	int		bpp;
	int		width;
	int		heigth;
	int		endian;
	int		line_length;
	void	*img;
	char	*addr;
}			t_img;

typedef struct s_flg
{
	int	click;
	int	shift_u;
	int	shift_d;
	int	shift_l;
	int	shift_r;
	int	zoom_in;
	int	shift_sh;
	int	zoom_out;
	int	bt1_click;
	int	bt2_click;
	int	bt3_click;
	int	bt4_click;
	int	bt5_click;
	int	bt6_click;
	int	bt7_click;
	int	bt1_hover;
	int	bt2_hover;
	int	bt3_hover;
	int	bt4_hover;
	int	bt5_hover;
	int	bt6_hover;
	int	bt7_hover;
	int	mouse_press;
}		t_flg;

typedef struct s_mus
{
	int	x;
	int	y;
}		t_mus;

typedef struct s_ssd
{
	int	width;
	int	heigth;
}		t_ssd;

typedef struct s_ast
{
	t_img	*sid;
	t_img	*hov;
	t_img	*clk;
}			t_ast;

typedef struct s_data
{
	int		type;
	int		color;
	int		bonus;
	int		x_color;
	int		iter_mx;
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
	t_ast	*ast;
	t_ssd	*ssd;
}			t_data;

// 
// print && debug && print error
// 
void	help(void);
void	p_error(char *s);
void	help_n(void);

// 
// check parameters error
// 
int		invalid_number(char *nptr);

// 
// delete
// 
void	destroy_data(t_data *data);
void	delete_star(void **ptr);
void	delete_win(t_win *win);
void	delete_img(t_img *img, t_win *win);
void	delete_ast(t_ast *ast, t_win *win);

// 
// init && new && && create
// 
t_data	*new_data(int argc, char **argv);
int		set_type(int argc, char **argv);
t_win	*new_win(char *win_name);
t_img	*new_img(t_win *win);
void	put_pixel_in_image(t_img *img, int x, int y, int color);
int		set_julia(t_data *data, char **argv);
t_flg	*new_flag(void);
t_mus	*new_mouse(void);
int		get_texture_pixel(t_img *img, int x, int y);
t_img	*get_sidebar(t_data *data, char *name);
t_ssd	*new_sizeofside(void);
t_ast	*new_assets(t_data *data);

// 
// loop
// 
void	loop(t_data *data);
void	close_window(t_data *data, int status);
int		to_close(t_data *data);

// 
// event
// 
int		mouse_press(int scroll, int x, int y, t_data *data);
void	zoom(char *state, t_data *data);
int		handle_keyrelease(int key, t_data *data);
int		handle_keypress(int key, t_data *data);
void	set_shift_key(int key, t_data *data);
int		mouse_release(int btn_clk, int x, int y, t_data *data);
int		mouse_move(int x, int y, t_data *data);
void	reset(t_data *data);

// 
// render
// 
void	draw(t_data *data);
int		fractal_point(int x, int y, t_data *data);
int		render(t_data *data);
void	sidebar(t_data *data);
void	app_flag(t_data *data);
void	btn_flag(t_data *data);
void	hover_flag(int x, int y, t_data *data);
void	reset_hover_flag(t_data *data);
int		get_start(t_data *data);
void	hover(t_data *data);
void	set_button_click(int btn_clk, t_data *data);

#endif
