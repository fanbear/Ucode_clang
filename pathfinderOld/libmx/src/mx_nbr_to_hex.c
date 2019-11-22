#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long tmp = nbr;
    int length = 0;
    char *result = NULL;
    int i = 0;

    if (nbr == 0) {
        return "0";
    }
    while (tmp > 0) {
        tmp /= 16;
        length++;
    }
    result = mx_strnew(length);
    i = length - 1;
	while (nbr > 0) {
        int tmp1 = nbr % 16;

        if (tmp1 < 10) {
            result[i] = tmp1 + '0';
        }
        else {
            result[i] = tmp1 + 87;
        }
        nbr /= 16;
		i--;
	}
	return result;
}
