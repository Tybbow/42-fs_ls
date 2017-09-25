/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:37:24 by tiskow            #+#    #+#             */
/*   Updated: 2017/09/25 15:43:36 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_checkopta(char *basename)
{
	if (opt_a  || !(opt_a || basename[0] == '.'))
		return (1);
	return (0);
}

char	*ft_dirpath(char *path2, char *name)
{
	char 	*tmp;

	tmp = ft_strjoin("/", name);
	path2 = ft_strjoin(path2, tmp);
	ft_strdel(&tmp);
	return (path2);
}

void 	ft_decade(char *value, size_t valui, size_t lenght)
{
	size_t	i;
	int 	y;

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

LS	*ft_create_elem(char *name, time_t time, size_t dirorfile)
{
	LS *newElement;

	newElement = ft_memalloc(sizeof(LS));
	if (!newElement)
		return (NULL);
	newElement->name = ft_strdup(name);
	newElement->mtime = time;
	newElement->nlinkLen = 0;
	newElement->uidLen = 0;
	newElement->gidLen = 0;
	newElement->sizeLen = 0;
	newElement->mtimeLen = 0;
	newElement->nameLen = 0;
	newElement->dirorfile = dirorfile;
	newElement->Block = 0;
	newElement->next = NULL;
	return (newElement);
}