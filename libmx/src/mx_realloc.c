#include "libmx.h"
#include <string.h>

void *mx_realloc(void *ptr, size_t size) {

	void *cpy = NULL;

	if (!ptr && size) return malloc(size);

	if (!size && ptr) {
		free(ptr);
		cpy = malloc(malloc_size(NULL));
		return cpy;
	}
	cpy = malloc(size);
	mx_memmove(cpy, ptr, malloc_size(ptr));
	free(ptr);
	return cpy;
}
/*
int main() {
	char *s1 = malloc(5);
	mx_strcpy(s1, "sadff");
	printf("%s\n", s1);
	printf("%zu\n", malloc_size(s1));
	s1 = realloc(s1, 34);
	printf("%s  %zu", s1, malloc_size(s1));
} */
