#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//Insertion Sort
void insertionSort(int arr[], int n) 
{ 
    int i, x, j; 
    for (i = 1; i < n; i++) { 
        x = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > x) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = x; 
    } 
} 
void insertionSortChar(char arr[], int n) 
{
    int i, j;
    char x;
    for(i = 1; i < n; i++) {
        x = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
    }
}

   void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void swapChar(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

//Selection Sort 
void selectionSort(int arr[], int n) 
{ 
    int i, j, min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 

void selectionSortChar(char arr[], int n) 
{ 
    int i, j;
    char min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swapChar(&arr[min], &arr[i]); 
    } 
}
//Bubble Sort
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void bubbleSortChar(char arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapChar(&arr[j], &arr[j+1]); 
}
//Merge Sort
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k, x1, x2; 
    x1 = m - l + 1; 
    x2 = r - m; 

    int L[x1], R[x2]; 

    for (i = 0; i < x1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < x2; j++) 
        R[j] = arr[m + 1 + j]; 

    i = 0; 
    j = 0; 
    k = l; 

    while (i < x1 && j < x2) { 
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

    while (i < x1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < x2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 

        merge(arr, l, m, r); 
    } 
} 

void mergeChar(char arr[], int l, int m, int r) 
{ 
    int i, j, k, x1, x2; 
    x1 = m - l + 1; 
    x2 = r - m; 

    int L[x1], R[x2]; 

    for (i = 0; i < x1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < x2; j++) 
        R[j] = arr[m + 1 + j]; 

    i = 0; 
    j = 0; 
    k = l; 

    while (i < x1 && j < x2) { 
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

    while (i < x1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < x2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSortChar(char arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 

        mergeSortChar(arr, l, m); 
        mergeSortChar(arr, m + 1, r); 

        mergeChar(arr, l, m, r); 
    } 
}

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); } 
   


int main() {
    clock_t t;

    int number[] = { 2, 0, 1, 8, 5, 5, 5, 0, 6, 9 };
    char name[] = "ANIL YILMAZ"; 
    int n = sizeof(number) / sizeof(number[0]); 
    int charSize = strlen(name);

    t = clock();
    insertionSort(number, n);
    t = clock() - t;
    printArray(number, n); 
    printf("time for insertion sort: %lf\n", ((double)t) / CLOCKS_PER_SEC);
    insertionSortChar(name, charSize);
    t = clock() - t;
    printf("%s\n", name);
    printf("time for insertion char sort: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    

    int numX[] = { 2, 0, 1, 8, 5, 5, 5, 0, 6, 9 }; 
    char nameX[] = "ANIL YILMAZ"; 
    int x1 = sizeof(numX) / sizeof(numX[0]); 
    int charSizeX = strlen(nameX);
    selectionSort(numX, x1);
    t = clock() - t;
    printArray(numX, x1); 
    printf("time for selection sort: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    selectionSortChar(nameX, charSizeX);
    t = clock() - t;
    printf("%s\n", nameX);
    printf("time for selection char sort: %lf\n", ((double)t) / CLOCKS_PER_SEC);



    int numY[] = { 2, 0, 1, 8, 5, 5, 5, 0, 6, 9 }; 
    char nameY[] = "ANIL YILMAZ"; 
    int nY = sizeof(numY) / sizeof(numY[0]); 
    int charSizeY = strlen(nameY);

    bubbleSort(numY, nY);
    t = clock() - t;
    printArray(numY, nY); 
    printf("time for bubble sort: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    bubbleSortChar(nameY, charSizeY);
    t = clock() - t;
    printf("%s\n", nameY);
    printf("time for bubble char sort: %lf\n", ((double)t) / CLOCKS_PER_SEC);


    int numZ[] = { 2, 0, 1, 8, 5, 5, 5, 0, 6, 9 }; 
    char nameZ[] = "ANIL YILMAZ"; 
    int nZ = sizeof(numZ) / sizeof(numZ[0]); 
    int charSizeZ = strlen(nameZ);

    mergeSort(numZ, 0, nZ - 1);
    t = clock() - t;
    printArray(numZ, nZ); 
    printf("time for merge sort: %lf\n", ((double)t) / CLOCKS_PER_SEC);
    mergeSortChar(nameZ, 0, charSizeZ - 1);
    t = clock() - t;
    printf("%s\n", nameZ);
    printf("time for merge char sort: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    return 0;
} 
