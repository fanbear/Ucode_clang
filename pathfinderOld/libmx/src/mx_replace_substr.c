#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	int len = 0;
	char *cpy1 = NULL;
	char *cpy2 = NULL;
	int count = 0;

	count = mx_count_substr(str,sub);
	len = mx_strlen(str) - (mx_strlen(sub) * count) + (mx_strlen(replace) * count);
	cpy1 = mx_strnew(len);
	cpy2 = cpy1;

	while (*str && *str != '\0') {
		if (str != mx_strstr(str, sub)) {
			*cpy2 = *str;
			cpy2++;
			str++;
		}
		if (str == mx_strstr(str, sub)) {
			mx_strncpy(cpy2, replace, mx_strlen(replace));
			cpy2 += mx_strlen(replace);
			str += mx_strlen(sub);
		}
	}
	return cpy1;
}
