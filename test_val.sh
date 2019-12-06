clear
gcc -g main.c -I./includes ./srcs/*.c annex.c annex2.c annex3.c annex4.c
valgrind --leak-check=full ./a.out test.txt
