/**********
 * Bilal Atakan Ünal
 * 2018556069
 * CEN215 Data Structure Lab 
 * Homework 1 : SHORTING
 *********** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>



/*** SWAP FS ***/
void swapForInt(int *aP, int *bP)
{
	int temp = *aP;
	*aP = *bP;
	*bP = temp;
}
void swapForChar(char* aP, char* bP)
{
	char temp = *aP;
	*aP = *bP;
	*bP = temp;
}

/*** INSERTIONSORT ***/
void insertionForInt(int number[], int n)
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

void insertionForChar(char name[], int len) { 

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

/*** SELECTIONSORT ALGORITHM ***/
void selectionForInt(int number[], int n)
{
	int i, j, min;

	for (i = 0; i < n - 1; i++)
	{
		min = i;

		for (j = i + 1; j < n; j++)
			if (number[j] < number[min]) min = j;

		swapForInt(&number[min], &number[i]);
	}
}

void selectionForChar(char name[], int len) {
	int i, j, min;

	for (i = 0; i < len - 1; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
			if (name[j] < name[min]) min = j;

		swapForChar(&name[min], &name[i]);
	}

}
/*** BUBBLESORT ALGORITHM ***/
void bubbleForInt(int arr[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) 
                swapForInt(&arr[j], &arr[j + 1]);
}
void bubbleForChar(char name[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - i - 1; j++)
			if (name[j] > name[j + 1])
				swapForChar(&name[j], &name[j + 1]);
}

/*** MERGE SORT ALGORITHM ***/
void mergeForInt(int arr[], int l, int m, int r) 
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


void mergeSortForInt(int arr[], int l, int r) 
{ 
	if (l < r) { 
		
		int middle = l + (r - l) / 2; 

		
		mergeSortForInt(arr, l, middle); 
		mergeSortForInt(arr, middle + 1, r); 

		mergeForInt(arr, l, middle, r); 
	} 
} 

void mergeForChar(char arr[], int l, int middle, int r) 
{ 
	int i, j, k; 
	int n1 = middle - l + 1; 
	int n2 = r - middle; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[middle + 1 + j]; 

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


void mergeSortForChar(char arr[], int l, int r) 
{ 
	if (l < r) { 
		
		int middle = l + (r - l) / 2; 

		
		mergeSortForChar(arr, l, middle); 
		mergeSortForChar(arr, middle + 1, r); 

		mergeForChar(arr, l, middle, r); 
	} 
} 


/*** PRINT FUNCTIONS ***/
void printArrayForChar(char name[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%c ", name[i]);
	printf("\n");
}
void printArrayForInt(int number[], int n)
{
	int i;
	printf("  ");
	for (i = 0; i < n; i++)
		printf("%d ", number[i]);
	printf("\n");
}

/*** PRINT PERFORMANCE ***/
void printPerformance( float t ) {
    printf("Performance: %f", t / CLOCKS_PER_SEC);
	printf("\n\n");
}

int main()
{
	clock_t t;

	char name[] = "Bilal Atakan UNAL";
	int number[] = { 2,0,1,8,5,5,6,0,6,9 };

	int len = strlen(name);
	int n = sizeof(number) / sizeof(number[0]);

	for(int i = 0; i < len; i++){
		name[i] = tolower(name[i]); // Lower case: A -> a
	}

	/***************************/

	printf("Name: Bilal Atakan UNAL\n");
    printf("Student No: 2018556069");

    printf("\n\n");

	printf("-----> INSERTION SORT <-----\n");

	t = clock(); // get current time
    insertionForChar(name, len);
    t = clock() - t; // current time - starting time
    
    printArrayForChar(name, len); 
    printPerformance( (float) t);


	insertionForInt(number, n);	
	t = clock() - t;
	printArrayForInt(number, n);
    printf("Insertion Sort Process: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

    /**************************/

	printf("-----> SELECTION SORT <-----\n");

	t = clock();
	selectionForChar(name, len);
	t = clock() - t;

	printArrayForChar(name, len);
	printPerformance( (float) t);

	selectionForInt(number, n);
	t = clock() - t;
	printArrayForInt(number, n);

    printPerformance( (float) t);

    /**************************/

	printf("-----> SELECTION SORT <-----\n");

	t = clock();
	bubbleForChar(name, len);
	t = clock() - t;

	printArrayForChar(name, len);
	printPerformance( (float) t);

	bubbleForInt(number, n);
	t = clock() - t;
	printArrayForInt(number, n);

	printPerformance( (float) t);

    /**************************/
    printf("-----> MERGE SORT <-----\n");

	t = clock();
	mergeSortForChar(name, 0, len-1);
	t = clock() - t;

	printArrayForChar(name, len);
	printPerformance( (float) t);

	mergeSortForInt(number, 0, n - 1); 
	t = clock() - t;
	printArrayForInt(number, n);

	printPerformance( (float) t);

	return 0;
    
}