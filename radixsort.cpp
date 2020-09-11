int get_max(int* arr, int size)
{
	int* arr;
	arr = new int[size];
	int max = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			return max;
		}
	}
}

void count_sort(int* arr, int size, int exp)
{
	int* arr = new int[size];
	int* output;
	output = new int[size];
	int count[100] = { 0 };

	for (int i = 0; i < size; i++) {
		count[(arr[i] / exp) % 10]++;
	}

	for (int i = 1; i < size; i++) {
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < size; i++) {
		arr[i] = output[i];
	}
}

void radix_sort(int* arr, int size)
{
	int temp = get_max(arr, size);

	for (int exp = 1; temp / exp > 0; exp *= 10) {
		count_sort(arr, size, exp);
	}
}
