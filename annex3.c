/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:07:36 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/06 16:17:51 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>
#include <time.h>

int		try(t_grille grille, t_piece piece, t_pos pos)
{
	int i;
	int j;
	struct timespec start, end;
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	i = 0;
	j = -1;
	cpt_testok++;
	 if (piece.lenght + pos.x > grille.l)
	 	return (0);
	 if (piece.width + pos.y > grille.l)
	 	return (0); 
	 while (++j < piece.width)
	{
		while (i < piece.lenght)
		{
			if (grille.tableaux[pos.x + i][pos.y +j] && piece.data2[i][j])
				return (0);
			i++;
		}
		i = 0;
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	total_time += (double)(end.tv_nsec - start.tv_nsec)/1000000;
	return (1);
}

void	insert_remove(t_grille grille, t_piece piece, t_pos pos)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	cpt_showhide++;
	while (j < piece.width)
	{
		while (i < piece.lenght)
		{
			grille.tableaux[pos.x + i][pos.y +j] = piece.zip[(i * piece.width) + j] ^ grille.tableaux[pos.x + i][pos.y +j];
			i++;
		}
		i = 0;
		j++;
	}
}

int		found_solution(t_liste *ent, int idx, t_pos pos, t_grille grd)
{
	int t;

	cpt_back++;
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
				(ent->pieces + idx - 1)->t_pos_sol = pos;
				return (grd.l);
			}
			insert_remove(grd, ent->pieces[--idx], pos);
		}
		pos = find_pos(pos, grd.l);
	}
	return (0);
}
