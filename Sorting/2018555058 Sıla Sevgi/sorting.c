#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Rest
void rest_N(int* num, int* num1, int size);
void rest_L(char* let, char* let1, int size);

//SelectionSort
void selectionSort_N(int* num, int size);
void selectionSort_L(char* let, int size);

//BubbleSort
void bubleSort_N(int* num, int size);
void bubleSort_L(char* let, int size);

//InsertionSort
void insertionSort_N(int* num, int size);
void insertionSort_L(char* let, int size);

//MergeSort
void mergeSort_N(int* num, int i, int j);
void merge_N(int* num, int l, int m, int r);
void mergeSort_L(char* let, int i, int j);
void merge_L(char* let, int l, int m, int r);

//Swap
void swap_N(int* num, int i, int j);
void swap_L(char* let, int i, int j);

//Print
void print_N(int* num, int size);
void print_L(char* let, int size);

int main() {

	// SchoolNumber array
	int schoolNumber[] = { 2,0,1,8,5,5,5,0,5,8 };
	int size_N = sizeof(schoolNumber) / sizeof(schoolNumber[0]);
	int num[10];
	clock_t timer;
	printf("Original Number is : ");
	print_N(&schoolNumber[0], size_N);

	printf("\n");
	// Name Array
	char name[] = "SilaSevgi";
	int size_L = sizeof(name) / sizeof(name[0]);
	char let[17];
	printf("Original Letter is : ");
	print_L(&name[0], size_L);

	//selectionSort *****************************************
	printf("\n\nPart of Selection Sort\n");

	//for Number
	rest_N(&schoolNumber[0], &num[0], size_N);
	timer = clock();
	selectionSort_N(&num[0], size_N);
	timer = clock() - timer;
	printf("Organized Number is : ");
	print_N(&num[0], size_N);
	printf("\nThe passing time : %f second", ((double)timer) / CLOCKS_PER_SEC);

	printf("\n");
	//for Letter
	rest_L(&name[0], &let[0], size_L);
	timer = clock();
	selectionSort_L(&let[0], size_L);
	timer = clock() - timer;
	printf("Organized Letter is : ");
	print_L(&let[0], size_L);
	printf("\nThe passing time : %f second", (((double)timer) / CLOCKS_PER_SEC));

	//bubbleSort  *****************************************
	printf("\n\nPart of Bubble Sort\n");

	//for Number
	rest_N(&schoolNumber[0], &num[0], size_N);
	timer = clock();
	bubleSort_N(&num[0], size_N);
	timer = clock() - timer;
	printf("xOrganized Number is : ");
	print_N(&num[0], size_N);
	printf("\nThe passing time : %f second", (((double)timer) / CLOCKS_PER_SEC));

	printf("\n");
	//for Letter
	rest_L(&name[0], &let[0], size_L);
	timer = clock();
	bubleSort_L(&let[0], size_L);
	timer = clock() - timer;
	printf("Organized Letter is : ");
	print_L(&let[0], size_L);
	printf("\nThe passing time : %f second", (((double)timer) / CLOCKS_PER_SEC));


	//insertionSort ****************************************
	printf("\n\nPart of Insertion Sort\n");

	//for Number
	rest_N(&schoolNumber[0], &num[0], size_N);
	timer = clock();
	insertionSort_N(&num[0], size_N);
	timer = clock() - timer;
	printf("Organized Number is : ");
	print_N(&num[0], size_N);
	printf("\nThe passing time : %f second", (((double)timer) / CLOCKS_PER_SEC));

	printf("\n");

	//for Letter
	rest_L(&name[0], &let[0], size_L);
	timer = clock();
	insertionSort_L(&let[0], size_L);
	timer = clock() - timer;
	printf("Organized Letter is : ");
	print_L(&let[0], size_L);
	printf("\nThe passing time : %f second", (((double)timer) / CLOCKS_PER_SEC));

	//mergeSort	******************************************
	printf("\n\nPart of Merge Sort\n");

	//for Number
	rest_N(&schoolNumber[0], &num[0], size_N);
	timer = clock();
	mergeSort_N(&num[0], 0, size_N - 1);
	timer = clock() - timer;
	printf("Organized Number is : ");
	print_N(&num[0], size_N);
	printf("\nThe passing time : %f second", (((double)timer) / CLOCKS_PER_SEC));

	printf("\n");

	//for Letter
	rest_L(&name[0], &let[0], size_L);
	timer = clock();
	mergeSort_L(&let[0], 0, size_L - 1);
	timer = clock() - timer;
	printf("Organized Letter is : ");
	print_L(&let[0], size_L);
	printf("\nThe passing time : %f second", (((double)timer) / CLOCKS_PER_SEC));

}

//Rest	*************************************************

//for Number
void rest_N(int* num, int* num1, int size) {
	int i = 0;
	for (; i < size; i++) {
		num1[i] = num[i];
	}
}

//for Letter
void rest_L(char* let, char* let1, int size) {
	int i = 0;
	for (; i < size; i++) {
		let1[i] = let[i];
	}
}

//selectionSort *****************************************

//for Number
void selectionSort_N(int* num, int size) {
	int i = 0;
	for (; i < size - 1; i++) {
		int mc = i, flag = 0;
		int j = i + 1;
		for (; j < size; j++) {
			if (num[j] < num[mc]) {
				mc = j;
				flag = 1;
			}
		}
		if (flag == 1) {
			swap_N(num, i, mc);
		}
	}

}

//for Letter
void selectionSort_L(char* let, int size) {
	int i = 0;
	for (; i < size - 1; i++) {
		int mc = i, flag = 0;
		int j = i + 1;
		for (; j < size; j++) {
			if (let[j] < let[mc]) {
				mc = j;
				flag = 1;
			}
		}
		if (flag == 1) {
			swap_L(let, i, mc);
		}
	}
}

//bubbleSort  ***************************************

//for Number
void bubleSort_N(int* num, int size) {
	int i = 0;
	for (; i < size; i++) {
		int j = 0;
		for (; j < size - 1; j++) {
			if (num[j] > num[j + 1]) {
				swap_N(num, j, j + 1);
			}
		}
	}
}

//for Letter
void bubleSort_L(char* let, int size) {
	int i = 0;
	for (; i < size; i++) {
		int j = 0;
		for (; j < size - 1; j++) {
			if (let[j] > let[j + 1]) {
				swap_L(let, j, j + 1);
			}
		}
	}
}

//insertionSort **************************************

//for Number
void insertionSort_N(int* num, int size) {
	int i = 1;
	for (; i < size; i++) {
		int fc = num[i];
		int mc = i;
		for (; mc > 0 && num[mc - 1] > fc; mc--) {
			num[mc] = num[mc - 1];
		}
		num[mc] = fc;
	}
}

//for Letter
void insertionSort_L(char* let, int size) {
	int i = 1;
	for (; i < size; i++) {
		int fc = let[i];
		int mc = i;
		for (; mc > 0 && let[mc - 1] > fc; mc--) {
			let[mc] = let[mc - 1];
		}
		let[mc] = fc;
	}
}

//MergeSort	 ***************************************

//for Number
void mergeSort_N(int* num, int i, int j) {
	if (i < j) {

		int mc = i + (j - i) / 2;

		mergeSort_N(num, i, mc);
		mergeSort_N(num, mc + 1, j);

		merge_N(num, i, mc, j);
	}
}
void merge_N(int* num, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = num[l + i];
	for (j = 0; j < n2; j++)
		R[j] = num[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			num[k] = L[i];
			i++;
		}
		else {
			num[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		num[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		num[k] = R[j];
		j++;
		k++;
	}
}

//for Letter 
void mergeSort_L(char* let, int i, int j) {
	if (i < j) {

		int mc = i + (j - i) / 2;

		mergeSort_L(let, i, mc);
		mergeSort_L(let, mc + 1, j);

		merge_L(let, i, mc, j);
	}
}
void merge_L(char* let, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	char L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = let[l + i];
	for (j = 0; j < n2; j++)
		R[j] = let[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			let[k] = L[i];
			i++;
		}
		else {
			let[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		let[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		let[k] = R[j];
		j++;
		k++;
	}
}


//Swap	********************************************

//for Number
void swap_N(int* num, int i, int j) {
	int a = num[i];
	num[i] = num[j];
	num[j] = a;
}

//for Letter
void swap_L(char* let, int i, int j) {
	char a = let[i];
	let[i] = let[j];
	let[j] = a;
}

//Print  *******************************************

//for Number
void print_N(int* num, int size) {
	int i = 0;
	for (; i < size; i++)
		printf("%d", num[i]);
}

//for Letter
void print_L(char* let, int size) {
	int i = 0;
	for (; i < size; i++)
		if (let[i] == ' ')
			printf("_");
		else
			printf("%c", let[i]);
}
