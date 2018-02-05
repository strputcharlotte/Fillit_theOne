/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:36:56 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/04 23:30:58 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 chaque # doit etre en contact avec un autre #
 une fois qu'on a verifié que le fichier est bon, on transforme les tetri en lettres
 puis on nettoie, ie on enleve les points en trop
 ensuite le parser extrait les tetros un par un et les envoie sous la forme d'un double tableau
 au solver. Le solver recoit donc un premier tetro, puis un deuxieme, etc.
*/

#include "includes.h"

int			error(char **tab)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (**tab)
	{
//		while (tab[y][x] == "." || tab[y][x] == "#") -> ne compile pas
		while (ft_strcmp(&tab[y][x], ".") || ft_strcmp(&tab[y][x], "#"))
			x++;
// tout ca sort du while sinon on ne rentre jamais dedans
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
//		return (-1); a supprimer
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

	while (**tab)
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

int		separe_tetro(char **tab)
{
	int		j;
	int		y;
	int 	cpt;
	t_tab	*new_tetro;

	j = 0;
	y = 0;
	cpt = 0;
	while (tab)
	{
		while (*tab[y] != '\n' && j < 4)
		{
			ft_strncpy(new_tetro->tab[j], tab[y], 4);
			y++;
			j++;
		}
		if (j != 0)
		{
			cpt++;
			new_tetro = new_tetro->next;
		}
		else
			y++;
		j = 0;
		if (cpt > 26 || cpt == 0)
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
