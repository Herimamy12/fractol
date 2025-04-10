/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:25:05 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/09 12:25:07 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	help(void)
{
	p_error("How to use ??\n");
	p_error("You have two choices, like :\n");
	p_error("\t\t\t\t./fractol Tricorn\n");
	p_error("\t\t\t\t./fractol Mandelbrot\n");
	p_error("\t\t\t\t./fractol Julia real_number imaginary_number\n");
}

void	help_n(void)
{
	p_error("The number must be a number (positive or negative)\n");
	p_error("If you use a floating number, ");
	p_error("it must not start or end with a comma\n");
	p_error("Like :\n");
	p_error("\t0.000000\n");
	p_error("\t-0.000000\n");
}

void	p_error(char *s)
{
	while (*s)
		write(2, s++, 1);
}
