/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:56:42 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/13 13:48:15 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_begin_argv(char *av, int *i, int dir)
{
	size_t j;

	j = 1;
	if (!ft_strcmp(av, "-") || !ft_strcmp(av, ""))
		dir = 1;
	if (av[0] != '-' && ft_strlen(av) > 1 && !dir)
		dir = 1;
	else if (av[0] == '-' && ft_strlen(av) > 1 && !dir)
	{
		dir = ft_check_opt(av, j);
		*i += dir;
	}
	else if (av[0] != '-' && ft_strlen(av) == 1 && !dir)
		dir = 1;
	return (dir);
}

int		ft_read_argv(LS **elt, LS **alt, LS **dlt, int j)
{
	if (*elt)
		ft_read_errors(*elt);
	j = j - 1;
	if (*alt)
	{
		ft_display_ls(alt, alt, 1, 1);
		ft_freelt(*alt);
		if (*dlt)
			ft_putchar(10);
		return (1);
	}
	if (j < 2 && !*alt)
	{
		if (!*dlt)
			*dlt = ft_addlt(*dlt, ".", NULL, 1);
		return (0);
	}
	return (1);
}

int		ft_check_er(LS **alt, LS **dlt, struct stat sb, char *name)
{
	DIR		*pdir;
	int		j;

	j = 0;
	if ((S_ISDIR(sb.st_mode) || S_ISLNK(sb.st_mode)) && (pdir = opendir(name)))
	{
		*dlt = ft_addlt(*dlt, name, NULL, 1);
		closedir(pdir);
	}
	else
	{
		if ((pdir = opendir(name)) || !S_ISDIR(sb.st_mode))
		{
			*alt = ft_addlt(*alt, name, NULL, 0);
			if (g_opt_l)
				*alt = ft_updatelt(*alt, name, name);
		}
		else
		{
			ft_display_error(name);
			j = 1;
		}
	}
	return (j);
}

int		ft_check_argv(LS **elt, LS **alt, LS **dlt, char *name)
{
	struct stat	statbuf;
	int			j;

	j = 0;
	if (lstat(name, &statbuf) == -1)
	{
		*elt = ft_addlt(*elt, name, NULL, 999);
		j = 1;
	}
	else
		j = ft_check_er(alt, dlt, statbuf, name);
	return (j);
}

int		ft_init_ls(int ac, char **av, LS **ltmp)
{
	size_t	dir;
	size_t	j;
	int		i;
	LS		*alt;
	LS		*elt;

	dir = 0;
	i = 1;
	j = 1;
	alt = NULL;
	elt = NULL;
	while (i < ac)
	{
		dir = ft_begin_argv(av[i], &i, dir);
		if (dir && i < ac && j++)
		{
			if (ft_check_argv(&elt, &alt, ltmp, av[i]))
				j += 3;
		}
		i++;
	}
	return (ft_read_argv(&elt, &alt, ltmp, j));
}
