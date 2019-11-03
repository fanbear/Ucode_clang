#include <stdio.h>

int mx_strcmp(const char *s1, const char *s2);

static void swap(char *a, char *b) {
	char *temp = a;
	a = b;
	b = temp;
}

static int partition(char **arr, int left, int right) {
	int pivot = (right + left) / 2;
	int count = 0;
	for (int j = pivot + 1, i = left; j < right && i < pivot && left != right; j++) {
		if (mx_strcmp(arr[j], arr[pivot]) <= 0) {
			i++;
			swap(arr[i], arr[j]);
			count++;
		}
	}
	return count;
}

int mx_quicksort(char **arr, int left, int right) {
	
	int count = 0;
	int pivot = (left + right) / 2;

	if (!arr) return -1;

	count += partition(arr, left, right);
	mx_quicksort(arr, left, pivot);
	mx_quicksort(arr, pivot, right);
	return count;
}

int main() {
	char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
	printf("%d", mx_quicksort(arr, 0, 3));
}
