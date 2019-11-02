#include "libmx.h"
#include <string.h>

void *mx_memmove(void *dst, const void *src, size_t len) {

	unsigned char buffer[len];

	mx_memcpy(buffer, src, len);
	mx_memcpy(dst, buffer, len);
	return dst;
}
/*
int main() {
    void *b = malloc(40);
    const void *b2 = malloc(40);
	b2 = "012345678901234567890";
    memmove(b, b2, 5);
    printf("%s \n", b);
    printf("%s \n", memmove(b, b2, 30));
	printf("%s \n", b);

}*/
