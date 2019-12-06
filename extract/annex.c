annex2.c                                                                                            000644  111501  010321  00000004620 13571473245 014043  0                                                                                                    ustar 00adelorme                        2019_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:07:36 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/03 15:52:21 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	init_data(t_piece list[NB_MAX])
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < NB_MAX)
	{
		ft_memset((void*)&list[i], '\0', sizeof(t_piece));
		while (j < SIZE)
		{
			while (k < SIZE)
			{
				list->data[j + j * k] = 0;
				list->data_compressed[j + j * k] = 0;
				k++;
			}
			j++;
		}
		(list + i)->column_min = SIZE + 1;
		(list + i)->row_min = SIZE + 1;
		i++;
	}
}

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

void	extract_compressed(t_piece *piece)
{
	int i;
	int x;
	int y;
	i = 0;
	while (i < SIZE * SIZE)
	{
		if (piece->data[i] == 1 && (i % SIZE) > piece->column_max)
			piece->column_max = (i % SIZE);
		if (piece->data[i] == 1 && (i / SIZE) > piece->row_max)
			piece->row_max = (i / SIZE);
		if (piece->data[i] == 1 && (i % SIZE) < piece->column_min)
			piece->column_min = (i % SIZE);
		if (piece->data[i] == 1 && (i / SIZE) < piece->row_min)
			piece->row_min = (i / SIZE);
		i++;
	}
	i = 0;
	piece->width = (piece->column_max - piece->column_min + 1);
	piece->lenght = (piece->row_max - piece->row_min + 1);
	
	while (i < piece->width * piece->lenght)
	{
		x = i / piece->width + piece->row_min;
		y = i % piece->width + piece->column_min;
		piece->data_compressed[i] = piece->data[x * SIZE + y];
		i++;
	}
}


                                                                                                                annex3.c                                                                                            000644  111501  010321  00000004426 13571500256 014041  0                                                                                                    ustar 00adelorme                        2019_paris                      000000  000000                                                                                                                                                                         /* ************************************************************************** */
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
                                                                                                                                                                                                                                          main.c                                                                                              000644  111501  010321  00000002330 13571500306 013555  0                                                                                                    ustar 00adelorme                        2019_paris                      000000  000000                                                                                                                                                                         #include "libft.h"
#include "get_next_line.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

void display_tableau (int *tableau, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tableau[i * size + j])
				ft_putstr("🧮");
			else 
				ft_putstr("🧾");
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
	}
}
void find_solution(t_liste *entree)
{
	int size;
	int		**tableau;
	int		i;

	size = 8;
	
	 while (1)
	 {
		 i = 0;
		 tableau = (int**)ft_memalloc(sizeof(int*));
		 while (i < entree->nb)
		 	{
				 tableau[i] = (int*)ft_memalloc(size * size * sizeof(int));
				 display(entree->pieces + i);
				 printf("\n");
				 i++;
			}
			insert(tableau[0], entree->pieces[0], 0, size);
			display_tableau (tableau[0], size);
			return;
			if (found_solution(entree, 0, 0, tableau, size))
				return;
		 size++;
	 }
}
int main(int ac, char **av)
{
	t_piece liste[NB_MAX];
	t_liste entree;
	int size;
	int **tableau;
	
	entree.nb = 0;
	entree.pieces = liste;
	size = 4;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}

	if (read_file(av[1], &entree) == -1)
	{
		//exit;
		ft_putstr("error\n");
		return (0);
	}
	find_solution( &entree);
	
	return (1);
}




                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        