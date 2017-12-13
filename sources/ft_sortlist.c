/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:22 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/13 13:27:29 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_sortstr_reverse(LS **list, LS **newelem)
{
	LS	*tmp;
	LS	*swap;

	tmp = *list;
	while (tmp->next && ft_strcmp(tmp->next->name, (*newelem)->name) >= 0)
		tmp = tmp->next;
	if (ft_strcmp(tmp->name, (*newelem)->name) > 0)
	{
		swap = tmp->next;
		tmp->next = *newelem;
		(*newelem)->next = swap;
		return (0);
	}
	(*newelem)->next = *list;
	*list = *newelem;
	return (0);
}

int		ft_sortstr(LS **list, LS **newelem)
{
	LS	*tmp;
	LS	*swap;

	tmp = *list;
	while (tmp->next && ft_strcmp(tmp->next->name, (*newelem)->name) <= 0)
		tmp = tmp->next;
	if (ft_strcmp(tmp->name, (*newelem)->name) <= 0)
	{
		swap = tmp->next;
		tmp->next = *newelem;
		(*newelem)->next = swap;
		return (0);
	}
	(*newelem)->next = *list;
	*list = *newelem;
	return (0);
}

int		ft_timecmp(time_t t1, time_t t2, char *name, char *nname)
{
	int	str_cmp_res;

	if (t1 < t2)
		return (-1);
	if (t1 > t2)
		return (1);
	str_cmp_res = ft_strcmp(name, nname);
	return (str_cmp_res);
}

int		ft_sorttime(LS **list, LS **newelem)
{
	LS	*tmp;
	LS	*swap;

	tmp = *list;
	while (tmp->next
		&& ft_timecmp(tmp->next->mtime, (*newelem)->mtime,
		(*newelem)->name, tmp->next->name) > 0)
		tmp = tmp->next;
	if (ft_timecmp(tmp->mtime, (*newelem)->mtime,
		(*newelem)->name, tmp->name) > 0)
	{
		swap = tmp->next;
		tmp->next = (*newelem);
		(*newelem)->next = swap;
		return (0);
	}
	(*newelem)->next = *list;
	*list = (*newelem);
	return (0);
}

int		ft_sorttime_reverse(LS **list, LS **newelem)
{
	LS	*tmp;
	LS	*swap;

	tmp = *list;
	while (tmp->next
		&& ft_timecmp(tmp->next->mtime, (*newelem)->mtime,
		(*newelem)->name, tmp->next->name) < 0)
		tmp = tmp->next;
	if (ft_timecmp(tmp->mtime, (*newelem)->mtime,
		(*newelem)->name, tmp->name) < 0)
	{
		swap = tmp->next;
		tmp->next = *newelem;
		(*newelem)->next = swap;
		return (0);
	}
	(*newelem)->next = *list;
	*list = *newelem;
	return (0);
}
