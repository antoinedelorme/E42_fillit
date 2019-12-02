
#ifndef FILLIT_H
# define FILLIT_H
# define KBLOCK 'x'
# define KEMPTY '.'
# include <string.h>
#define NB_MAX 26
# define SIZE 4

typedef	struct		s_piece
{
	int data[SIZE*SIZE];
	int data_compressed[SIZE*SIZE];
	int row_min;
	int row_max;
	int column_min;
	int column_max;
	int width;
	int lenght;
	
}					t_piece;

int read_file(char *name, t_piece *liste, int *nb);
int found_solution(t_piece *liste, int nb_piece, int size);
int display(t_piece *liste, int nb_piece);
void init_data(t_piece list[NB_MAX]);
void extract_compressed(t_piece *piece);
#endif
