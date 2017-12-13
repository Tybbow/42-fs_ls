/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:03 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/13 13:07:13 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_get_file_type(mode_t m)
{
	if (S_ISDIR(m))
		return ('d');
	if (S_ISBLK(m))
		return ('b');
	if (S_ISCHR(m))
		return ('c');
	if (S_ISFIFO(m))
		return ('p');
	if (S_ISLNK(m))
		return ('l');
	if (S_ISSOCK(m))
		return ('s');
	return ('-');
}

void	ft_get_permissions(mode_t m)
{
	ft_putchar(ft_get_file_type(m));
	ft_putchar((m & S_IRUSR) ? 'r' : '-');
	ft_putchar((m & S_IWUSR) ? 'w' : '-');
	if (m & S_ISUID)
		ft_putchar((m & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((m & S_IXUSR) ? 'x' : '-');
	ft_putchar((m & S_IRGRP) ? 'r' : '-');
	ft_putchar((m & S_IWGRP) ? 'w' : '-');
	if (m & S_ISGID)
		ft_putchar((m & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((m & S_IXGRP) ? 'x' : '-');
	ft_putchar((m & S_IROTH) ? 'r' : '-');
	ft_putchar((m & S_IWOTH) ? 'w' : '-');
	if (m & S_ISVTX)
		ft_putchar((m & S_IXOTH) ? 't' : 'T');
	else
		ft_putchar((m & S_IXOTH) ? 'x' : '-');
	ft_putchar(32);
}

void	ft_display_uidgid(struct stat sb, LS *list)
{
	struct passwd	*psswd;
	struct group	*grp;

	ft_putchar(32);
	if ((psswd = getpwuid(sb.st_uid)) != NULL)
		ft_putstr(psswd->pw_name);
	else
		ft_putnbr(sb.st_uid);
	ft_putchar(32);
	if ((grp = getgrgid(sb.st_gid)) != NULL)
		ft_decade(grp->gr_name, 0,
			list->gidlen + list->uidlen -
				((psswd) ? ft_strlen(psswd->pw_name) : ft_intlen(sb.st_uid)));
	else
		ft_decade(NULL, sb.st_gid,
			list->gidlen + list->uidlen -
				((psswd) ? ft_strlen(psswd->pw_name) : ft_intlen(sb.st_uid)));
	ft_putchar(32);
}

void	ft_display_rlink(char *path)
{
	char			*buf;

	buf = ft_strnew(256);
	if (buf)
	{
		readlink(path, buf, 256);
		ft_putstr(" -> ");
		ft_putstr(buf);
		ft_strdel(&buf);
	}
}
