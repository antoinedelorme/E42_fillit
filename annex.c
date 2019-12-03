/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:01:44 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/03 17:21:05 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

int	conform_line(char *line, int index, t_piece list[NB_MAX])
{
	int i;

	i = 0;
	if (index % (SIZE + 1) == SIZE)
	{
		if (*line == '\0')
		{
			ft_strdel(&line);
			return (1);
		}
		return (0);
	}
	while (line[i])
	{
		if ((!((line[i] == KBLOCK) || (line[i] == KEMPTY))))
		{
			ft_strdel(&line);
			return (0);
		}
		list[index / (SIZE + 1)].data[(index % (SIZE + 1)) * SIZE + i] =
	(line[i] == KBLOCK ? 1 : 0);
		i++;
	}
	ft_strdel(&line);
	return ((i <= SIZE));
}

int	test_conform(char *name, t_piece liste[NB_MAX], int *nb)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		return (-1);
	while ((get_next_line(fd, &line) > 0))
	{
		if (!conform_line(line, i, liste))
		{
			close(fd);
			return (-1);
		}
		i++;
	}
	if ((i % (SIZE + 1)) != SIZE && (i % (SIZE + 1)) != (SIZE - 1))
		return (-1);
	if (i > (NB_MAX * (SIZE + 1)))
		return (-1);
	close(fd);
	*nb = (i / (SIZE + 1)) + 1;
	return (1);
}

int	test_piece(t_piece pc)
{
	int i;
	int total;
	int flag;
	int nb_blocks;

	i = 0;
	nb_blocks = 0;
	total = 0;
	while (i < SIZE * SIZE)
	{
		flag = pc.data[i];
		nb_blocks += flag;
		total += flag && ((i - SIZE) >= 0 ? pc.data[i - SIZE] : 0);
		total += flag && ((i + SIZE) < (SIZE * SIZE) ? pc.data[i + SIZE] : 0);
		total += flag && ((i == (SIZE - 1) % SIZE) ? 0 : pc.data[i + 1]);
		total += flag && ((i == 0 % SIZE) ? 0 : pc.data[i - 1]);
		i++;
	}
	return ((nb_blocks == 4) && (total >= 6));
}

int	read_file(char *name, t_liste *entree)
{
	int i;
	int j;

	i = 0;
	j = 0;
	init_data(entree->pieces);
	if (test_conform(name, entree->pieces, &(entree->nb)) == -1)
		return (-1);
	while (i < entree->nb)
	{
		if (!test_piece(entree->pieces[i]))
			return (-1);
		extract_compressed(entree->pieces + i);
		j = 0;
		while (j < (entree->pieces + i)->lenght * (entree->pieces + i)->width)
			j++;
		i++;
	}
	return (1);
}
