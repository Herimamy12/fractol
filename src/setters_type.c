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

int	set_julia(t_data *data, char **argv)
{
	data->bonus = 1;
	if (data->type == 1 || data->type == 3)
	{
		data->c_re = 0.0;
		data->c_im = 0.0;
		if (data->type == 3)
			data->bonus = -1;
		return (1);
	}
	if (invalid_number(argv[2]) || invalid_number(argv[3]))
		return (0);
	data->c_re = ft_atol(argv[2]);
	data->c_im = ft_atol(argv[3]);
	return (1);
}

int	invalid_number(char *nptr)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	if (!nptr || !*nptr || nptr[i] == '.')
		return (help_n(), 1);
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]) || (!comma && nptr[i] == '.'))
	{
		if (!comma && nptr[i] == '.')
			comma = 1;
		i++;
	}
	if (nptr[i] || nptr[--i] == '.')
		return (help_n(), 1);
	return (0);
}

int	set_type(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
		return (help(), 0);
	if (ft_strcmp(argv[1], "Mandelbrot") && ft_strcmp(argv[1], "Julia")
		&& ft_strcmp(argv[1], "Tricorn"))
		return (help(), 0);
	if (!ft_strcmp(argv[1], "Tricorn") && argc != 2)
		return (help(), 0);
	else if (!ft_strcmp(argv[1], "Mandelbrot") && argc != 2)
		return (help(), 0);
	else if (!ft_strcmp(argv[1], "Julia") && argc != 4)
		return (help(), 0);
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		return (1);
	if (!ft_strcmp(argv[1], "Julia"))
		return (2);
	return (3);
}
