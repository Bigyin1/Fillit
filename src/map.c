/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:10:56 by zcadwyl           #+#    #+#             */
/*   Updated: 2019/02/02 18:43:13 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		if (map->array[i] == NULL)
			ft_putstr("fail");
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		place(char *ttrno, t_map *map, int x, int y)
{
	int i;
	int new_x;
	int new_y;

	i = 1;
	if (map->array[y][x] != '.')
		return (0);
	while (++i < 5)
	{
		new_x = x;
		new_y = y;
		new_y += (ttrno[1] + ttrno[i]) / 4 - ttrno[1] / 4;
		new_x += (ttrno[1] + ttrno[i]) % 4 - ttrno[1] % 4;
		if (new_x >= map->size || new_y >= map->size ||
			map->array[new_y][new_x] != '.')
			return (0);
	}
	set_piece(ttrno, map, y * map->size + x, ttrno[0]);
	return (1);
}

void	set_piece(char *ttrno, t_map *map, int sum, char c)
{
	int i;
	int new_x;
	int new_y;
	int x;
	int y;

	y = sum / map->size;
	x = sum % map->size;
	i = 1;
	map->array[y][x] = c;
	while (++i < 5)
	{
		new_x = x;
		new_y = y;
		new_y += (ttrno[1] + ttrno[i]) / 4 - ttrno[1] / 4;
		new_x += (ttrno[1] + ttrno[i]) % 4 - ttrno[1] % 4;
		map->array[new_y][new_x] = c;
	}
}
