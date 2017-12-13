/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:16 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/13 14:00:25 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_display_fi(LS **dlt, LS **ltmp)
{
	char			*path;
	struct stat		statbuf;
	char			*testtime;
	DIR				*dir;

	dir = opendir((*dlt)->name);
	path = ft_dirpath((dir) ? (*dlt)->name : ".", (*ltmp)->name);
	if (lstat(path, &statbuf) != -1)
	{
		ft_get_permissions(statbuf.st_mode);
		ft_decade(NULL, statbuf.st_nlink, (*dlt)->nlinklen);
		ft_display_uidgid(statbuf, *dlt);
		ft_decade(NULL, statbuf.st_size, (*dlt)->sizelen);
		testtime = ft_get_time(statbuf.st_mtime);
		ft_decade(testtime, 0, (*dlt)->mtimelen);
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

void	ft_display_nol(LS **flt)
{
	LS	*tmp;

	tmp = *flt;
	while (tmp)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

void	ft_display_l(LS **flt, LS **dlt)
{
	LS	*tmp;

	tmp = *flt;
	if ((*dlt)->dirorfile && *flt)
	{
		ft_putstr("total ");
		ft_putnbr((*dlt)->block);
		ft_putchar(10);
	}
	while (tmp)
	{
		ft_display_fi(dlt, &tmp);
		tmp = tmp->next;
	}
}

void	ft_display_ls(LS **flt, LS **dlt, size_t dis, size_t tour)
{
	if ((dis && (*dlt)->dirorfile) || (g_opt_re && tour && (*dlt)->dirorfile))
	{
		ft_putstr((*dlt)->name);
		ft_putendl(":");
	}
	if (!g_opt_l)
		ft_display_nol(flt);
	else
		ft_display_l(flt, dlt);
}
