#include "path.h"
// #include "libmx.h"

int main(int argc, char *argv[]) {
	int **matrix = NULL;
	char **set = NULL;
	char *file = mx_file_to_str(argv[1]);

	mx_errors(argc, file, argv);
	mx_parse(file, &matrix, &set);
	// mx_print_strarr(set, "\n");
	mx_algo(matrix, set);
	mx_strdel(&file);
	mx_del_strarr(&set);
	return 0;
}
