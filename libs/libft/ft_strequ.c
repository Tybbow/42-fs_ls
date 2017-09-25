/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 05:47:06 by tiskow            #+#    #+#             */
/*   Updated: 2016/12/04 01:34:45 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *str1, const char *str2)
{
	if (str1 && str2)
		return (ft_strnequ(str1, str2, ft_strlen(str2) + 1));
	return (0);
}
