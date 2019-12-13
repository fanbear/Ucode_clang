#ifndef PATH_H
#define PATH_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <malloc.h>
#include <fcntl.h>
// #include "libmx.h"

// Extra libmx.h

int mx_atoi(const char *str);
void mx_printerr(const char *s);
bool mx_isalpha(int c);
bool mx_isupper(int c);
bool mx_islower(int c);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_strncmp(const char *s1, const char *s2, size_t n);
char *mx_strchr(const char *str, int ch);

// Utils pack

void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);

// String pack

int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
int mx_read_line(char **lineptr, int buf_size, char delim, const int fd);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);

// Memory pack

void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

// List pack

typedef struct  s_list {
    void  *data;
    struct s_list *next;
}         t_list;

t_list  *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

typedef struct s_path {
	int bondIsl;
	int bondDist;
	struct s_path *nextBond;
	struct s_path *nextPath;
}       t_path;

typedef struct s_island {
	int currentIsl;
	int distTo;
	struct s_path *path;
	struct s_island *next;
}		t_island;

t_path *mx_create_path(int isl, int dist);
void mx_delPath(t_path **head);
void mx_push_backBond(t_path **path, int isl, int dist);
t_path *mx_addPath(t_path **previous, int isl, int dist);
void mx_push_backPath(t_path **path, t_path **previous, int isl, int dist);
void mx_check_empty_line(char **lines, char *file);
void mx_errors(int argc, char *file, char **argv);
void mx_parse(char *fd, int ***matrix, char ***set);
void mx_create_arrarr(char **lines, char ***arrarr);
void mx_create_set(char ***set, char ***arrarr, char *nIslands);
int **mx_create_matrix(char **set, char ***arrarr);
void mx_print_mat(int **mat, char **set);
void mx_algo(int **matrix, char **set);
t_island *mx_shortest(t_island **unvisited);

#endif
