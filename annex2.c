/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:07:36 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/06 14:41:55 by adelorme         ###   ########.fr       */
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
				list->zip[j + j * k] = 0;
				k++;
			}
			j++;
		}
		(list + i)->column_min = SIZE + 1;
		(list + i)->row_min = SIZE + 1;
		i++;
	}
}

void	extract_compressed(t_piece *piece)
{
	int i;

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
		piece->data2[i / piece->width][i % piece->width] = piece->data[(i / piece->width + piece->row_min) * SIZE + (i % piece->width + piece->column_min)];
		piece->zip[i] = piece->data[(i / piece->width +
		piece->row_min) * SIZE + (i % piece->width + piece->column_min)];
		i++;
	}
}
