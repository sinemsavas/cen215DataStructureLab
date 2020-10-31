#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sys/time.h> /* We cannot use the <sys/time.h> library in visual studio. */



void id_print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)

        printf("%d", arr[i]);
    printf("\n");
}


void name_print(char string[])
{
    printf("%s\n", string);
}


void insertion_id_sort(int arr[], int n)
{
    int i, k, j;
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }

}


void insertion_name_sort(char string[], int m)
{
    int i, k, j;
    for (i = 1; i < m; i++)
    {
        k = string[i];
        j = i - 1;

        while (j >= 0 && string[j] > k) {
            string[j + 1] = string[j];
            j = j - 1;
        }
        string[j + 1] = k;
    }

}


void bubble_id_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}


void bubble_name_sort(char string[], int m)
{
    int i, j;
    for (i = 0; i < m - 1; i++)
        for (j = 0; j < m - i - 1; j++)
            if (string[j] > string[j + 1])
                swap(&string[j], &string[j + 1]);
}


void selection_id_sort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++)
    { 
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}


void selection_name_sort(char string[], int m)
{
    int i, j, min_idx;
 
    for (i = 0; i < m - 1; i++)
    { 
        min_idx = i;
        for (j = i + 1; j < m; j++)
            if (string[j] < string[min_idx])
                min_idx = j;
 
        swap(&string[min_idx], &string[i]);
    }
}


void merge_id(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // When we divide the main array into smaller arrays, 
    // we need to make a left and right subarray.
    // Visual studio gives error when trying to do this.

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
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


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void merge_name(char string[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
        L[i] = string[l + i];
    for (j = 0; j < n2; j++)
        R[j] = string[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            string[k] = L[i];
            i++;
        }
        else
        {
            string[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        string[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        string[k] = R[j];
        j++;
        k++;
    }
}


void merge_id_sort(int arr[], int l, int r)
{
    if (l < r)
    {
         
        int m = l + (r - l) / 2;

        merge_id_sort(arr, l, m);
        merge_id_sort(arr, m + 1, r);

        merge_id(arr, l, m, r);
    }
}


void merge_name_sort(char string[], int l, int r)
{
    if (l < r)
    {
        
        int m = l + (r - l) / 2;

        merge_name_sort(string, l, m);
        merge_name_sort(string, m + 1, r);

        merge_name(string, l, m, r);
    }
}


void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


int main(void)
{

    int arr[] = { 2,0,1,8,5,5,5,0,5,7 }; /* id */
    char string[] = "utkubarisselcuk"; /* name */

    printf("\nID = 2018555057\n");
    printf("NAME = Utku Barış Selçuk\n");


    int n = sizeof(arr) / sizeof(arr[0]);
    int m = strlen(string);
    
    struct timeval stop, start;

    /* -----> INSERTION ID SORT <----- */

    gettimeofday(&start, NULL);

    insertion_id_sort(arr, n);
    printf("\ninsertion -> ");
    id_print(arr, n);

    gettimeofday(&stop, NULL);
    printf("took -> %lu microseconds\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
    
    /* -----> INSERTION NAME SORT <----- */

    gettimeofday(&start, NULL);

    insertion_name_sort(string, m);
    printf("insertion -> ");
    name_print(string);

    gettimeofday(&stop, NULL);
    printf("took -> %lu microseconds\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    /* -----> BUBBLE ID SORT <----- */

    gettimeofday(&start, NULL);

    bubble_id_sort(arr, n);
    printf("\nbubble -> ");
    id_print(arr, n);
    
    gettimeofday(&stop, NULL);
    printf("took -> %lu microseconds\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    /* -----> BUBBLE NAME SORT <----- */

    gettimeofday(&start, NULL);

    bubble_name_sort(string, m);
    printf("bubble -> ");
    name_print(string);

    gettimeofday(&stop, NULL);
    printf("took -> %lu microseconds\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    /* -----> SELECTION ID SORT <----- */

    gettimeofday(&start, NULL);

    selection_id_sort(arr, n);
    printf("\nselection -> ");
    id_print(arr, n);

    gettimeofday(&stop, NULL);
    printf("took -> %lu microseconds\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    /* -----> SELECTION NAME SORT <----- */

    gettimeofday(&start, NULL);

    selection_name_sort(string, m);
    printf("selection -> ");
    name_print(string);
    
    gettimeofday(&stop, NULL);
    printf("took -> %lu microseconds\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    /* -----> MERGE ID SORT <----- */

    gettimeofday(&start, NULL);

    merge_id_sort(arr,0,n-1);
    printf("\nmerge -> ");
    id_print(arr, n);

    gettimeofday(&stop, NULL);
    printf("took -> %lu microseconds\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    /* -----> MERGE NAME SORT <----- */

    gettimeofday(&start, NULL);

    merge_name_sort(string,0,m-1);
    printf("merge -> ");
    name_print(string);

    gettimeofday(&stop, NULL);
    printf("took -> %lu microseconds\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    return 0;

}
