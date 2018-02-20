/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:33:57 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/20 18:04:54 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H
# define BUFF_SIZE 600
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct			s_tab
{
	char				tab[4][4];
	struct s_tab		*next;
}						t_tab;

char					**ft_read(char **str, int fd);
void					ft_print_map(char **map);
int						error(char **tab);
int						comptchar(char **tab);
t_tab					*separe_tetro(char **tab);
int						side_to_side(char **tab);
char					*ft_convletter(char *str);
char					**call_fonctions(char **argv);

#endif
