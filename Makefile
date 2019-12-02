CC = gcc
CFLAGS = -Wall -Wextra -Werror
DATA = ./srcs/
INCLUDES = ./includes/
SRC	= ${wildcard ${DATA}ft*.c} ${DATA}get_next_line.c main.c annex.c
OBJ = ${SRC:.c=.o}
NAME = libft.a
EXEC = fillit
HEADER = ft.h

all: ${EXEC}

${NAME}: ${OBJ}
	ar -cr $@ $^

${EXEC}: ${NAME}
	${CC} ${CFLAGS} -o fillit main.c libft.a -I./includes

%.o : %.c
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES}

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${OBJ}
	rm -f ${NAME}
	rm -f ${EXEC}

re:
	rm -f ${OBJ}
	rm -f ${NAME}
	rm -f ${EXEC}
	make all

	
