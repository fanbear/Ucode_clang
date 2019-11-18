#include "path.h"

static int mx_count_set(char **arr, char *nIslands) {
	int i = 0, count = 0;
	while (arr[i] != NULL) {
		if(mx_isdigit(arr[i][0]) && arr[i + 1] != NULL) i++;
		int j = i - 1;
		while(j >= 0) {
			if (mx_strcmp(arr[i], arr[j]) == 0) break;
			if (j == 0) count++;
			j--;
		}
		i++;
	}
	if (count != mx_atoi(nIslands)) {
		mx_printerr("error: invalid number of islands\n");
		exit(EXIT_FAILURE);
	}
	return count;
}

void mx_create_set(char ***set, char ***arrarr, char *nIslands) {
	char **arr = *arrarr;
	int count = mx_count_set(arr, nIslands);
	int i = 0;
	*set = (char **)malloc((count + 1) * sizeof(char *));
	char **set1 = *set;

	while(*arr) {
		if (mx_isdigit(**arr)) arr++;
		int flag = 0, j = 0;
			while(set1[j]) {
				if (mx_strcmp(*arr, set1[j]) == 0) {
					arr++, flag++;
					break;
				}
				j++;
			}
		if (flag == 0) {
			set1[i] = mx_strdup(*arr);
			i++;
		}
		arr++;
	}
	set1[i] = NULL;
}
