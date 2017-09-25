/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:15:49 by tiskow            #+#    #+#             */
/*   Updated: 2017/09/25 15:28:06 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

size_t		ft_uidgidlen(struct stat sb, int i)
{
	struct passwd	*psswd;
	struct group	*grp;

	if (!i)
	{
		if ((psswd = getpwuid(sb.st_uid)) != NULL)
			return (ft_strlen(psswd->pw_name));
		else
			return (ft_intlen(sb.st_uid));
	}
	else
	{
		if ((grp = getgrgid(sb.st_gid)) != NULL)
        	return (ft_strlen(grp->gr_name));
		else
			return (ft_intlen(sb.st_gid));
	}
}

size_t		ft_countlist(LS *list)
{
	LS 	*tmp;
	size_t		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}