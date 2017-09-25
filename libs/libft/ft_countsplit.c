/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:17:19 by tiskow            #+#    #+#             */
/*   Updated: 2016/12/03 17:20:03 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countsplit(char const *str, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strclen(&str[i], c))
			count++;
		i += ft_strclen(&str[i], c) ? ft_strclen(&str[i], c) : 1;
	}
	return (count);
}
