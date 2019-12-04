#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int find_solution(t_liste *entree)
{
	t_grille grille;
	int		i;
	t_sol_vector	vector_sol;
	int	size;
	//int		vecteur_sol[NB_MAX];

	grille.size = 4;
	ft_memset((void*)vector_sol.sol, '\0', sizeof(int) * NB_MAX);
	 while (1)
	 {
		 i = 0;
		grille.tableaux = (int*)ft_memalloc(grille.size * grille.size * sizeof(int));
		vector_sol.current = 0;
		if ((size = found_solution(entree, 0, 0, grille)))
				return(size);
		ft_memdel((void**)&grille.tableaux);

		grille.size++;
		i++;
	}
		
	 
}
int main(int ac, char **av)
{
	t_piece liste[NB_MAX];
	t_liste entree;
	int size;
	
	entree.nb = 0;
	entree.pieces = liste;
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
	size = find_solution( &entree);
	affiche_solution(entree, size);
	return (1);
}




