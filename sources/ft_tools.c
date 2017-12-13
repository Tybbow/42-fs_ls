/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:24 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/13 13:32:31 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_checkopta(char *basename)
{
	if (g_opt_a || !(g_opt_a || basename[0] == '.'))
		return (1);
	return (0);
}

char	*ft_dirpath(char *path2, char *name)
{
	char	*tmp;

	tmp = ft_strjoin("/", name);
	path2 = ft_strjoin(path2, tmp);
	ft_strdel(&tmp);
	return (path2);
}

void	ft_decade(char *value, size_t valui, size_t lenght)
{
	size_t	i;
	int		y;

	y = 0;
	i = 0;
	if (!value)
	{
		value = ft_itoa(valui);
		y = 1;
	}
	while (i++ + ft_strlen(value) <= lenght)
		ft_putchar(' ');
	ft_putstr(value);
	if (y)
		ft_strdel(&value);
}

size_t	ft_uidgidlen(struct stat sb, int i)
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

LS		*ft_create_elem(char *name, time_t time, size_t dirorfile)
{
	LS *newe;

	newe = ft_memalloc(sizeof(LS));
	if (!newe)
		return (NULL);
	newe->name = ft_strdup(name);
	newe->mtime = time;
	newe->nlinklen = 0;
	newe->uidlen = 0;
	newe->gidlen = 0;
	newe->sizelen = 0;
	newe->mtimelen = 0;
	newe->namelen = 0;
	newe->dirorfile = dirorfile;
	newe->block = 0;
	newe->next = NULL;
	return (newe);
}
