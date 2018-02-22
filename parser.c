/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:36:56 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/22 15:54:06 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 une fois qu'on a verifié que le fichier est bon, on transforme les tetri en lettres
 puis on nettoie, ie on enleve les points en trop
 ensuite le parser extrait les tetros un par un et les envoie sous la forme d'un double tableau
 au solver. Le solver recoit donc un premier tetro, puis un deuxieme, etc.
*/

/*
 *segfault dans separe tetro, boucle while (tab[y] != '\n')
*/

#include "includes.h"

int			error(char **tab)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (tab)
	{
		while (tab[y][x] == '.' || tab[y][x] == '#')
		{
			x++;
			if (tab[y][4] == '\n')
			{
				y++;
				x = 0;
				if (tab[y][x] == '\n')
					y++;
			}
			else
				return (-1);
			if (y > 129)
				return (-1);
		}
	}
	return (0);
}

int		comptchar(char **tab)
{
	int compt_diese;
	int compt_point;
	int x;
	int y;

	compt_diese = 0;
	compt_point = 0;
	x = 0;
	y = 0;

	while (tab)
	{
		if (tab[y][x] == '#')
			compt_diese++;
		if (tab[y][x] == '.')
			compt_point++;
		x++;
		if (tab[y][4] == '\n')
		{
			y++;
			x = 0;
		}
		if (tab[3][4]) // = "au moment ou on est a cet endroit, rentre dans la boucle"
		{
			if (compt_diese != 4 && compt_point != 12)
				return (-1);
			else
				return (0);
		}
	}
	return (0);
}

t_tab		*separe_tetro(char **tab)
{
	int		j;
	int		y;
	int		x;
	int 	cpt;
	t_tab	*new_tetro;

	j = 0;
	x = 0;
	y = 0;
	cpt = 0;
	if (!(new_tetro = (t_tab*)malloc(sizeof(t_tab))))
		return(NULL);
	while (tab)
	{
		while (tab[y][x] != '\n' && tab[y+1][0] != '\n')
		{
			ft_strncpy(new_tetro->tetro[j], tab[y], 4);
			y += 3;
			x += 4;
			j++;
		}
		if (j != 0)
			cpt++;
		y += 2;
		j = 0;
		if (cpt > 26 || cpt == 0)
			return (NULL);
	}
	return (new_tetro);
}

int		side_to_side(char **tab)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (tab)
	{
		if (tab[y][x] == '#')
		{
			if (tab[y-1][x] != '#' && tab[y][x-1] != '#' &&
					tab[y][x+1] != '#' && tab[y+1][x] != '#')
				return (-1);
		}
		x++;
		if (tab[y][4] == '\n')
		{
			y++;
			x = 0;
		}
		else
			return (-1);
	}
	return (0);
}

char	*ft_convletter(char *str)
{
	int i;
	int compt;
	char c;
	i = 0;
	compt = 0;
	c = 'A';
	while (str[i])
	{
		if (str[i] == '#')
		{
			str[i] = c;
			compt++;
		}
		if(compt == 4)
		{
			c++;
			compt = 0;
		}
		i++;
	}
	return (str);
}
