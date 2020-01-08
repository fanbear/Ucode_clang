#include "path.h"


static int mx_flag(char *arr, char ***set1, int i) {
	int j = 0;
	int flag = 0;
	char **set = *set1;

	while(set[j]) {
		if (mx_strcmp(arr, set[j]) == 0) {
			flag++;
			break;
		}
		j++;
	}
	if (flag == 0) {
		set[i] = mx_strdup(arr);
		set[i+1] = NULL;
	}
	return flag;
}

static void mx_set(char ***set, char ***arrarr) {
	char **arr = *arrarr;
	char **set1 = *set;
	int i = 0;

	for (int flag = 0; *arr; flag = 0) {
		if (mx_isdigit(**arr))
			arr++;
		if (*arr) {
			flag = mx_flag(*arr, &set1, i);
			if (flag != 0) {
				arr++;
				continue;
			}
			if (flag == 0)
				i++;
			arr++;
		}
	}
}

void mx_create_set(char ***set, char ***arrarr, char *nIslands) {
	int count = 0;

	mx_count_set(*arrarr, nIslands, &count);
	*set = (char **)malloc((count + 1) * sizeof(char *));
	**set = NULL;
	mx_set(&(*set), &(*arrarr));
}
