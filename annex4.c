#include "fillit.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>


int	find_pos(t_grille grille, int pos)
{
	pos++;
	//while (grille.tableaux[pos] && pos < grille.l * grille.l)
	//	pos++;
	return (pos);
}

char *gen_tableau(t_liste solution, int size)
{
	int i;
	int j;
	int k;
	char *tableau;
	char *letters;
	int W;
	int X;
	int Y;


	
	tableau = (char*)ft_memalloc(size * size * sizeof(char) * CHAR);
	letters = (char*)ft_memalloc(28 * sizeof(char) * CHAR);

	letters = LETTERS;
	
	i = 0;
	while (i < size * size)
	{
		ft_memcpy(tableau + i * CHAR , letters , CHAR);
		i++;
	}

		
	i = 0;
	while (i < solution.nb)
	{
		k = 0;
		W = solution.pieces[i].width;
				
		while (k < solution.pieces[i].lenght)
		{
			j = 0;
			while (j < solution.pieces[i].width)
			{
				X = solution.pieces[i].pos_sol%size + j;
				Y = solution.pieces[i].pos_sol/size + k;
				ft_memcpy(tableau + CHAR * (Y*size + X), solution.pieces[i].data_compressed[j + k*W] ? letters + (i + 1) * CHAR : tableau + CHAR * (Y*size + X), CHAR);
				//tableau[(Y*size + X) * CHAR] = solution.pieces[i].data_compressed[j + k*W] ?  letters[(i + 1) * CHAR] : tableau[(Y*size + X) * CHAR] ;
				j++;
			}
			k++;
		}
		i++;
	}
	return (tableau);
}

void affiche_solution(t_liste solution, int size)
{
	char i;
	int j;
	int k;
	char *tableau;
	
	tableau = gen_tableau(solution, size);
	i = 0;
		k = 0;
		while (k < size)
		{
			j = 0;
			while (j < size)
			{
				write(1, tableau + (j + k *size) * CHAR, CHAR);
				j++;
			}
			ft_putchar('\n');
			k++;
		}
		i++;
	
}

