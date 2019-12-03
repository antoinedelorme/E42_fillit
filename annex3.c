/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:07:36 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/03 17:17:37 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

int try_insert(int *tableau, t_piece piece, int pos)
{
	return(0);
}

void insert(t_grille grille, t_piece piece, int pos, int index)
{

	int X;
	int Y;
	int i;
	int j;
	int temp;
	
	X = pos / grille.size;
	Y = pos % grille.size;

	i = 0;
	j = 0;

	while (j < piece.width)
	{
		while (i < piece.lenght)
			{
				temp = (i * piece.width) + j;
				grille.tableaux[index][(X + i) * grille.size + Y + j] = piece.data_compressed[(i * piece.width) + j];
				i++;
			}
		i = 0;
		j++;
	}
	
}

void remove_piece(t_grille grille, t_piece piece, int pos, int index)
{
	
}

void move_search_position(t_grille grille, t_liste *entree, int pos, int index)
{

}

int	found_solution(t_liste *entree, int index, int next_pos, t_grille grille)
{
	int try;
	
	while ((try = try_insert(grille.tableaux[index], entree->pieces[index], next_pos)) != -1)
	{
		if (try == 1)
		{
			insert(grille, entree->pieces[index], next_pos, index);
			if (index == entree->nb)
			{
				(entree->pieces + index)->column_sol = 0;
				(entree->pieces + index)->row_sol = 0;
				return (1);
			}
			if (found_solution(entree, index + 1, next_pos, grille))
			{
				(entree->pieces + index)->column_sol = 0;
				(entree->pieces + index)->row_sol = 0;
				return (1);
			}
			remove_piece(grille, entree->pieces[index], next_pos, index);
		}
		move_search_position(grille, entree, next_pos, index);
	}
	return (0);
}
