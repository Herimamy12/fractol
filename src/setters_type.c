/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:27:53 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/09 12:27:54 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
