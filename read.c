/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:30:11 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/20 18:04:58 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

char		**ft_read(char **str, int fd)
{
	int		ret;
	int		i;
	char	buff[BUFF_SIZE + 1];

	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && ret != '\n')
	{
		buff[ret] = '\0';
		ret++;
		if (str == NULL)
			*str = ft_strdup(buff);
		else
			*str = ft_strjoin(*str, buff);
	}
	return (str);
}
