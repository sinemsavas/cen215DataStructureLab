#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//swap operations for type int
void swapIdNumber(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

}
//swap operations for type char
void swapName(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}
//INSERTION SORT
void insertionSortIdNumber(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void insertionSortName(char str[], int n)
{
  int i, j;
  char key;
  for (i = 1; i < n; i++)
  {
    key = str[i];
    j = i - 1;
    while (j >= 0 && str[j] > key)
    {
      str[j + 1] = str[j];
      j = j - 1;
    }
    str[j + 1] = key;
  }
}


//SELECTION SORT
void selectionSortIdNumber(int arr[], int size) {
	int i, j, curMin;
	for (i = 0; i < size - 1; ++i) {
		curMin = i;
		for (j = i + 1; j < size; ++j) {
			if (arr[j] < arr[curMin])
				curMin = j;
		}
		swapIdNumber(&arr[curMin], &arr[i]);
	}

}
void selectionSortName(char arr[], int size) {
	int i, j, curMin;
	for (i = 0; i < size - 1; ++i) {
		curMin = i;
		for (j = i + 1; j < size; ++j) {
			if (arr[j] < arr[curMin])
				curMin = j;
		}
		swapName(&arr[curMin], &arr[i]);
	}

}

//BUBBLE SORT
void bubbleSortIdNumber(int arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swapIdNumber(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void bubbleSortName(char arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swapName(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//MERGE SORT
void mergeIdNumber(int arr[], int left, int mid, int right)
{
	int i, j, l = 0;
	int temp[right - left + 1];

	for (i = left, j = mid + 1; (i <= mid) && (j <= right);)
	{
		if (arr[i] < arr[j]) {
			temp[l] = arr[i];
			i++;
			l++;
		}
		else {
			temp[l] = arr[j];
			j++;
			l++;
		}
	}

	while (i <= mid) {
		temp[l] = arr[i];
		i++;
		l++;
	}
	while (j <= right) {
		temp[l] = arr[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		arr[i] = temp[l];
	}

}

void mergeName(char arr[], int left, int mid, int right)
{
	int i, j, l = 0;
	char temp[right - left + 1];

	for (i = left, j = mid + 1; (i <= mid) && (j <= right);)
	{
		if (arr[i] < arr[j]) {
			temp[l] = arr[i];
			i++;
			l++;
		}
		else {
			temp[l] = arr[j];
			j++;
			l++;
		}
	}

	while (i <= mid) {
		temp[l] = arr[i];
		i++;
		l++;
	}
	while (j <= right) {
		temp[l] = arr[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		arr[i] = temp[l];
	}

}
void  mergeSortIdNumber(int arr[], int left, int right) {
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		mergeSortIdNumber(arr, left, mid);
		mergeSortIdNumber(arr, mid + 1, right);

		mergeIdNumber(arr, left, mid, right);

	}
}
void mergeSortName(char arr[], int left, int right) {
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		mergeSortName(arr, left, mid);
		mergeSortName(arr, mid + 1, right);
		mergeName(arr, left, mid, right);

	}
}

//PRINT SORTS
void printSortIdNumber(int arr[], int size) {
	int i;
	printf(" Sorted numbers :");
	for (i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void printSortName(char arr[], int size) {
	int i;
	printf(" Sorted chars : ");
	for (i = 0; i < size; ++i) {
		printf("%c ", arr[i]);
	}
	printf("\n");
}



int main() {
	
	printf(" CEN215 - DATA STRUCTURES LAB HOMEWORK #1\n");
	printf(" ID Number: 2017556459\n");
	printf(" Name: IREM HALAC\n\n\n");
	
		
	printf(" INSERTION SORT \n");
	clock_t timer;
	timer = clock();
	int IdNumber[] = { 2,0,1,7,5,5,6,4,5,9 };
	char Name[] = "IREM HALAC";
	int IdNumberSize = sizeof(IdNumber) / sizeof(IdNumber[0]);
	int NameSize = strlen(Name);
	insertionSortIdNumber(IdNumber, IdNumberSize);
	timer = clock() - timer;
	printSortIdNumber(IdNumber, IdNumberSize);
	printf(" Running time of Insertion Sort for ID Number: %f\n", ((double)(timer)) / CLOCKS_PER_SEC);

	insertionSortName(Name, NameSize);
	timer = clock() - timer;
	printSortName(Name, NameSize);
	printf(" Running time of Insertion Sort for name: %f\n\n", ((double)(timer)) / CLOCKS_PER_SEC);
	
	

	printf(" SELECTION SORT\n");
	int IdNumber2[] = { 2,0,1,7,5,5,6,4,5,9 };
	char Name2[] = "IREM HALAC";
	int IdNumberSize2 = sizeof(IdNumber2) / sizeof(IdNumber2[0]);
	int NameSize2 = strlen(Name2);
	selectionSortIdNumber(IdNumber2, IdNumberSize2);
	timer = clock() - timer;
	printSortIdNumber(IdNumber2, IdNumberSize2);
	printf(" Running time of Selection Sort for ID Number: %f\n", ((double)(timer)) / CLOCKS_PER_SEC); 

	selectionSortName(Name2, NameSize2);
	timer = clock() - timer;
	printSortName(Name2, NameSize2);
	printf(" Running time of Selection Sort for name: %f\n\n", ((double)(timer)) / CLOCKS_PER_SEC);
	
	

	printf(" MERGE SORT \n");
	int IdNumber3[] = { 2,0,1,7,5,5,6,4,5,9 };
	char Name3[] = "IREM HALAC";
	int IdNumberSize3 = sizeof(IdNumber3) / sizeof(IdNumber3[0]);
	int NameSize3 = strlen(Name3);
	mergeSortIdNumber(IdNumber3, 0, IdNumberSize3 - 1);
	timer = clock() - timer;
	printSortIdNumber(IdNumber3, IdNumberSize3);
	printf(" Running time of Merge Sort for ID Number: %f\n", ((double)(timer)) / CLOCKS_PER_SEC);

	mergeSortName(Name3, 0, NameSize3 - 1);
	timer = clock() - timer;
	printSortName(Name3, NameSize3);
	printf(" Running time of Merge Sort for name: %f\n\n", ((double)(timer)) / CLOCKS_PER_SEC);




	printf(" BUBBLE SORT\n");
	int IdNumber4[] = { 2,0,1,7,5,5,6,4,5,9 };
	char Name4[] = "IREM HALAC";
	int IdNumberSize4 = sizeof(IdNumber4) / sizeof(IdNumber4[0]);
	int NameSize4 = strlen(Name4);
	bubbleSortIdNumber(IdNumber4, IdNumberSize4);
	timer = clock() - timer;
	printSortIdNumber(IdNumber4, IdNumberSize4);
	printf(" Running time of Bubble Sort for ID Number: %f\n", ((double)(timer)) / CLOCKS_PER_SEC);

	bubbleSortName(Name4, NameSize4);
	timer = clock() - timer;
	printSortName(Name4, NameSize4);
	printf(" Running time of Bubble Sort for name: %f\n\n", ((double)(timer)) / CLOCKS_PER_SEC);




	return 0;
}
