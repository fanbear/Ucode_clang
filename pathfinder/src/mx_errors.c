#include "path.h"

static void mx_print_invalid(int nline) {
	nline++;
	char *index = mx_itoa(nline);
	mx_printerr("error: line ");
	mx_printerr(index);
	mx_printerr(" isn't valid\n");
	exit(EXIT_FAILURE);
}

static void mx_checkline(char **lines, int nline) {

	while(nline > 0) {
		int i = 0, copy_i = 0;
		while(mx_isalpha(lines[nline][i])) i++;
		if (i == 0 || lines[nline][i] != '-')
			mx_print_invalid(nline);
		i++, copy_i = i;
		while(mx_isalpha(lines[nline][copy_i])) copy_i++;
		if (copy_i - i == 0 || lines[nline][copy_i] != ',')
			mx_print_invalid(nline);
		copy_i++, i = copy_i;
		while(mx_isdigit(lines[nline][copy_i])) copy_i++;
		if (copy_i - i == 0 || lines[nline][copy_i] != '\0') 
			mx_print_invalid(nline);
		nline--;
	}
}

static void mx_parserr(char *file) {

	char **lines = mx_strsplit(file, '\n');
	int nline = 0, at = 0;
	
	while (lines[nline]) nline++;
	while (lines[0][at]) {
		if (!mx_isdigit(lines[0][at])) {
			mx_printerr("error: line 1 isn't valid\n");
			exit(EXIT_FAILURE);
		}
		at++;
	}
	at = mx_atoi(lines[0]);
	mx_checkline(lines, nline-1);
	mx_del_strarr(&lines);
}

void mx_errors(int argc, char **argv) {

	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(EXIT_FAILURE);
	}
	char *file = mx_file_to_str(argv[1]);

	if (!file) {
		 mx_printerr("error: file ");
		 mx_printerr(argv[1]);
		 mx_printerr(" doesn't exist\n");
		 exit(EXIT_FAILURE);
	}
	if (mx_strlen(file) == 0) {
		mx_printerr("error: file ");
		mx_printerr(argv[1]);
		mx_printerr(" is empty\n");
		exit(EXIT_FAILURE);
	}
	mx_parserr(file);
	mx_strdel(&file);
}
