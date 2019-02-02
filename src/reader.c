/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:11:08 by zcadwyl           #+#    #+#             */
/*   Updated: 2019/02/02 18:46:46 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "fillit.h"

void	del_ttrno(void *ttrno, size_t len)
{
	ft_memdel(&ttrno);
	len++;
}

void	ttrno_to_vec(char *str, char *dst, char value)
{
	int i;
	int j;
	int low_ind;

	i = -1;
	j = 0;
	low_ind = -1;
	dst[0] = value;
	while (++i < 20)
	{
		if (str[i] == '#' && low_ind == -1)
		{
			dst[++j] = i - i / 5;
			low_ind = i;
		}
		else if (str[i] == '#')
		{
			dst[++j] = i - low_ind;
			dst[j] -= (i / 5 - low_ind / 5);
		}
	}
}

int		check_connection(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 3 || block == 4);
}

int		check_tetremino(char *str, int read_count)
{
	int i;
	int blocks;

	blocks = 0;
	i = 0;
	if (read_count == 21 && str[20] != '\n')
		return (0);
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (0);
			if (str[i] == '#' && ++blocks > 4)
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
		i++;
	}
	if (!check_connection(str))
		return (0);
	return (1);
}

t_list	*read_input(int fd)
{
	char	buf[21];
	int		count;
	t_list	*list;
	char	tetremino[5];
	char	curr_letter;

	list = NULL;
	curr_letter = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (!check_tetremino(buf, count))
		{
			ft_lstdel(&list, del_ttrno);
			return (0);
		}
		ttrno_to_vec(buf, tetremino, curr_letter++);
		ft_lstadd(&list, ft_lstnew(tetremino, sizeof(tetremino)));
		curr_letter = count == 20 ? 1 : curr_letter;
	}
	if (count != 0 || curr_letter != 1)
	{
		ft_lstdel(&list, del_ttrno);
		return (0);
	}
	return (list);
}
