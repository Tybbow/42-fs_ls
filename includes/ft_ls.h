/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 08:00:24 by tiskow            #+#    #+#             */
/*   Updated: 2017/09/25 16:04:54 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LS t_ls

# include "../libs/libft/libft.h"
# include <stdio.h>
# include <time.h>
# include <sys/types.h>
# include <math.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>
# include <locale.h>
# include <langinfo.h>
# include <stdint.h>

// global var for options.
int		opt_a;
int		opt_l;
int		opt_r;
int		opt_R;
int		opt_ti;
int		opt_1;

// structure for list.
typedef struct 	s_ls	t_ls;

// structure for elems of list.
struct 			s_ls
{
	char 					*name;
	time_t					mtime;
	size_t					nlinkLen;
	size_t					uidLen;
	size_t					gidLen;
	size_t					sizeLen;
	size_t					mtimeLen;
	size_t					nameLen;
	size_t					Block;
	size_t					dirorfile;
	t_ls					*next;
};

// function ls
void	ft_start_ls(LS **list, size_t dis);
void	ft_read_dir(LS **dlist, LS **ltmp, size_t dis, size_t tour);
void	ft_corefiles(LS **ltmp, LS **dlist, LS **flist, DIR *currentdir);
void	ft_initopts();

//f unction check_argv
int		ft_begin_argv(char *av, int *i, int dir);
int		ft_read_argv(LS **elist, LS **alist, LS **dlist, int j);
int		ft_check_noerr(LS **alist, LS **dlist, struct stat sb, char *name);
int		ft_check_argv(LS **elist, LS **alist, LS **dlist, char *name);
int		ft_init_ls(int ac, char **av, LS **ltmp);

// function errors
void	ft_display_illegal(char c);
void	ft_display_error(const char *name);
void    ft_stat_error(char *name);
void	ft_read_errors(LS *elist);
int		ft_check_opt(char *argv);

// function display l
char	ft_get_file_type(mode_t m);
void	ft_get_permissions(mode_t m);
void	ft_display_uidgid(struct stat sb, LS *list);
void	ft_display_rlink( char *path);

// function display ls
void	ft_display_fi(LS **dlist, LS **ltmp);
void	ft_display_nol(LS **flist);
void	ft_display_l(LS **flist, LS **dlist);
void	ft_display_ls(LS **flist, LS **dlist, size_t dis, size_t tour);

// function sort list
int		ft_sortstr_reverse(LS **list, LS **newElem);
int		ft_sortstr(LS **list, LS **newElem);
int		ft_timecmp(time_t t1, time_t t2, char *name, char *next_name);
int		ft_sorttime(LS **list, LS **newElem);
int		ft_sorttime_reverse(LS **list, LS **newElem);

// function time
char 	*ft_get_time(time_t timestamp);
time_t 	ft_get_time_len(char *av);

// function with tools
int		ft_checkopta(char *basename);
char	*ft_dirpath(char *path2, char *name);
void 	ft_decade(char *value, size_t valui, size_t lenght);
size_t	ft_uidgidlen(struct stat sb, int i);
LS		*ft_create_elem(char *name, time_t time, size_t dirorfile);

// function with list tools
LS		*ft_addlist(LS *list, char *basename, char *path, size_t dirorfile);
LS		*ft_updatelist(LS *dlist, char *name, char *path);
void	ft_copylist(LS **dlist, LS **ltmp);
void	ft_freelist(LS *list);
void	ft_freelistone(LS **dirlist);
#endif
