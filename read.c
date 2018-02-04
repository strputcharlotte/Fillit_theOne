/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:30:11 by emoreau           #+#    #+#             */
/*   Updated: 2018/01/29 16:33:31 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

char	*ft_read(char **argv)
{
	int fd;
	int ret;
	char *str2;
	char str[BUFF_SIZE + 1];

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error_exit("File doesn't exist", 100);
	ret = read(fd, str, BUFF_SIZE);
	str[ret] = 0;
	str2 = ft_strdup(str);
	return (str2);
}
