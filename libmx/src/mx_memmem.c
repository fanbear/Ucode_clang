#include "libmx.h"
#include <string.h>

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {

	const char *bg = big;
	const char *lt = little;

	if (big_len < little_len || big_len == 0 || little_len == 0) return NULL;
	if (!mx_strlen(little)) return NULL;

	if (mx_strstr(bg, lt)) return mx_strstr(bg, lt);

	return NULL;
}
/*
int main() {
    void *s = "";
	void *s1 = "1";

    printf("%s\n", mx_memmem(s, 10, s1, 1));
    printf("%s\n", memmem(s, 10, s1, 1));
}*/
