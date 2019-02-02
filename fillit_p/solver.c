/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:11:18 by zcadwyl           #+#    #+#             */
/*   Updated: 2019/02/02 18:44:20 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include "fillit.h"

int		solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	char		*ttrno;

	if (list == NULL)
		return (1);
	y = 0;
	ttrno = (char*)(list->content);
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (place(ttrno, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(ttrno, map, y * map->size + x, '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_map	*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = high_sqrt(ft_lstcount(list) * 4);
	map = map_new(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}
