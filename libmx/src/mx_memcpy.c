#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	
	unsigned char *dt = dst;
	unsigned const char *sc = src;

	while(n--)
		*dt++ = *sc++;

	return dst;
}
/*
int main() {
    void *restrict b = malloc(5);
	const void *restrict src = malloc(5);
	src = "0123";
    mx_memcpy(b, src, 3);
    printf("%s \n", b);
	printf("%s \n", mx_memcpy(b,src, 3));
} */
