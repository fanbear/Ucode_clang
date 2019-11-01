#include "libmx.h"
#include <string.h>

void *mx_memchr(const void *s, int c, size_t n) {

	unsigned char c1 = c;
	unsigned const char *s1 = s;

	while(*s1 && n--) {
		if (*s1 == c1)
			return (char*)s1;
			s1++;
		}
	return NULL;
}
/*
int main() {

	void *s = "0123456789";

	printf("%s\n", mx_memchr(s, '5', 10));
	printf("%s\n", memchr(s, '5', 10));
} */
