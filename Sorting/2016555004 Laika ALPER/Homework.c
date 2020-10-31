#include <stdio.h>
#include <string.h>
#include <time.h>



//SWAP FUNCTION
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void swapName(char* xp, char* yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//INSERTIONSORT  ALGORITHM
void insertionName(char name[], int len) { 

	int i, key, j;
	for (i = 1; i < len; i++) {
		key = name[i];
		j = i - 1;

		while (j >= 0 && name[j] > key) {
			name[j + 1] = name[j];
			j = j - 1;
		}

		name[j + 1] = key;
	}

}
void insertionNumber(int number[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = number[i];
		j = i - 1;

	
		while (j >= 0 && number[j] > key) {
			number[j + 1] = number[j];
			j = j - 1;
		}
		number[j + 1] = key;
	}
}



//SELECTIONSORT ALGORITHM
void selectionNumber(int number[], int n)
{
	int i, j, minIndex;

	for (i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < n; j++)
			if (number[j] < number[minIndex])
				minIndex = j;

		swap(&number[minIndex], &number[i]);
	}
}

void selectionName(char name[], int len) {
	int i, j, minIndex;

	for (i = 0; i < len - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < len; j++)
			if (name[j] < name[minIndex])
				minIndex = j;

		swapName(&name[minIndex], &name[i]);
	}

}
//BUBBLESORT ALGORITHM
void bubbleNumber(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
void bubbleName(char name[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)

		for (j = 0; j < len - i - 1; j++)
			if (name[j] > name[j + 1])
				swapName(&name[j], &name[j + 1]);
}

//MERGE SORT ALGORITHM
void mergeNumber(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 


	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 


void mergeSortNumber(int arr[], int l, int r) 
{ 
	if (l < r) { 
		
		int m = l + (r - l) / 2; 

		
		mergeSortNumber(arr, l, m); 
		mergeSortNumber(arr, m + 1, r); 

		mergeNumber(arr, l, m, r); 
	} 
} 

void mergeName(char arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 


	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 


void mergeSortName(char arr[], int l, int r) 
{ 
	if (l < r) { 
		
		int m = l + (r - l) / 2; 

		
		mergeSortName(arr, l, m); 
		mergeSortName(arr, m + 1, r); 

		mergeName(arr, l, m, r); 
	} 
} 


//PRINT FUNCTIONS
void printArrayName(char name[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%c ", name[i]);
	printf("\n");
}
void printArrayNumber(int number[], int n)
{
	int i;
	printf("  ");
	for (i = 0; i < n; i++)
		printf("%d ", number[i]);
	printf("\n");
}


int main()
{
	clock_t t;

	char name[] = "Laika Alper";
	int number[] = { 2,0,1,6,5,5,5,0,0,4 };

	int len = strlen(name);
	int n = sizeof(number) / sizeof(number[0]);

	/***************************/
	printf("My name is: Laika ALPER\nMy number is: 2016555004\n\n");
	printf("******Insertion sort******\n");
	t = clock();
    insertionName(name, len);
    t = clock() - t;
    printArrayName(name, len); 
    printf("Insertion Sort Process: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	insertionNumber(number, n);	
	t = clock() - t;
	printArrayNumber(number, n);
    printf("Insertion Sort Process: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
    /**************************/
	printf("******Selection sort******\n");
	t = clock();
	selectionName(name, len);
	t = clock() - t;
	printArrayName(name, len);
	printf("Selection Sort Process: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	selectionNumber(number, n);
	t = clock() - t;
	printArrayNumber(number, n);
    printf("Selection Sort Process: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
    /**************************/
	printf("******Bubble sort******\n");
	t = clock();
	bubbleName(name, len);
	t = clock() - t;
	printArrayName(name, len);
	printf("Bubble Sort Process: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	bubbleNumber(number, n);
	t = clock() - t;
	printArrayNumber(number, n);
	printf("Bubble Sort Process: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
    /**************************/
    printf("******Merge sort******\n");
	t = clock();
	mergeSortName(name, 0, len-1);
	t = clock() - t;
	printArrayName(name, len);
	printf("Merge Sort Process: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	mergeSortNumber(number, 0, n - 1); 
	t = clock() - t;
	printArrayNumber(number, n);
	printf("Merge Sort Process: %f\n\n", ((double)t) / CLOCKS_PER_SEC);	
	
	return 0;
    
}


