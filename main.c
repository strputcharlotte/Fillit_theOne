/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:50:35 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/20 17:44:50 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes.h"
#include <stdio.h>

void		ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map)
	{
		ft_putstr(map[i]);
		write(1, "\n",1);
		i++;
	}
}

char		**call_fonctions(char **argv)
{
	char	c;
	int		cnt;
	char	**tetri;

	c = 'A';
	cnt = 4;
	while (cnt != 0)
	{
		if (error(argv) == -1)
			return (NULL);
		while (argv)
		{
			tetri = (char**)separe_tetro(argv);
			comptchar(tetri);
		}
		side_to_side(tetri);
		ft_convletter(*tetri);
		ft_print_map(tetri);
		c++;
		cnt--;
	}
	return (tetri);
}

int				main(int argc, char **argv)
{
	char **test;
	char **str;
	int i;

	i = 0;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	str = ft_read(argv, 4);
	test = call_fonctions((char**)str);
	ft_print_map(test);
//	ft_print_map(ft_solver (tab, 0, str));
	return (0);
}
