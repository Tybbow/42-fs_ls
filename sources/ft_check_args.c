/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:56:42 by tiskow            #+#    #+#             */
/*   Updated: 2017/09/25 15:15:57 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_begin_argv(char *av, int *i, int dir)
{
	if (!ft_strcmp(av, "-") || !ft_strcmp(av, ""))
		dir = 1;
	if (av[0] != '-' && ft_strlen(av) > 1 && !dir)
		dir = 1;
	else if (av[0] == '-' && ft_strlen(av) > 1 && !dir)
	{
		dir = ft_check_opt(av);
		*i += dir;
	}
	else if (av[0] != '-' && ft_strlen(av) == 1 && !dir)
		dir = 1;
	return (dir);
}

int		ft_read_argv(LS **elist, LS **alist, LS **dlist, int j)
{
	if (*elist)
		ft_read_errors(*elist);
	j = j - 1;
	if (*alist)
	{
		ft_display_ls(alist, alist, 1, 1);
		ft_freelist(*alist);
		if (*dlist)
			ft_putchar(10);
		return (1);
	}
	if (j < 2 && !*alist)
	{
		if (!*dlist)
			*dlist = ft_addlist(*dlist, ".", NULL, 1);
		return (0);
	}
	return (1);
}

int		ft_check_noerr(LS **alist, LS **dlist, struct stat sb, char *name)
{
	DIR 	*pdir;
	int		j;

	j = 0;
	if ((S_ISDIR(sb.st_mode) || S_ISLNK(sb.st_mode)) && (pdir = opendir(name)))
	{
		*dlist = ft_addlist(*dlist, name, NULL, 1);
		closedir(pdir);
	}
	else
	{
		if ((pdir = opendir(name)) || !S_ISDIR(sb.st_mode))
		{
			*alist = ft_addlist(*alist, name, NULL, 0);
			if (opt_l)
				*alist = ft_updatelist(*alist, name, name);
		}
		else
		{
			ft_display_error(name);
			j = 1;
		}
	}
	return (j);
}

int		ft_check_argv(LS **elist, LS **alist, LS **dlist, char *name)
{
	struct	stat 	statbuf;
	int		j;

	j = 0;
	if (lstat(name, &statbuf) == -1)
	{
		*elist = ft_addlist(*elist, name, NULL, 999);
		j = 1;
	}
	else
		j = ft_check_noerr(alist, dlist, statbuf, name);
	return (j);
}

int		ft_init_ls(int ac, char **av, LS **ltmp)
{
	size_t dir;
	size_t j;
	int i;
	LS *alist;
	LS *elist;
	
	dir = 0;
	i = 1;
	j = 1;	
	alist = NULL;
	elist = NULL;

	while (i < ac)
	{
		dir = ft_begin_argv(av[i], &i, dir);
		if (dir && i < ac && j++)
		{
			if (ft_check_argv(&elist, &alist, ltmp, av[i]))
				j += 3;
		}
		i++;
	}
	return(ft_read_argv(&elist, &alist, ltmp, j)) ;
}
