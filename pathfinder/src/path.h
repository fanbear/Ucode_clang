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

void mx_errors(int argc, char **argv);
void mx_parse(char **argv);
void mx_create_arrarr(char **lines, char ***arrarr);
void mx_create_set(char ***set, char ***arrarr, char *nIslands);
void mx_create_matrix(int ***matrix, char **set, char **arrarr);

#endif
