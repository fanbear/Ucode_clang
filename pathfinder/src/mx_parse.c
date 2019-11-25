#include "path.h"

void mx_parse(char *fd, int ***matrix, char ***set) {
	char **arrarr = NULL;
	char **lines = mx_strsplit(fd, '\n');
	mx_create_arrarr(lines, &arrarr);
	mx_create_set(&(*set), &arrarr, lines[0]);
	// mx_print_strarr(*set, "\n");
	*matrix = mx_create_matrix(*set, &arrarr);
	// mx_print_mat(*matrix, *set);
	mx_del_strarr(&lines);
	mx_del_strarr(&arrarr);
}
