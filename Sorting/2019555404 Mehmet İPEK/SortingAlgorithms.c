#include <stdio.h>
#include <time.h>

void Swap(int *a, int *b);
void PrintNumber(int array[], int size);
void PrintName(int array[], int size);

void BubbleSort(int array[], int size) {

	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1; j++) {
			if (array[j] > array[j + 1])
				Swap(&array[j], &array[j + 1]);
		}
	}
}

void SelectionSort(int array[], int size) {

	int i, j, min;
	for (i = 0; i < size; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {

			if (array[j] < array[min]) {
				min = j;
			}
		}
		Swap(&array[i], &array[min]);
	}
}

void InsertionSort(int array[], int size) {

	int i, j, key;

	for (i = 1; i < size; i++) {

		j = i - 1;
		key = array[i];

		while (j >= 0 && array[j] > key) {

			array[j + 1] = array[j];
			j -= 1;

		}

		array[j + 1] = key;
	}
}

void Merge(int array[], int left, int middle, int right){
	int i, j, k;
	int Lsize = middle - left + 1;
	int Rsize = right - middle;

	int Left[10], Right[10];

	for (i = 0; i < Lsize; i++)
		Left[i] = array[left + i];

	for (j = 0; j < Rsize; j++)
		Right[j] = array[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < Lsize && j < Rsize) {

		if (Left[i] <= Right[j]) {
			array[k] = Left[i];
			i++;
		}
		else {

			array[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < Lsize) {

		array[k] = Left[i];
		i++;
		k++;
	}

	while (j < Rsize) {

		array[k] = Right[j];
		j++;
		k++;
	}
}

void MergeSort(int array[], int left, int right) {

	if (left < right) {

		int middle = (left + right) / 2;

		MergeSort(array, left, middle);
		MergeSort(array, middle + 1, right);

		Merge(array, left, middle, right);
	}
}

int main() {
	//Definitions
	clock_t time;

	int number0[] = { 2,0,1,9,5,5,5,4,0,4};
	int number0Size = sizeof(number0) / sizeof(number0[0]);
	printf("My number is: 2019555404\n");

	int name0[] = { 'M','e','h','m','e','t','I','p','e','k' };
	int name0Size = sizeof(name0) / sizeof(name0[0]);
	printf("My name is: Mehmet Ipek\n\n");

	//Buble Sort
	printf("\n\tBubble Sort\n\n");
	time = clock();
	BubbleSort(number0, number0Size);
	time = clock() - time;
	PrintNumber(number0, number0Size);
	printf("Bubble Sort took %f seconds to sort my number\n", ((double)time) / CLOCKS_PER_SEC);
	time = clock();
	BubbleSort(name0, name0Size);
	time = clock() - time;
	PrintName(name0, name0Size);
	printf("Bubble Sort took %f seconds to sort my name\n", ((double)time) / CLOCKS_PER_SEC);

	//Definitions2
	int number1[] = { 2,0,1,9,5,5,5,4,0,4};
	int number1Size = sizeof(number1) / sizeof(number1[0]);

	int name1[] = { 'M','e','h','m','e','t','I','p','e','k' };
	int name1Size = sizeof(name1) / sizeof(name1[0]);

	//Selection Sort
	printf("\n\tSelection Sort\n\n");
	time = clock();
	SelectionSort(number1, number1Size);
	time = clock() - time;
	PrintNumber(number1, number1Size);
	printf("Selection Sort took %f seconds to sort my number\n", ((double)time) / CLOCKS_PER_SEC);
	time = clock();
	SelectionSort(name1, name1Size);
	time = clock() - time;
	PrintName(name1, name1Size);
	printf("Selection Sort took %f seconds to sort my name\n", ((double)time) / CLOCKS_PER_SEC);

	//Definitions3
	int number2[] = { 2,0,1,9,5,5,5,4,0,4};
	int number2Size = sizeof(number2) / sizeof(number2[0]);

	int name2[] = { 'M','e','h','m','e','t','I','p','e','k' };
	int name2Size = sizeof(name2) / sizeof(name2[0]);

	//Insertion Sort
	printf("\n\tInsertion Sort\n\n");
	time = clock();
	InsertionSort(number2, number2Size);
	time = clock() - time;
	PrintNumber(number2, number2Size);
	printf("Insertion Sort took %f seconds to sort my number\n", ((double)time) / CLOCKS_PER_SEC);
	time = clock();
	InsertionSort(name2, name2Size);
	time = clock() - time;
	PrintName(name2, name2Size);
	printf("Insertion Sort took %f seconds to sort my name\n", ((double)time) / CLOCKS_PER_SEC);

	//Definitions4
	int number3[] = { 2,0,1,9,5,5,5,4,0,4};
	int number3Size = sizeof(number3) / sizeof(number3[0]);

	int name3[] = { 'M','e','h','m','e','t','I','p','e','k' };
	int name3Size = sizeof(name3) / sizeof(name3[0]);

	//Merge Sort
	printf("\n\tMerge Sort\n\n");
	time = clock();
	MergeSort(number3, 0, number3Size - 1);
	time = clock() - time;
	PrintNumber(number3, number3Size);
	printf("Merge Sort took %f seconds to sort my number\n", ((double)time) / CLOCKS_PER_SEC);
	time = clock();
	MergeSort(name3, 0, name3Size - 1);
	time = clock() - time;
	PrintName(name3, name3Size);
	printf("Merge Sort took %f seconds to sort my name\n", ((double)time) / CLOCKS_PER_SEC);

	return 0;
}

void Swap(int* a, int* b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintNumber(int array[], int size) {

	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void PrintName(int array[], int size) {

	int i;
	for (i = 0; i < size; i++) {
		printf("%c ", array[i]);
	}
	printf("\n");
}
