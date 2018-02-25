/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:50:35 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/25 20:31:39 by cfarjane         ###   ########.fr       */
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
		printf("test map\n");
		ft_putstr(map[i]);
		write(1, "\n",1);
		i++;
	}
}

char		**call_functions(char **argv)
{
	char	c;
	int		cnt;
	char	**tetri;
	char	*str;

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
		str = NULL;
		ft_strcpy(str, *tetri);
		check_piece(str);
		ft_convletter(str);
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
	printf("test 1\n");
	test = call_functions((char**)str);
	printf("test 2\n");
	ft_print_map(test);
	printf("%s\n", argv[1]);
//	ft_print_map(ft_solver (tab, 0, str));
	return (0);
}
