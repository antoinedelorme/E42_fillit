/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:46:44 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/06 14:12:20 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int	racine(int x)
{
	int y;

	y = 0;
	while (y * y < x)
		y++;
	return (y - 1);
}

int	find_solution(t_liste *entree)
{
	t_grille		grille;
	t_sol_vector	vector_sol;
	int				size;
	int 			i;

	grille.l = racine(entree->nb * 4) + 1;
	ft_memset((void*)vector_sol.sol, '\0', sizeof(int) * NB_MAX);
	while (1)
	{
		i = -1;
		grille.tableaux = (int**)ft_memalloc(grille.l * sizeof(int*));
		while (++i < grille.l)
			grille.tableaux[i] = (int*)ft_memalloc(grille.l * sizeof(int));
		vector_sol.current = 0;
		if ((size = found_solution(entree, 0, (t_pos){0,0}, grille)))
		{
			ft_memdel((void**)&grille.tableaux);
			return (size);
		}
		ft_memdel((void**)&grille.tableaux);
		grille.l++;
	}
}

int	exit_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
	return (0);
}

int	main(int ac, char **av)
{
	t_piece	liste[NB_MAX];
	t_liste	entree;
	int		size;

	entree.nb = 0;
	entree.pieces = liste;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}
	if (read_file(av[1], &entree) == -1)
		return (exit_error());
	size = find_solution(&entree);
	if (!affiche_solution(entree, size))
		return (exit_error());
	exit(EXIT_SUCCESS);
	return (1);
}
