#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	unsigned const char *s11 = s1;
	unsigned const char *s22 = s2;
	
	while(n--) {
		if (*s11 != *s22)
			return *s11 - *s22;
		s11++, s22++;
	}
	return n;
}
/*
int main() {
	void *s1 = "012345Z";
	void *s2 = "012345w";
	printf("%d\n", mx_memcmp(s1, s2, 10));
	printf("%d\n", memcmp(s1, s2, 10));
}*/
