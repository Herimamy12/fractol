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

typedef struct s_data
{
	t_win	*win;
	t_img	*img;
}			t_data;

// 
// print && debug && print error
// 

// 
// check map error
// 

// 
// delete
// 

// 
// init && new && && create
// 

// 
// loop
// 

// 
// event
// 

// 
// render
// 

#endif
