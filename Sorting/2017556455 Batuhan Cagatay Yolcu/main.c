#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    int i, x, j;
    for (i = 1; i < n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
    }
}
void insertionSortCh(char arr[], int n)
{
    int i, j;
    char x;
    for (i = 1; i < n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
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

void swapCh(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
    }
}

void selectionSortCh(char arr[], int n)
{
    int i, j;
    char min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swapCh(&arr[min], &arr[i]);
    }
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void bubbleSortCh(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapCh(&arr[j], &arr[j + 1]);
}
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

    while (i < x1 && j < x2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < x1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < x2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void mergeCh(char arr[], int l, int m, int r)
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

    while (i < x1 && j < x2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < x1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < x2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortCh(char arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortCh(arr, l, m);
        mergeSortCh(arr, m + 1, r);

        mergeCh(arr, l, m, r);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    clock_t t;

    int ID[] = {2, 0, 1, 7, 5, 5, 6, 4, 5, 5};
    char name[] = "batuhan cagatay yolcu";
    int n = sizeof(ID) / sizeof(ID[0]);
    int charSize = strlen(name);

    t = clock();
    insertionSort(ID, n);
    t = clock() - t;
    printArray(ID, n);
    printf("insertion sort time: %lf\n", ((double)t) / CLOCKS_PER_SEC);
    insertionSortCh(name, charSize);
    t = clock() - t;
    printf("%s\n", name);
    printf("insertion char sort time: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    int IDX[] = {2, 0, 1, 7, 5, 5, 6, 4, 5, 5};
    char namex[] = "batuhan cagatay yolcu";
    int x1 = sizeof(IDX) / sizeof(IDX[0]);
    int charSizeX = strlen(namex);
    selectionSort(IDX, x1);
    t = clock() - t;
    printArray(IDX, x1);
    printf("selection sort time: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    selectionSortCh(namex, charSizeX);
    t = clock() - t;
    printf("%s\n", namex);
    printf("selection char sort time: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    int IDY[] = {2, 0, 1, 7, 5, 5, 5, 4, 5, 5};
    char namey[] = "batuhan cagatay yolcu";
    int nY = sizeof(IDY) / sizeof(IDY[0]);
    int charSizeY = strlen(namey);

    bubbleSort(IDY, nY);
    t = clock() - t;
    printArray(IDY, nY);
    printf("bubble sort time: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    bubbleSortCh(namey, charSizeY);
    t = clock() - t;
    printf("%s\n", namey);
    printf("bubble char sort time: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    int IDZ[] = {2, 0, 1, 7, 5, 5, 6, 4, 5, 5};
    char namez[] = "batuhan cagatay yolcu";
    int nZ = sizeof(IDZ) / sizeof(IDZ[0]);
    int charSizeZ = strlen(namez);

    mergeSort(IDZ, 0, nZ - 1);
    t = clock() - t;
    printArray(IDZ, nZ);
    printf("merge sort time: %lf\n", ((double)t) / CLOCKS_PER_SEC);
    mergeSortCh(namez, 0, charSizeZ - 1);
    t = clock() - t;
    printf("%s\n", namez);
    printf("merge char sort time: %lf\n", ((double)t) / CLOCKS_PER_SEC);

    return 0;
}