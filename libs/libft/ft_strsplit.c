/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 06:38:56 by tiskow            #+#    #+#             */
/*   Updated: 2016/12/04 01:33:53 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *str, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	split = ft_memalloc(sizeof(split) * ft_countsplit(str, c) + 1);
	if (!split)
		return (NULL);
	while (str[i])
	{
		if (ft_strclen(&str[i], c))
			split[j++] = ft_strsub(str, i, ft_strclen(&str[i], c));
		i += ft_strclen(&str[i], c) ? ft_strclen(&str[i], c) : 1;
	}
	split[j] = NULL;
	return (split);
}
