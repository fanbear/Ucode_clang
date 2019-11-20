#include "path.h"

static int mx_count_set(char **arr, char *nIslands) {
	int i = 0;
	int count = 0;
	int j = 0;
	
	while (arr[i] != NULL) {
		if(mx_isdigit(arr[i][0]) && arr[i + 1] != NULL) i++;
		j = i - 1;
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

static int mx_flag(char *arr, char **set1) {
	int j = 0;
	int flag = 0;

	while(set1[j]) {
		if (mx_strcmp(arr, set1[j]) == 0) {
			flag++;
			break;
		}
		j++;
	}
	return flag;
}


static void mx_set(char ***set, char ***arrarr) {
	char **arr = *arrarr;
	char **set1 = *set;
	int flag = 0;
	int i = 0;

	while(*arr) {
		if (mx_isdigit(**arr)) arr++;
		if (*arr) {
			flag = mx_flag(*arr, set1);
			if (flag != 0) arr++;
			if (flag == 0) {
				set1[i] = mx_strdup(*arr);
				i++;
			}
			arr++;
		}
	}
	set1[i] = NULL;
}

void mx_create_set(char ***set, char ***arrarr, char *nIslands) {
	int count = mx_count_set(*arrarr, nIslands);
	*set = (char **)malloc((count + 1) * sizeof(char *));
	mx_set(&(*set), &(*arrarr));
}
