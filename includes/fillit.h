/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:17:17 by adelorme          #+#    #+#             */
/*   Updated: 2019/12/06 16:18:01 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define KBLOCK '#'
# define KEMPTY '.'
# define NB_MAX 26
# define SIZE 4
# ifdef COLOR
#  define CHAR 4
#  define LETTERS  "🏴🐽🦷🐡💀💭🧠🐝👹👻🤖👾😺🙈💋💔💥👹🐽🦷🐡💀💭🧠🐝👹👻🤖👾😺🙈💋💔💥👹"
# else
#  define CHAR 1
#  define LETTERS ".ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# endif

# include <string.h>
#include <time.h>

int cpt_back;
int cpt_showhide;
int cpt_testok;
double total_time;

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;


typedef	struct	s_piece
{
	int	data[SIZE * SIZE];
	int	data2[SIZE][SIZE];
	int	zip[SIZE * SIZE];
	int	row_min;
	int	row_max;
	int	column_min;
	int	column_max;
	int	width;
	int	lenght;
	int	pos_sol;
	t_pos	t_pos_sol;
}				t_piece;

typedef struct	s_liste
{
	t_piece	*pieces;
	int		nb;
}				t_liste;

typedef struct	s_grille
{
	int **tableaux;
	int	l;
	int index;
}				t_grille;

typedef struct	s_sol_vector
{
	int sol[NB_MAX];
	int current;
}				t_sol_vector;

void			display(t_piece *piece);
void			insert(t_grille grille, t_piece piece, t_pos pos);
int				read_file(char *name, t_liste *entree);
int				found_solution(t_liste *entree, int index,
t_pos next_pos, t_grille grille);
void			init_data(t_piece list[NB_MAX]);
void			extract_compressed(t_piece *piece);
t_pos				find_pos(t_pos pos, int width);
int				get_next_index(t_liste entree, t_sol_vector sol_vector);
int				affiche_solution(t_liste solution, int size);
int		pos_compare(t_pos pos1, t_pos pos2);
#endif
