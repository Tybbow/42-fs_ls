/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:13:05 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/13 13:18:02 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_corefiles(LS **ltmp, LS **dlt, LS **flt, DIR *curr)
{
	char			*path;
	struct dirent	*ent;

	while ((ent = readdir(curr)) != NULL)
	{
		path = ft_dirpath((*dlt)->name, ent->d_name);
		if (ft_checkopta(ent->d_name))
		{
			*flt = ft_addlt(*flt, ent->d_name, path, 0);
			*dlt = ft_updatelt(*dlt, ent->d_name, path);
			if (ent->d_type == DT_DIR && g_opt_re &&
				((ft_strcmp(".", ent->d_name) &&
					(ft_strcmp("..", ent->d_name)))))
				*ltmp = ft_addlt(*ltmp, path, NULL, 1);
		}
		ft_strdel(&path);
	}
}

void	ft_read_dir(LS **dlt, LS **ltmp, size_t dis, size_t tour)
{
	DIR		*dir;
	LS		*flt;

	*ltmp = NULL;
	flt = NULL;
	dir = opendir((*dlt)->name);
	if (!dir)
	{
		ft_putstr((*dlt)->name);
		ft_putendl(":");
		ft_display_error((*dlt)->name);
	}
	else
	{
		ft_corefiles(ltmp, dlt, &flt, dir);
		closedir(dir);
		ft_display_ls(&flt, dlt, dis, tour);
		ft_freelt(flt);
	}
}

void	ft_start_ls(LS **ltmp, size_t dis)
{
	LS	*dlt;
	int	i;

	dlt = NULL;
	i = 0;
	while (dlt || *ltmp)
	{
		if (*ltmp)
			ft_copylist(&dlt, ltmp);
		if ((dlt || *ltmp) && i)
			ft_putchar(10);
		ft_read_dir(&dlt, ltmp, dis, i);
		ft_freeltone(&dlt);
		i++;
	}
}

int		main(int argc, char **argv)
{
	LS		*ltmp;
	size_t	dis;

	dis = 0;
	ltmp = NULL;
	g_opt_a = 0;
	g_opt_l = 0;
	g_opt_r = 0;
	g_opt_re = 0;
	g_opt_ti = 0;
	g_opt_1 = 0;
	dis = ft_init_ls(argc, argv, &ltmp);
	if (!ltmp)
		return (0);
	ft_start_ls(&ltmp, dis);
	return (0);
}
