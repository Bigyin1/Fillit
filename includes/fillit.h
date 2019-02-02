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
void			set_piece(char *ttrno, t_map *map, int x, int y, char c);
t_map			*solve(t_list *list);
void			del_ttrno(void *, size_t);
#endif
