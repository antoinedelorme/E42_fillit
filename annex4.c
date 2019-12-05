#include "fillit.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>


int	find_pos(int pos)
{
	pos++;
	return (pos);
}

void clean_tableau(char *tab, int size, char *letters)
{
	int	i;

	i = -1;
	while (++i < size * size)
		ft_memcpy(tab + i * CHAR, letters , CHAR);
}

char *gen_tableau(t_liste solution, int size)
{
	int i;
	int j;
	int k;
	char *tableau;
	char *letters;
	
	tableau = (char*)ft_memalloc(size * size * sizeof(char) * CHAR);
	letters = LETTERS;	
	clean_tableau(tableau, size, letters);
	i = -1;
	while (++i < solution.nb)
	{
		k = -1;
		while (++k < solution.pieces[i].lenght)
		{
			j = -1;
			while (++j < solution.pieces[i].width)
				ft_memmove(tableau + CHAR * ((solution.pieces[i].pos_sol/size + k)*size + solution.pieces[i].pos_sol%size + j), solution.pieces[i].data_compressed[j + k* solution.pieces[i].width] ? letters + (i + 1) * CHAR : tableau + CHAR * ((solution.pieces[i].pos_sol/size + k)*size + solution.pieces[i].pos_sol%size + j), CHAR);
		}
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
	ft_strdel(&tableau);
}

