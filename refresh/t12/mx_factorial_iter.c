#include <stdio.h>

int mx_factorial_iter(int n) {
	int result = 1;
	if (n > 12 || n < 0)
		return 0;
	while (n) {
		result *= n;
		n--;
	}
	return result;
}
