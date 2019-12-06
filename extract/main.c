#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

void display_tableau (int *tableau, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tableau[i * size + j])
				ft_putstr("🧮");
			else 
				ft_putstr("🧾");
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
	}
}
void find_solution(t_liste *entree)
{
	int size;
	int		**tableau;
	int		i;

	size = 8;
	
	 while (1)
	 {
		 i = 0;
		 tableau = (int**)ft_memalloc(sizeof(int*));
		 while (i < entree->nb)
		 	{
				 tableau[i] = (int*)ft_memalloc(size * size * sizeof(int));
				 display(entree->pieces + i);
				 printf("\n");
				 i++;
			}
			insert(tableau[0], entree->pieces[0], 0, size);
			display_tableau (tableau[0], size);
			return;
			if (found_solution(entree, 0, 0, tableau, size))
				return;
		 size++;
	 }
}
int main(int ac, char **av)
{
	t_piece liste[NB_MAX];
	t_liste entree;
	int size;
	int **tableau;
	
	entree.nb = 0;
	entree.pieces = liste;
	size = 4;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}

	if (read_file(av[1], &entree) == -1)
	{
		//exit;
		ft_putstr("error\n");
		return (0);
	}
	find_solution( &entree);
	
	return (1);
}




