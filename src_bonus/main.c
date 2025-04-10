/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:28:49 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/09 12:24:39 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = new_data(argc, argv);
	if (!data)
		return (1);
	loop(data);
	return (0);
}
