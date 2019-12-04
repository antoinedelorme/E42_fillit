/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:07:36 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/04 18:29:47 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>


int try_insert(t_grille grille, t_piece piece, int pos)
{
	int X;
	int Y;
	int i;
	int j;
	int pixel;
	
	X = pos / grille.size;
	Y = pos % grille.size;
	i = 0;
	j = 0;

	while (j < piece.width)
	{
		while (i < piece.lenght)
			{
				if ((X + i) >= grille.size || (Y + j) >= grille.size)
					pixel = 1;
				else
					pixel = grille.tableaux[(X + i) * grille.size + Y + j];
				if ( pixel && piece.data_compressed[(i * piece.width) + j])
					return (0);
				i++;
			}
		i = 0;
		j++;
	}
	return (1);
}



void insert_remove(t_grille grille, t_piece piece, int pos)
{
	int X;
	int Y;
	int i;
	int j;
	int pixel;
	
	X = pos / grille.size;
	Y = pos % grille.size;
	i = 0;
	j = 0;
	while (j < piece.width)
	{
		while (i < piece.lenght)
			{
				pixel = piece.data_compressed[(i * piece.width) + j]^grille.tableaux[(X + i) * grille.size + Y + j]; 
				grille.tableaux[(X + i) * grille.size + Y + j] = pixel;
				i++;
			}
		i = 0;
		j++;
	}
}


int	found_solution(t_liste *entree, int index, int next_pos, t_grille grille)
{
	int try;

	if (index == entree->nb)
		return (grille.size);
	while ((try = try_insert(grille, entree->pieces[index], next_pos)) != -1 && next_pos != grille.size * grille.size)
	{
		if (try == 1)
		{
			insert_remove(grille, entree->pieces[index], next_pos);
			if((find_next_pos(grille, next_pos)) == grille.size * grille.size)
			{
				insert_remove(grille, entree->pieces[index], next_pos);
				break;
			}
				index++;
			if (found_solution(entree, index, next_pos, grille))
			{
				(entree->pieces + index - 1)->pos_sol = next_pos;
				return (grille.size);
			}
			index--;
			insert_remove(grille, entree->pieces[index], next_pos);
		}
			
		next_pos = find_next_pos(grille, next_pos);
	}
	return (0);
}
