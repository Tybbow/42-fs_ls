/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:16 by tiskow            #+#    #+#             */
/*   Updated: 2017/09/25 15:17:58 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_display_fi(LS **dlist, LS **ltmp)
{
	char 			*path;
	struct stat		statbuf;
	char			*testtime;
	DIR 			*dir;
	
	dir = opendir((*dlist)->name);
	path = ft_dirpath((dir) ? (*dlist)->name : ".", (*ltmp)->name);
	if (lstat(path, &statbuf) != -1)
	{
		ft_get_permissions(statbuf.st_mode);
		ft_decade(NULL, statbuf.st_nlink, (*dlist)->nlinkLen);
		ft_display_uidgid(statbuf, *dlist);
		ft_decade(NULL, statbuf.st_size, (*dlist)->sizeLen);
		testtime = ft_get_time(statbuf.st_mtime);
		ft_decade(testtime, 0, (*dlist)->mtimeLen);
		ft_strdel(&testtime);
		ft_putstr(" ");
		ft_putstr((*ltmp)->name);
		if (S_ISLNK(statbuf.st_mode))
			ft_display_rlink(path);
		ft_putendl("");
	}
	if (dir)
		closedir(dir);
	ft_strdel(&path);
}

void	ft_display_nol(LS **flist)
{
	LS	*tmp;
	
	tmp = *flist;
	while (tmp)
	{	
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}

}

void	ft_display_l(LS **flist, LS **dlist)
{
	LS	*tmp;

	tmp = *flist;
	if ((*dlist)->dirorfile && *flist)
	{
		ft_putstr("total ");
		ft_putnbr((*dlist)->Block);
		ft_putchar(10);	
	}
	while (tmp)
	{
		ft_display_fi(dlist, &tmp);
		tmp = tmp->next;
	}
}

void	ft_display_ls(LS **flist, LS **dlist, size_t dis, size_t tour)
{
	if ((dis && (*dlist)->dirorfile) || (opt_R && tour && (*dlist)->dirorfile))
	{
		ft_putstr((*dlist)->name);
		ft_putendl(":");
	}
	if (!opt_l)
		ft_display_nol(flist);
	else
		ft_display_l(flist, dlist);
}

