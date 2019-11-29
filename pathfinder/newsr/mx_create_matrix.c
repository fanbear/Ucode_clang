#include "path.h"

static void mx_fill(char **set, char **arrarr, int ***matrix, int i, int j) {
	int **mat = *matrix;
	int k = 0;

	// mx_print_strarr(set, "\n");
	if(mx_isdigit(arrarr[j + 1][0])) {
		while(mx_strcmp(set[k], arrarr[j-1]) != 0) k++;
		mat[i][k] = mx_atoi(arrarr[j+1]);
		// mx_printint(mat[i][k]);
		// mx_printchar('\n');
	}
	else {
		while(mx_strcmp(set[k], arrarr[j+1]) != 0) k++;
		mat[i][k] = mx_atoi(arrarr[j+2]);
		// mx_printint(mat[i][k]);
		// mx_printchar('\n');
	}
}

static void mx_mat(char **set, char **arrarr, int ***matrix) {
	int i = 0;
	int j = 0;

	while(set[i]) {
		j = 0;
		while(arrarr[j]) {
			if(mx_strcmp(set[i], arrarr[j]) == 0) {
				mx_fill(set, arrarr, &(*matrix), i, j);
			}
			j++;
		}
		i++;
	}
}

int **mx_create_matrix(char **set, char ***arrarr) {
	int **matrix = NULL;
	int i = 0;
	int k = i;

	while(set[i]) i++;
	k = i;
	matrix = malloc(sizeof(int*) * i);
	while(k >= 0) {
		matrix[k] = malloc(sizeof(int) * i);
		k--;
	}
	mx_mat(set, *arrarr, &matrix);
	return matrix;
}
