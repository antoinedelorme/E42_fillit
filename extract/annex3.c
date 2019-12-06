/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:07:36 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/03 16:35:10 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

int try_insert(int *tableau, t_piece piece, int pos)
{
	return(0);
}

void insert(int *tableau, t_piece piece, int pos, int size_test)
{

	int X;
	int Y;
	int i;
	int j;
	int temp;
	
	X = pos / size_test;
	Y = pos % size_test;

	i = 0;
	j = 0;

	while (j < piece.width)
	{
		while (i < piece.lenght)
			{
				temp = (i * piece.width) + j;
				tableau[(X + i) * size_test + Y + j] = piece.data_compressed[(i * piece.width) + j];
				i++;
			}
		i = 0;
		j++;
	}
	
}

void remove_piece(int *tableau, t_piece piece, int pos)
{
	
}

void move_search_position(int *tableau, t_piece piece, int *pos)
{

}

int	found_solution(t_liste *entree, int index, int next_pos, int **tableau, int size_test)
{
	int try;
	
	while ((try = try_insert(tableau[index], entree->pieces[index], next_pos)) != -1)
	{
		if (try == 1)
		{
			insert(tableau + index, entree->pieces[index], next_pos, size_test);
			if (index == entree->nb)
			{
				(entree->pieces + index)->column_sol = 0;
				(entree->pieces + index)->row_sol = 0;
				return (1);
			}
			if (found_solution(entree, index + 1, next_pos, tableau, size_test))
			{
				(entree->pieces + index)->column_sol = 0;
				(entree->pieces + index)->row_sol = 0;
				return (1);
			}
			remove_piece(tableau[index], entree->pieces[index], next_pos);
		}
		move_search_position(tableau[index], entree->pieces[index], &next_pos);
	}
	return (0);
}
