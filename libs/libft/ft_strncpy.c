/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 07:48:39 by tiskow            #+#    #+#             */
/*   Updated: 2016/12/05 08:04:09 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	ft_memcpy(dest, src, n);
	if (ft_strlen(src) < n)
		ft_bzero(&dest[ft_strlen(dest)], (n - ft_strlen(dest)));
	return (dest);
}
