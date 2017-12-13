/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolslist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:27 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/13 13:35:16 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

LS		*ft_addlt(LS *list, char *basename, char *path, size_t dirorfile)
{
	LS		*newe;
	char	*fullpath;

	fullpath = (!path) ? basename : path;
	newe = ft_create_elem(basename, ft_get_time_len(fullpath), dirorfile);
	if (!newe)
		return (NULL);
	if (!list)
		return (newe);
	if ((!g_opt_r && !g_opt_ti) || (dirorfile == 999))
		ft_sortstr(&list, &newe);
	else if (!g_opt_r && g_opt_ti)
		ft_sorttime(&list, &newe);
	else if (g_opt_r && !g_opt_ti)
		ft_sortstr_reverse(&list, &newe);
	else if (g_opt_r && g_opt_ti)
		ft_sorttime_reverse(&list, &newe);
	return (list);
}

LS		*ft_updatelt(LS *dlt, char *name, char *path)
{
	struct stat		statbuf;
	char			*timelen;

	timelen = NULL;
	if (lstat(path, &statbuf) != -1)
	{
		if (dlt->nlinklen < ft_intlen(statbuf.st_nlink))
			dlt->nlinklen = ft_intlen(statbuf.st_nlink);
		if (dlt->uidlen < ft_uidgidlen(statbuf, 0))
			dlt->uidlen = ft_uidgidlen(statbuf, 0);
		if (dlt->gidlen < ft_uidgidlen(statbuf, 1))
			dlt->gidlen = ft_uidgidlen(statbuf, 1);
		if (dlt->sizelen < ft_intlen(statbuf.st_size))
			dlt->sizelen = ft_intlen(statbuf.st_size);
		timelen = ft_get_time(statbuf.st_mtime);
		if (dlt->mtimelen < ft_strlen(timelen))
			dlt->mtimelen = ft_strlen(timelen);
		ft_strdel(&timelen);
		if (dlt->namelen < ft_strlen(name))
			dlt->namelen = ft_strlen(name);
		dlt->block += statbuf.st_blocks;
	}
	return (dlt);
}

void	ft_copylist(LS **dlt, LS **ltmp)
{
	LS *tmp2;
	LS *tmp3;

	tmp2 = *ltmp;
	tmp3 = *dlt;
	if (!*dlt)
		*dlt = *ltmp;
	else
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp3;
	}
	*dlt = *ltmp;
}

void	ft_freelt(LS *list)
{
	LS *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		ft_strdel(&tmp->name);
		ft_memdel((void*)&tmp);
	}
}

void	ft_freeltone(LS **dirlist)
{
	LS *tmp;

	tmp = *dirlist;
	if (*dirlist)
	{
		*dirlist = (*dirlist)->next;
		ft_strdel(&tmp->name);
		ft_memdel((void*)&tmp);
	}
}
