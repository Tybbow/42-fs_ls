/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:13:05 by tiskow            #+#    #+#             */
/*   Updated: 2017/09/25 15:18:48 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_initopts()
{
	opt_a = 0;
	opt_l = 0;
	opt_r = 0;
	opt_R = 0;
	opt_ti = 0;
	opt_1 = 0;
}

void	ft_corefiles(LS **ltmp, LS **dlist, LS **flist, DIR *currentdir)
{
	char 		*path;
	struct dirent	*ent;
	
	while ((ent = readdir(currentdir)) != NULL)
	{
		path = ft_dirpath((*dlist)->name, ent->d_name);
		if (ft_checkopta(ent->d_name))
		{
			*flist = ft_addlist(*flist, ent->d_name, path, 0);
			*dlist = ft_updatelist(*dlist, ent->d_name, path);
			if (ent->d_type == DT_DIR && ent->d_seekoff > 2 && opt_R)
				*ltmp = ft_addlist(*ltmp, path, NULL, 1);	
		}
		ft_strdel(&path);
	}
}

void		ft_read_dir(LS **dlist, LS **ltmp, size_t dis, size_t tour)
{
	DIR		*dir;
	LS		*flist;
	
	*ltmp = NULL;
	flist = NULL;
	dir = opendir((*dlist)->name);
	if (!dir)
	{
		ft_putstr((*dlist)->name);
		ft_putendl(":");
		ft_display_error((*dlist)->name);
	}
	else
	{
		ft_corefiles(ltmp, dlist, &flist, dir);
		closedir(dir);
		ft_display_ls(&flist, dlist, dis, tour);
		ft_freelist(flist);
	}
}

void	ft_start_ls(LS **ltmp, size_t dis)
{
	LS 		*dlist;
	int		i;
	
	dlist = NULL;
	i = 0;
	while (dlist || *ltmp)
	{
		if (*ltmp)
			ft_copylist(&dlist, ltmp);
		if ((dlist || *ltmp) && i)
			ft_putchar(10);
		ft_read_dir(&dlist, ltmp, dis, i);
		ft_freelistone(&dlist);
		i++;
	}
}

int		main(int argc, char **argv)
{
	LS		*ltmp;
	size_t	dis;

	dis = 0;
	ltmp = NULL;
	ft_initopts();
	dis = ft_init_ls(argc, argv, &ltmp);
	if (!ltmp)
		return (0);
	ft_start_ls(&ltmp, dis);	
	return (0);
}