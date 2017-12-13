/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 08:00:24 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/13 13:48:05 by tiskow           ###   ########.fr       */
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

typedef struct s_ls	t_ls;

int				g_opt_a;
int				g_opt_l;
int				g_opt_r;
int				g_opt_re;
int				g_opt_ti;
int				g_opt_1;

struct				s_ls
{
	char		*name;
	time_t		mtime;
	size_t		nlinklen;
	size_t		uidlen;
	size_t		gidlen;
	size_t		sizelen;
	size_t		mtimelen;
	size_t		namelen;
	size_t		block;
	size_t		dirorfile;
	t_ls		*next;
};

void				ft_start_ls(LS **list, size_t dis);
void				ft_read_dir(LS **dlt, LS **ltmp, size_t dis, size_t tr);
void				ft_corefiles(LS **ltmp, LS **dlt, LS **flt, DIR *curr);

int					ft_begin_argv(char *av, int *i, int dir);
int					ft_read_argv(LS **elt, LS **alt, LS **dlt, int j);
int					ft_check_er(LS **alt, LS **dlt, struct stat sb, char *name);
int					ft_check_argv(LS **elt, LS **alt, LS **dlt, char *name);
int					ft_init_ls(int ac, char **av, LS **ltmp);

void				ft_display_illegal(char c);
void				ft_display_error(const char *name);
void				ft_stat_error(char *name);
void				ft_read_errors(LS *elt);
int					ft_check_opt(char *argv, size_t i);

char				ft_get_file_type(mode_t m);
void				ft_get_permissions(mode_t m);
void				ft_display_uidgid(struct stat sb, LS *list);
void				ft_display_rlink(char *path);

void				ft_display_fi(LS **dlt, LS **ltmp);
void				ft_display_nol(LS **flt);
void				ft_display_l(LS **flt, LS **dlt);
void				ft_display_ls(LS **flt, LS **dlt, size_t dis, size_t tr);

int					ft_sortstr_reverse(LS **list, LS **newelem);
int					ft_sortstr(LS **list, LS **newelem);
int					ft_timecmp(time_t t1, time_t t2, char *name, char *nname);
int					ft_sorttime(LS **list, LS **newelem);
int					ft_sorttime_reverse(LS **list, LS **newelem);

char				*ft_get_time(time_t timestamp);
time_t				ft_get_time_len(char *av);

int					ft_checkopta(char *basename);
char				*ft_dirpath(char *path2, char *name);
void				ft_decade(char *value, size_t valui, size_t lenght);
size_t				ft_uidgidlen(struct stat sb, int i);
LS					*ft_create_elem(char *name, time_t time, size_t dorf);

LS					*ft_addlt(LS *list, char *bname, char *path, size_t dorf);
LS					*ft_updatelt(LS *dlt, char *name, char *path);
void				ft_copylist(LS **dlt, LS **ltmp);
void				ft_freelt(LS *list);
void				ft_freeltone(LS **dirlist);
#endif
