/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:07:36 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/05 14:42:17 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	display(t_piece *piece)
{
	int x;
	int y;

		x = 0;
		while (x < piece->lenght)
		{
			y = 0;
			while (y < piece->width)
			{
				if (piece->data_compressed[x * piece->width + y])
				ft_putstr("🧮");
			else
				ft_putstr("🧾");
				y++;
			}
			printf("\n");
			x++;
		}

}

int		try(t_grille grille, t_piece piece, int pos)
{
	int i;
	int j;
	int pixel;

	i = 0;
	j = 0;
	//printf("trying to insert in pos: %i\n", pos);
	while (j < piece.width)
	{
		while (i < piece.lenght)
		{
			if (((pos / grille.l) + i) >= grille.l ||
			((pos % grille.l) + j) >= grille.l)
				pixel = 1;
			else
				pixel = grille.tableaux[((pos / grille.l) + i)
				* grille.l + (pos % grille.l) + j];
			if (pixel && piece.data_compressed[(i * piece.width) + j])
			{
	//			printf("failed\n");
				return (0);
			}
			i++;
		}
		i = 0;
		j++;
	}
	//printf("success\n");
	return (1);
}

void	insert_remove(t_grille grille, t_piece piece, int pos)
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
			pixel = piece.data_compressed[(i * piece.width) + j] ^
			grille.tableaux[((pos / grille.l) + i) * grille.l +
			(pos % grille.l) + j];
			grille.tableaux[((pos / grille.l) + i) * grille.l
			+ (pos % grille.l) + j] = pixel;
			i++;
		}
		i = 0;
		j++;
	}
}

void display_grid(t_grille grd)
{
	int i;
	int j;
	int pixel;

	i = 0;
	
	while (i < grd.l)
	{
		j = 0;
		while (j < grd.l)
		{
			if (grd.tableaux[j + i * grd.l] > 0)
				printf("@");
			else
			{
				printf(".");
			}
			
			j++;
		}
		printf("\n");
		i++;
	}
}

int		found_solution(t_liste *ent, int idx, int pos, t_grille grd)
{
	int t;

	if (idx == ent->nb)
		return (grd.l);
	while ((t = try(grd, ent->pieces[idx], pos)) != -1 && pos != grd.l * grd.l)
	{
		if (t == 1)
		{
		//	printf("inserting\n");
			insert_remove(grd, ent->pieces[idx], pos);
	//		display_grid(grd);
			if ((find_pos(grd, pos)) == grd.l * grd.l)
			{
		//	printf("[a]removing\n");
			insert_remove(grd, ent->pieces[idx], pos);
	//		display_grid(grd);
				break ;
			}
			if (found_solution(ent, ++idx, 0, grd))
			{
				(ent->pieces + idx - 1)->pos_sol = pos;
				return (grd.l);
			}
	//	printf("[b]removing\n");
			insert_remove(grd, ent->pieces[--idx], pos);
	//		display_grid(grd);
		}
		pos = find_pos(grd, pos);
	}
	
	return (0);
}
