/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 02:04:51 by tiskow            #+#    #+#             */
/*   Updated: 2016/12/17 04:45:54 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int i;
	int nbr;
	int negative;

	i = 0;
	nbr = 0;
	negative = 0;
	while ((nptr[i] == '\n') || (nptr[i] == '\t') || (nptr[i] == '\v') ||
			(nptr[i] == ' ') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		negative = (nptr[i++] == '-') ? 1 : 0;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	return (negative ? -nbr : nbr);
}
