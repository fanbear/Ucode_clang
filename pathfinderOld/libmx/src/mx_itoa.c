#include "libmx.h"

char *mx_itoa(int number) {

	int n = 0;
	int n1 = number;
	int flag = 0;
	char *res = NULL;
	int i = 0;


	if (number == 0) {
		res = mx_strnew(1);
		mx_strcpy(res, "0");
		return res;
	}
	if (number == -2147483648) {
		res = mx_strnew(11);
		mx_strcpy(res, "-2147483648");
		return res;
	}
	while (n1) {
		n1 /= 10;
		n++;
	}
	if (number < 0) {
		flag = 1;
		number *= -1;
		n++;
	}
	res = mx_strnew(n);
	while (number) {
		if (number < 10 && flag > 0)
            res[i+1] = '-';

		n = number % 10;
		res[i] = n + '0';
		number /= 10;
		i++;
	}
	mx_str_reverse(res);
	return res;
}
