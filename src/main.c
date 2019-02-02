#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int main(int argc, char **argv)
{
	t_list *list;
	t_map *map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((list = read_input(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = solve(list);
	print_map(map);
	free_map(map);
	ft_lstdel(&list, del_ttrno);
	return (0);
}
