#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

void printArray(int array[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
     printf("\n");
}
void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

//Insertion Sort
void insertion_sort(int array[], int size)
{
    int i, index, j;
    for (i = 1; i < size; i++) {
        index = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > index) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = index;
    }
}
void insertion_sort_char(char array[], int size)
{
    int i, j;
    char index;
    for(i = 1; i < size; i++) {
        index = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > index) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = index;
    }
}

//Selection Algorithm
void selection_sort(int arr[], int size)
{
    int i, j, min;
    for (i = 0; i < size-1; i++)
    {
        min = i;
        for (j = i+1; j < size; j++)
          if (arr[j] < arr[min])
            min = j;
        swap(&arr[min], &arr[i]);
    }
}

void selection_sort_char(char array[], int size)
{
    int i, j;
    char min;
    for (i = 0; i < size-1; i++)
    {
        min = i;
        for (j = i+1; j < size; j++)
          if (array[j] < array[min])
            min = j;
        swap_char(&array[min], &array[i]);
    }
}

// Merge sort
void merge(int array[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int array[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);
 
        merge(array, l, m, r);
    }
}
 
void merge_char(char arr[], int x, int y, int z)
{
    int i, j, k, n1, n2;
    n1 = y - x + 1;
    n2 = z - y;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[x + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[y + 1 + j];
 
    i = 0;
    j = 0;
    k = x;

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

void merge_sort_char(char arr[], int x, int y)
{
    if (x < y) {
        int m = x + (y - x) / 2;
 
        merge_sort_char(arr, x, m);
        merge_sort_char(arr, m + 1, y);
 
        merge_char(arr, x, m, y);
    }
}
// Bubble Sort
void bubble_sort(int array[], int size)
{
   int i, j;
   for (i = 0; i < size-1; i++)
       for (j = 0; j < size-i-1; j++)
           if (array[j] > array[j+1])
              swap(&array[j], &array[j+1]);
}


void bubble_sort_char(char array[], int size)
{
   int i, j;
   for (i = 0; i < size-1; i++)
       for (j = 0; j < size-i-1; j++)
           if (array[j] > array[j+1])
               swap_char(&array[j], &array[j+1]);
}
int main() {
 
    printf("Mertay AKTAS\n2018555003\n\n\n");
    clock_t time123;

    //Selection Sort
    
    int ogrenci_no[] = { 2, 0, 1, 8, 5, 5, 5, 0, 0, 3 };
    char name[] = "mertay aktas";
    int size = sizeof(ogrenci_no) / sizeof(ogrenci_no[0]);
    int char_size = strlen(name);

    time123 = clock();
    insertion_sort(ogrenci_no, size);
    time123 = clock() - time123;
    printArray(ogrenci_no, size);
    printf("insertion sorting time: %f\n", ((double)time123)/ CLOCKS_PER_SEC);
    insertion_sort_char(name, char_size);
    time123 = clock() - time123;
    printf("%s\n", name);
    printf("insertion char sorting time: %f\n", ((double)time123) / CLOCKS_PER_SEC);

    //Selection Sort
    
    selection_sort(ogrenci_no, size);
    time123= clock() - time123;
    printArray(ogrenci_no, size);
    printf("selection sorting time: %f\n", ((double)time123) / CLOCKS_PER_SEC);
    
    selection_sort_char(name, char_size);
    time123 = clock() - time123;
    printf("%s\n", name);
    printf("selection char sorting time: %f\n", ((double)time123) / CLOCKS_PER_SEC);

    
    //Merge Sort
    
    merge_sort(ogrenci_no, 0, size - 1);
    time123= clock() - time123;
    printArray(ogrenci_no, size);
    printf("merge sorting time: %f\n", ((double)time123) / CLOCKS_PER_SEC);
    merge_sort_char(name, 0, char_size - 1);
    time123 = clock() - time123;
    printf("%s\n", name);
    printf("merge char sorting time: %f\n", ((double)time123) / CLOCKS_PER_SEC);
    
    //Bubble Sort
  
    bubble_sort(ogrenci_no, size);
    time123 = clock() - time123;
    printArray(ogrenci_no, size);
    printf("bubble sorting time: %f\n", ((double)time123) / CLOCKS_PER_SEC);

    bubble_sort_char(name, char_size);
     time123= clock() - time123;
    printf("%s\n", name);
    printf("bubble char sorting time: %f\n", ((double)time123) / CLOCKS_PER_SEC);
    return 0;
}
