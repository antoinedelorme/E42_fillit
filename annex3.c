/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:07:36 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/06 13:59:36 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

int		try(t_grille grille, t_piece piece, t_pos pos)
{
	int i;
	int j;
	int pixel;

	i = 0;
	j = -1;
	if (piece.lenght + pos.x > grille.l)
		return (0);
	if (piece.width + pos.y > grille.l)
		return (0); 
	while (++j < piece.width)
	{
		while (i < piece.lenght)
		{
			
			pixel = grille.tableaux[pos.x + i][pos.y +j];
			if (pixel && piece.zip[(i * piece.width) + j])
				return (0);
			i++;
		}
		i = 0;
	}
	return (1);
}

void	insert_remove(t_grille grille, t_piece piece, t_pos pos)
{
	int i;
	int j;
	int pixel;

	i = 0;
	j = 0;
	while (j < piece.width)
	{
		while (i < piece.lenght)
		{
			pixel = piece.zip[(i * piece.width) + j] ^ grille.tableaux[pos.x + i][pos.y +j];
			grille.tableaux[pos.x + i][pos.y +j] = pixel;
			i++;
		}
		i = 0;
		j++;
	}
}

int		found_solution(t_liste *ent, int idx, t_pos pos, t_grille grd)
{
	int t;
	if (idx == ent->nb)
		return (grd.l);
	while ((pos.x != grd.l || pos.y != 0) && (t = try(grd, ent->pieces[idx], pos)) != -1) 
	{
		if (t == 1)
		{
			insert_remove(grd, ent->pieces[idx], pos);
		
			if (pos_compare(pos, (t_pos){grd.l, 0}))
			{
				insert_remove(grd, ent->pieces[idx], pos);
				break ;
			}
			if (found_solution(ent, ++idx, (t_pos){0,0} , grd))
			{
				printf("SOL piece: %i x: %i y: %i\n", idx -1, pos.x, pos.y);
				(ent->pieces + idx - 1)->t_pos_sol = pos;
				return (grd.l);
			}
			insert_remove(grd, ent->pieces[--idx], pos);
		}
		pos = find_pos(pos, grd.l);
	}
	return (0);
}
