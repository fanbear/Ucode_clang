#include "path.h"

 static void mx_linearr(char *line, char **island1, char **island2, char **dist) {
 
	int i = 0;
	char *str = line;
	while(str[i] != '-') i++;
	*island1 = mx_strndup(str, i);
	str += i + 1;
	i = 0;
	while(str[i] != ',') i++;
	*island2 = mx_strndup(str, i);
	str += i + 1;
	i = 0;
	while(str[i] != '\0') i++;
	*dist = mx_strndup(str, i);
}

static void mx_fill_islands(char ***arrarr, char **lines) {
	char **arr = *arrarr;
	char *island1 = NULL;
	char *island2 = NULL;
	char *dist = NULL;
	int line = 1;

	while(lines[line]) {
		mx_linearr(lines[line], &island1, &island2, &dist);
		*arr = mx_strdup(island1);
		arr++;
		mx_strdel(&island1);
		*arr = mx_strdup(island2);
		arr++;
		mx_strdel(&island2);
		*arr = mx_strdup(dist);
		line++, arr++;
		mx_strdel(&dist);
	}
	*arr = NULL;
}

void mx_create_arrarr(char **lines, char ***arrarr){
	int line = 1;

	while (lines[line]){
		line++;
	}
	*arrarr = (char **)malloc((line * 3 + 1) * sizeof(char *));
	mx_fill_islands(&(*arrarr), lines);
}
