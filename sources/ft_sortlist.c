/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:22 by tiskow            #+#    #+#             */
/*   Updated: 2017/09/25 15:20:58 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_sortstr_reverse(LS **list, LS **newElem)
{
	LS	*tmp;
	LS	*swap;

  	tmp = *list;
  	while (tmp->next && ft_strcmp(tmp->next->name, (*newElem)->name) >= 0)
    	tmp = tmp->next;
  	if (ft_strcmp(tmp->name, (*newElem)->name) > 0)
  	{
    	swap = tmp->next;
    	tmp->next = *newElem;
    	(*newElem)->next = swap;
    	return (0);
  	}
  	(*newElem)->next = *list;
  	*list = *newElem;
  	return (0);
}

int		ft_sortstr(LS **list, LS **newElem)
{
	LS	*tmp;
  	LS	*swap;

  	tmp = *list;
  	while (tmp->next && ft_strcmp(tmp->next->name, (*newElem)->name) <= 0)
    	tmp = tmp->next;
  	if (ft_strcmp(tmp->name, (*newElem)->name) <= 0)
  	{
    	swap = tmp->next;
    	tmp->next = *newElem;
    	(*newElem)->next = swap;
    	return (0);
  	}
  	(*newElem)->next = *list;
  	*list = *newElem;
	return (0);
}

int     ft_timecmp(time_t t1, time_t t2, char *name, char *next_name)
{
  int   str_cmp_res;
  
  if (t1 < t2)
    return (-1);
  if (t1 > t2)
    return (1);
  str_cmp_res = ft_strcmp(name, next_name);
  return (str_cmp_res);
}


int     ft_sorttime(LS **list, LS **newElem)
{
  	LS   *tmp;
  	LS   *swap;

  	tmp = *list;
  	while (tmp->next
    	     && ft_timecmp(tmp->next->mtime, (*newElem)->mtime, (*newElem)->name, tmp->next->name) > 0)
    tmp = tmp->next;
  	if (ft_timecmp(tmp->mtime, (*newElem)->mtime, (*newElem)->name, tmp->name) > 0)
  	{
    	swap = tmp->next;
    	tmp->next = (*newElem);
    	(*newElem)->next = swap;
    	return (0);
  	}
  	(*newElem)->next = *list;
  	*list = (*newElem);
  	return (0);
}

int		ft_sorttime_reverse(LS **list, LS **newElem)
{
	LS   *tmp;
	LS   *swap;

  	tmp = *list;
  	while (tmp->next
         && ft_timecmp(tmp->next->mtime, (*newElem)->mtime, (*newElem)->name, tmp->next->name) < 0)
    tmp = tmp->next;
  	if (ft_timecmp(tmp->mtime, (*newElem)->mtime, (*newElem)->name, tmp->name) < 0)
  	{
    	swap = tmp->next;
    	tmp->next = *newElem;
    	(*newElem)->next = swap;
    	return (0);
  	}
  	(*newElem)->next = *list;
  	*list = *newElem;
  	return (0);
}
