/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:02:08 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/13 13:29:24 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_get_time(time_t timestamp)
{
	char			*resultime;
	static int		timenow;
	static time_t	*test;

	resultime = ft_strnew(13);
	if (!resultime)
		return (NULL);
	resultime = ft_strncpy(resultime, &ctime(&timestamp)[4], 7);
	timenow = time(test);
	if (((unsigned int)timestamp + 15778463 <= (unsigned int)timenow)
		|| ((timenow + 3600) <= timestamp))
	{
		ft_strncpy(&resultime[7], " ", 1);
		if (ft_strlen(ctime(&timestamp)) < 26)
			ft_strncat(resultime, &ctime(&timestamp)[20], 4);
		else
			ft_strncat(resultime, &ctime(&timestamp)[24], 5);
	}
	else
		ft_strncat(resultime, &ctime(&timestamp)[11], 5);
	return (resultime);
}

time_t	ft_get_time_len(char *av)
{
	struct stat		statbuf;

	if (lstat(av, &statbuf) != -1)
		return (statbuf.st_mtime);
	return (0);
}
