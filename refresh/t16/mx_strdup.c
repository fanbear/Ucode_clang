#include <stdlib.h>
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);

char *mx_strdup(const char *str) {
	int len = mx_strlen(str);
	char *target = mx_strnew(len);

	for (int i = 0; i < len; i++) {
		target[i] = str[i];
	}
	return target;
}
