#include "fillit.h"
#include <stdlib.h>
#include "libft.h"

int	find_next_pos(t_grille grille, int pos)
{
	pos++;
	while (grille.tableaux[pos] && pos < grille.size * grille.size)
		pos++;
	return (pos);
}

int *gen_tableau(t_liste solution, int size)
{
	int i;
	int j;
	int k;
	int *tableau;
	int W;
	int X;
	int Y;

letter[0] = L'🆙';
letter[1] = L'🆘';
letter[2] = L'🆚';
letter[3] = L'🈯';
letter[4] = L'🈳';
letter[5] = L'🈚';
letter[6] = L'🆙';
letter[7] = L'🆘';
letter[8] = L'🈳';
letter[9] = L'🈯';
letter[10] = L'🆗';
letter[11] = L'🆘';
letter[12] = L'🆚';
letter[13] = L'🈯';
letter[14] = L'🈳';
letter[15] = L'🈚';
letter[16] = L'🆙';
letter[17] = L'🆘';
letter[18] = L'🈳';
letter[19] = L'🈯';
letter[20] = L'🆗';
letter[21] = L'🆘';
letter[22] = L'🆚';
letter[23] = L'🈯';
letter[24] = L'🈳';
letter[25] = L'🈚';


	tableau = (int*)ft_memalloc(size * size * sizeof(int));
	i = 0;
	while (i < size * size)
	{
		tableau[i] = L'⬛';
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
				tableau[Y*size + X] = solution.pieces[i].data_compressed[j + k*W] ? letter[i] : tableau[Y*size + X] ;
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
	int *tableau;
	
	tableau = gen_tableau(solution, size);
	i = 0;
		k = 0;
		while (k < size)
		{
			j = 0;
			while (j < size)
			{
				ft_putchar(tableau[j + k *size]);
				j++;
			}
			ft_putchar('\n');
			k++;
		}
		i++;
	
}

