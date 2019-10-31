void mx_sort_arr_int(int *arr, int size) {
	int t = 0;
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			if (arr[k] > arr[i]) {
				t = arr[i];
				arr[i] = arr[k];
				arr[k] = t;
			}
		}
	}
}
