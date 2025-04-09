/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:01:10 by nherimam          #+#    #+#             */
/*   Updated: 2025/04/09 13:01:11 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	get_sign(const char sign, int *value)
{
	if (sign == '-' || sign == '+')
	{
		if (sign == '-')
			*value = -1;
		return (1);
	}
	return (0);
}

static void	get_int(const char set, double *nbr)
{
	*nbr *= 10;
	*nbr += set - 48;
}

static void	get_decim(const char set, double *nbr, double *comma)
{
	*nbr += (set - 48) * *comma;
	*comma *= 0.1;
}

double	ft_atol(const char *nptr)
{
	int		sign;
	double	nbr;
	double	comma;

	nbr = 0;
	sign = 1;
	comma = 0;
	while (ft_iswhitespace(*nptr))
		nptr++;
	if (get_sign(*nptr, &sign))
		nptr++;
	if (!ft_isdigit(*nptr) && *nptr != '.')
		return (0);
	while (ft_isdigit(*nptr) || (*nptr == '.' && !comma))
	{
		if (!comma && *nptr == '.')
			comma = 0.1;
		else if (!comma)
			get_int(*nptr, &nbr);
		else
			get_decim(*nptr, &nbr, &comma);
		nptr++;
	}
	return (nbr * sign);
}
