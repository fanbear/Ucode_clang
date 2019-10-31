#include <stdlib.h>

char *mx_strnew(const int size) {
	if (size < 0)
		return NULL;
	char *target = (char*)malloc((size + 1) * sizeof(char));
	if (target == NULL)
		return NULL;
	for (int i = 0; i < size + 1; i++) {
		target[i] = '\0';
	}
	return target;
}
