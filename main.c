/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:50:35 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/05 19:55:06 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes.h"
#include <stdio.h>

void		ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		write(1, "\n",1);
		i++;
	}
}

int				main(int argc, char **argv)
{
	char **tab;
	char **test;
	char *str;
	int i;

	 i = 0;


	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	str = ft_read(argv);
	tab = ft_strsplit(str, '\n');
	test = call_fonctions(tab);
	ft_print_map(test);
	ft_print_map(ft_solver (tab, 0, str));
	return (0);
}
