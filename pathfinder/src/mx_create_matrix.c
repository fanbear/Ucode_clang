#include "path.h"

void mx_print_mat(int ***mat, char **set) {
	int **ma = *mat;
	int i = 0, k = 0;
	while(set[i]) i++;
	while(k < i) {
		int j = 0;
		while(j < i) {
			mx_printint(ma[k][j]);
			mx_printchar(' ');
			j++;
		}
		mx_printchar('\n');
		k++;
	}
}

void mx_create_matrix(int ***matrix, char **set, char **arrarr) {
	int **mat = *matrix;
	int i = 0;
	while(set[i]) i++;
	int k = i;
	mat = malloc(sizeof(int*) * i);
	while(k >= 0) {
		mat[k] = malloc(sizeof(int) * i);
		k--;
	}
	i = 0;
	while(set[i]) {
		// mx_printchar('\n');
		int j = 0;
		while(arrarr[j]) {
			if(mx_strcmp(set[i], arrarr[j]) == 0) {
				if(mx_isdigit(arrarr[j + 1][0])) {
					int k = 0;
					while(mx_strcmp(set[k], arrarr[j-1]) != 0) k++;
					mat[i][k] = mx_atoi(arrarr[j+1]);
				}
				else {
					int k = 0;
					while(mx_strcmp(set[k], arrarr[j+1]) != 0) k++;
					mat[i][k] = mx_atoi(arrarr[j+2]);
				}

			}
			j++;
		}
		i++;
	}
	mx_print_mat(&mat, set);
}
