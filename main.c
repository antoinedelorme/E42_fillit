#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	t_piece liste[NB_MAX];
	int nb_piece;
	int size;
	
	nb_piece = 0;
	size = 4;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}

	if (read_file(av[1], liste, &nb_piece) == -1)
	{
		//exit;
		ft_putstr("error\n");
		return (0);
	}

	return (0);
	while (!found_solution(liste, nb_piece, size))
		size++;
	display(liste, nb_piece);
	ft_memdel((void **)&liste);
	//exit;
	return (0);
}
