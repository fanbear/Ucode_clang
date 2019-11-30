#include "path.h"

static void mx_print_invalid(int nline) {
	nline++;
	char *index = mx_itoa(nline);
	mx_printerr("error: line ");
	mx_printerr(index);
	mx_printerr(" isn't valid\n");
	exit(EXIT_FAILURE);
}

void mx_check_empty_line(char **lines, char *file) {
	char *fl = file;
	char **ln = lines;
	int i = 0;
	if (*fl == '\n')
		mx_print_invalid(0);
	while(*fl) {
		if (*fl == '\n' && *(fl+1) == '\n') {
			while(ln[i]) {
				if (mx_strncmp(fl+2, ln[i], mx_strlen(ln[i])) == 0) 
					mx_print_invalid(i);
				i++;
			}
			mx_print_invalid(i);
		}
		fl++;
	}
}
