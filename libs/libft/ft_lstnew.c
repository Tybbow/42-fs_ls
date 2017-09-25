/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 05:58:26 by tiskow            #+#    #+#             */
/*   Updated: 2016/11/21 01:15:15 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*ret;

	ret = ft_memalloc(sizeof(t_list));
	if (ret)
	{
		if (content)
		{
			ret->content_size = content_size;
			ret->content = ft_memalloc(content_size);
			ret->content = ft_memcpy(ret->content, content, content_size);
		}
		else
		{
			ret->content = NULL;
			ret->content_size = 0;
		}
	}
	return (ret);
}
