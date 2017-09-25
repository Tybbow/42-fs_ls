/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolslist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:27 by tiskow            #+#    #+#             */
/*   Updated: 2017/09/25 15:29:21 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

LS	*ft_addlist(LS *list, char *basename, char *path, size_t dirorfile)
{
	LS 		*newElement;
	char	*fullpath;

	fullpath = (!path) ? basename : path;
	newElement = ft_create_elem(basename, ft_get_time_len(fullpath), dirorfile);
	if (!newElement)
		return (NULL);
	if (!list)
		return (newElement);
	if ((!opt_r && !opt_ti) || (dirorfile == 999))
		ft_sortstr(&list, &newElement);
	else if (!opt_r && opt_ti)
		ft_sorttime(&list, &newElement);
	else if (opt_r && !opt_ti)
		ft_sortstr_reverse(&list, &newElement);
	else if (opt_r && opt_ti)
		ft_sorttime_reverse(&list, &newElement);
	return (list);
}

LS		*ft_updatelist(LS *dlist, char *name, char *path)
{
	struct stat		statbuf;
	char			*timeLen;

	timeLen = NULL;
	if (lstat(path, &statbuf) != -1)
	{
		if (dlist->nlinkLen < ft_intlen(statbuf.st_nlink))
			dlist->nlinkLen = ft_intlen(statbuf.st_nlink);
		if (dlist->uidLen < ft_uidgidlen(statbuf, 0))
			dlist->uidLen = ft_uidgidlen(statbuf, 0);
		if (dlist->gidLen < ft_uidgidlen(statbuf, 1))
			dlist->gidLen = ft_uidgidlen(statbuf, 1);
		if (dlist->sizeLen < ft_intlen(statbuf.st_size))
			dlist->sizeLen = ft_intlen(statbuf.st_size);
		timeLen = ft_get_time(statbuf.st_mtime);
		if (dlist->mtimeLen < ft_strlen(timeLen))
			dlist->mtimeLen = ft_strlen(timeLen);
		ft_strdel(&timeLen);
		if (dlist->nameLen < ft_strlen(name))
			dlist->nameLen = ft_strlen(name);
		dlist->Block += statbuf.st_blocks;
	}
	return (dlist);
}

void	ft_copylist(LS **dlist, LS **ltmp)
{
	LS *tmp2;
	LS *tmp3;
	
	tmp2 = *ltmp;
	tmp3 = *dlist;
	if (!*dlist)
		*dlist = *ltmp;
	else
	{
		while (tmp2->next)
			tmp2 = tmp2->next;	
		tmp2->next = tmp3;
	}
	*dlist = *ltmp;
}

void	ft_freelist(LS *list)
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

void	ft_freelistone(LS **dirlist)
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