#ifndef PATH_H
#define PATH_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <malloc/malloc.h>
#include <fcntl.h>
#include "libmx.h"

typedef struct s_path {
	char *bondIsl;
	char *bondDist;
	struct s_path *next;
}       t_path;

typedef struct s_island {
	int currentIsl;
	int distTo;
	struct s_path *path;
	struct s_island *next;
}		t_island;



void mx_errors(int argc, char *file, char **argv);
void mx_parse(char *fd, int ***matrix, char ***set);
void mx_create_arrarr(char **lines, char ***arrarr);
void mx_create_set(char ***set, char ***arrarr, char *nIslands);
int **mx_create_matrix(char **set, char ***arrarr);
void mx_print_mat(int **mat, char **set);
void mx_algo(int **matrix, char **set);


#endif
