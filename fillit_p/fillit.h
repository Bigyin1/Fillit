/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:10:21 by zcadwyl           #+#    #+#             */
/*   Updated: 2019/02/02 18:44:42 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

t_list			*read_input(int fd);
void			print_map(t_map *map);
void			free_map(t_map *map);
t_map			*map_new(int size);
int				place(char *ttrno, t_map *map, int x, int y);
void			set_piece(char *ttrno, t_map *map, int sum, char c);
t_map			*solve(t_list *list);
void			del_ttrno(void *ttrno, size_t size);
#endif
