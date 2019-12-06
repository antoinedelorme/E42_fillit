/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:46:33 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/06 14:09:59 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

t_pos		find_pos(t_pos pos, int width)
{
	pos.y ++;
	if (pos.y == width)
		{
			pos.y = 0;
			(pos.x)++;
		}
	return (pos);
}

int		pos_compare(t_pos pos1, t_pos pos2)
{
	if ((pos1.x != pos2.x) || (pos1.y != pos2.y))
		return (0);
	return (1);
}

void	clean_tableau(char *tab, int size, char *letters)
{
	int	i;

	i = -1;
	while (++i < size * size)
		ft_memcpy(tab + i * CHAR, letters, CHAR);
}

int		gen_tableau(t_liste sol, int size, char **tab)
{
	int		i;
	int		j;
	int		k;
	char	*letters;

	if (!(*tab = (char*)ft_memalloc(size * size * sizeof(char) * CHAR)))
		return (-1);
	letters = LETTERS;
	clean_tableau(*tab, size, letters);
	i = -1;
	while (++i < sol.nb)
	{
		k = -1;
		printf("AFF piece: %i x: %i y: %i\n", i, sol.pieces[i].t_pos_sol.x, sol.pieces[i].t_pos_sol.y);
			
		while (++k < sol.pieces[i].lenght)
		{
			j = -1;
			while (++j < sol.pieces[i].width)
			{
				ft_memmove(*tab + CHAR * ((sol.pieces[i].t_pos_sol.x + k)
				* size + sol.pieces[i].t_pos_sol.y + j), sol.pieces[i].
				zip[j + k * sol.pieces[i].width] ? letters + (i + 1)
				* CHAR : *tab + CHAR * ((sol.pieces[i].t_pos_sol.x + k)
				* size + sol.pieces[i].t_pos_sol.y + j), CHAR);
			
			}
			
		// ft_memmove(*tab + CHAR * ((sol.pieces[i].pos_sol / size + k)
		// 		* size + sol.pieces[i].pos_sol % size + j), sol.pieces[i].
		// 		zip[j + k * sol.pieces[i].width] ? letters + (i + 1)
		// 		* CHAR : *tab + CHAR * ((sol.pieces[i].pos_sol / size + k)
		// 		* size + sol.pieces[i].pos_sol % size + j), CHAR);
		// 
		}
	}
	return (1);
}

int		affiche_solution(t_liste solution, int size)
{
	int		j;
	int		k;
	char	*tableau;

	printf("----------------  DISPLAY SOLUTION\n");
	tableau = NULL;
	if (!gen_tableau(solution, size, &tableau))
		return (-1);
	k = 0;
	while (k < size)
	{
		j = 0;
		while (j < size)
			write(1, tableau + ((j++) + k * size) * CHAR, CHAR);
		ft_putchar('\n');
		k++;
	}
	ft_strdel(&tableau);
	return (1);
}
