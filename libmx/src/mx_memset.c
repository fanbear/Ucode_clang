#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {

	unsigned char *s = b;

	while(len--) {
		*s++ = c;
	}
	return b;
}
/*
int main() {
	void *b = malloc(5);
	mx_memset(b, '4', 5);
	printf("%s", b);
} */
