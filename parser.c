/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:36:56 by emoreau           #+#    #+#             */
/*   Updated: 2018/01/29 18:27:26 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 chaque # doit etre en contact avec un autre #
 une fois qu'on a verifié que le fichier est bon, on transforme les tetri en lettres
 puis on nettoie, ie on enleve les points en trop
 ensuite le parser extrait les tetros un par un et les envoie sous la forme d'un double tableau
 au solver. Le solver recoit donc un premier tetro, puis un deuxieme, etc.
*/

int			error(char **tab)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (**tab)
	{
		while (tab[y][x] == "." || tab[y][x] == "#")
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
		}
		if (y > 129)
			return (-1);
		return (-1);
	}
	return (0);
}

int		comptchar(char **tab)
{
	int compt_diese;
	int compt_point;
	int x;
	int y;

	compt_diese = 0
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
		if (tab[4][4])
		{
			if (compt_diese != 4 && compt_point != 12)
				return (-1);
			else
				return (0);
		}
	}
	return (0);
}
