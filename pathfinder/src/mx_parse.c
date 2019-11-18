#include "path.h"

void mx_parse(char **argv) {
	char **arrarr = NULL;
	int **matrix = NULL;
	char **set = NULL;
	char *fd = mx_file_to_str(argv[1]);
	char **lines = mx_strsplit(fd, '\n');
	mx_create_arrarr(lines, &arrarr);
	mx_create_set(&set, &arrarr, lines[0]);
	// mx_print_strarr(set, "\n");
	mx_create_matrix(&matrix, set, arrarr);
	mx_del_strarr(&lines);
	mx_del_strarr(&set);
	mx_del_strarr(&arrarr);
	mx_strdel(&fd);
}
