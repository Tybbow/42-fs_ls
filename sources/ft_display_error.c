/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:00 by tiskow            #+#    #+#             */
/*   Updated: 2017/09/25 15:14:16 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_display_illegal(char c)
{
	ft_putstr_fd("/bin/ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd(10, 2);
	ft_putstr_fd("usage: ls [-alrRt] [file ...]", 2);
	ft_putchar_fd(10, 2);
	exit(1);
}

void		ft_display_error(const char *name)
{
	ft_putstr_fd("ls: ", 2);
	perror(name);
}

void    	ft_stat_error(char *name)
{
        static char *str;

        str = NULL;
        if (!ft_strcmp(name, ""))
        {
                perror("ls: fts_open");
                exit(1);
        }
        else
        {
                str = ft_strjoin("ls: ", name);
                perror(str);
                ft_memdel((void*)&str);
        }
}

void		ft_read_errors(LS *elist)
{
	struct	stat 	statbuf;

	while (elist)
	{
		lstat(elist->name, &statbuf);
		if (!ft_strcmp(elist->name, ""))
		{
			ft_stat_error(elist->name);
			exit(1);
		}
		if (!S_ISDIR(statbuf.st_mode))
			ft_stat_error(elist->name);
		else
			ft_display_error(elist->name);
		ft_freelistone(&elist);
	}
}

int			ft_check_opt(char *argv)
{
	size_t i;
	i = 1;
	if (!ft_strcmp(argv, "--"))
		return (1);
	if (argv[0] == '-')
	{
		while (i < ft_strlen(argv))
		{
			if (argv[i] == 'a')
				opt_a = 1;
			else if (argv[i] == 'l')
				opt_l = 1;
			else if (argv[i] == 'r')
				opt_r = 1;
			else if (argv[i] == 'R')
				opt_R = 1;
			else if (argv[i] == 't')
				opt_ti = 1;
			else if (argv[i] == '1')
				opt_1 = 1;
			else
				ft_display_illegal((int)argv[i]);
			i++;
		}
	}
	return (0);
}
