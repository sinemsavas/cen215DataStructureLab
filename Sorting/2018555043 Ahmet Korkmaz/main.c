#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
void exchange(int* a, int* b);
void exchange_char(char* a, char*b);
long current_time();

void show(int Array[],int size);
void show_char(char Array[],int size);

void bubblesort(int bubblesort_array[], int number_of_elements);
void bubblesort_char(char Array[],int number_of_elements);

void selectionsort(int insertionsort_array[],int number_of_elements);
void selectionsort_char(char Array[],int number_of_elements);

void insertionsort(int Array[],int number_of_elements);
void insertionsort_char(char Array[], int number_of_elements);

void merge(int arr[], int left, int m, int right);
void mergesort(int Array[], int left, int right);

void merge_char(char Array[], int start, int mid, int end);
void mergesort_char(char Array[], int start, int end);


long int start_point;
long int stop_point;

void Array_copy(int Array[],int Array2[],int size);
void Array_copy_char(char Array[],char Array2[],int size);

int main()
{
    int school_number[] = {2,0,1,8,5,5,5,0,4,3};
    int number_of_elements = sizeof(school_number) / sizeof(int);

    int number_array[number_of_elements];
    Array_copy(school_number,number_array,number_of_elements);

    printf("-------------------------------------\n");

    bubblesort(number_array, number_of_elements);
    Array_copy(school_number,number_array,number_of_elements);

    printf("-------------------------------------\n");

    selectionsort(number_array,number_of_elements);
    Array_copy(school_number,number_array,number_of_elements);

    printf("-------------------------------------\n");

    insertionsort(number_array,number_of_elements);
    Array_copy(school_number,number_array,number_of_elements);

    printf("-------------------------------------\n");

    start_point = current_time();
    mergesort(number_array,0,number_of_elements-1);
    stop_point = current_time();
    printf("Mergesort algoritm running time %f\n", ((double)(stop_point - start_point))/ CLOCKS_PER_SEC);
    show(number_array,number_of_elements);
    printf("\n");

    printf("-------------------------------------\n");


    char name[] = "AhmetKORKMAZ"; 
    char name_array[sizeof(name)];
    Array_copy_char(name,name_array,sizeof(name));

    printf("-------------------------------------\n");

    bubblesort_char(name_array, strlen(name));
    Array_copy_char(name,name_array,sizeof(name));

    printf("-------------------------------------\n");

    selectionsort_char(name_array,strlen(name));
    Array_copy_char(name,name_array,sizeof(name));

    printf("-------------------------------------\n");

    insertionsort_char(name_array,strlen(name));
    Array_copy_char(name,name_array,sizeof(name));

    printf("-------------------------------------\n");

    start_point = current_time();
    mergesort_char(name_array,0,strlen(name_array)-1);
    stop_point = current_time();
    printf("Mergesort algoritm running time %f\n", ((double)(stop_point - start_point))/ CLOCKS_PER_SEC);
    show_char(name_array,strlen(name_array));
    printf("\n");

    printf("-------------------------------------\n");
}
void Array_copy(int Array[],int Array2[],int size)
{
    for(int i = 0;i<size;i++)
        Array2[i] = Array[i];
}

void Array_copy_char(char Array[],char Array2[],int size)
{
    for(int i = 0;i<size;i++)
        Array2[i] = Array[i];
}

void show(int Array[],int size)
{
    for(int i =0;i<size;i++)
    {
        printf("%d ",Array[i]);
    }
}

void show_char(char Array[],int size)
{
    for(int i =0;i<size;i++)
    {
        printf("%c ",Array[i]);
    }
}

void exchange(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exchange_char(char* a, char*b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

long current_time()
{
    return clock();
}

void bubblesort(int bubblesort_array[], int number_of_elements)
{
    start_point = current_time();
    for (int i = 0; i < number_of_elements; i++)
    {
        for (int j = 0; j < number_of_elements-1; j++)
        {
            if (bubblesort_array[j] > bubblesort_array[j + 1])
            {
                exchange(&bubblesort_array[j], &bubblesort_array[j + 1]);
            }
        }
    }

    stop_point = current_time();
    printf("Bubblesort algoritm running time %f\n", ((double)(stop_point - start_point))/ CLOCKS_PER_SEC);
    show(bubblesort_array,number_of_elements);
    printf("\n");
}

void bubblesort_char(char Array[],int number_of_elements)
{
    start_point = current_time();
    for(int i = 0;i< number_of_elements;i++)
    {
        for(int j = 0;j<number_of_elements-1;j++)
        {
            int minus = 0;
            if(Array[j] > 96)
                minus = 32;

            int minus2 = 0;
            if(Array[j+1] > 96)
                minus2 = 32;

            if(Array[j]-minus > Array[j+1]-minus2)
            exchange_char(&Array[j], &Array[j+1]);
        }
    }
    stop_point = current_time();
    printf("Bubblesort algoritm running time %f\n", ((double)(stop_point - start_point))/ CLOCKS_PER_SEC);
    show_char(Array, number_of_elements);
    printf("\n");
}

void selectionsort(int Array[],int number_of_elements)
{
    start_point = current_time();
    for(int i = 0;i<number_of_elements;i++)
    {
        int smallest_index = i;

        for(int j = i;j < number_of_elements;j++)
        {   // Do something in the right part.
            if(Array[j] < Array[smallest_index])
            smallest_index = j;
        }

        exchange(&Array[smallest_index], &Array[i]);
    }
    stop_point = current_time();
    printf("Selectionsort algoritm running time %f\n", ((double)(stop_point - start_point))/ CLOCKS_PER_SEC);

    show(Array, number_of_elements);
    printf("\n");
  
}

void selectionsort_char(char Array[],int number_of_elements)
{
    start_point = current_time();
    for(int i = 0;i<number_of_elements;i++)
    {
        int smallest_index = i;

        for(int j = i;j<number_of_elements;j++)
        {
            int minus = 0;
            if(Array[j] > 96)
                minus = 32;

            int minus2 = 0;
            if(Array[smallest_index] >96)
                minus2 = 32;

            if(Array[j]-minus < Array[smallest_index]-minus2)
                smallest_index = j;

        }
        exchange_char(&Array[i],&Array[smallest_index]);
    }
    stop_point = current_time();
    printf("Selectionsort algoritm running time %f\n", ((double)(stop_point - start_point))/ CLOCKS_PER_SEC);
    show_char(Array, number_of_elements);
    printf("\n");
}

void insertionsort(int Array[],int number_of_elements)
{
    int sorted[number_of_elements];
    sorted[0] = Array[0];
    start_point = current_time();
    for(int i = 1;i<number_of_elements;i++)
    {
        int extract = Array[i];
        int point = i;
       
        for(int j = i;j >=0;j--)
            if(sorted[j] > extract)
                point = j;


        int temp = sorted[point];

        for(int j = i;j > point;j--)
            sorted[j] = sorted[j-1];

        sorted[point] = extract;
    }
    stop_point = current_time();
    printf("Insertionsort algoritm running time %f\n", ((double)(stop_point - start_point))/ CLOCKS_PER_SEC);
    show(sorted,number_of_elements);
    printf("\n");
    
}

void insertionsort_char(char Array[], int number_of_elements)
{
    char sorted[number_of_elements];
    sorted[0] = Array[0];
    start_point = current_time();

    for(int i = 1;i<number_of_elements;i++)
    {
        char extract = Array[i];
        int point = i;

        for(int j=i;j>=0;j--)
        {
            int minus = 0;
            if(sorted[j] > 96)
                minus = 32;

            int minus2 = 0;
            if(extract > 96)
                minus2 = 32;

            if(sorted[j]-minus > extract-minus2)
                point = j;
        }

        char temp = sorted[point];

        for(int j = i;j>point;j--)
            sorted[j] = sorted[j-1];

        sorted[point] = extract;
    }
    stop_point = current_time();
    printf("Insertionsort algoritm running time %f\n", ((double)(stop_point - start_point))/ CLOCKS_PER_SEC);
    show_char(sorted,number_of_elements);
    printf("\n");
}

void merge(int arr[], int left, int m, int right) 
{ 
    int i, j, k; 
    int n1 = m - left + 1; 
    int n2 = right - m; 
 
    int L[n1], R[n2]; 
 
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
 
    
    i = 0; 
    j = 0; 
    k = left; 
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

void mergesort(int Array[], int left, int right) 
{  
    if (left < right) 
    { 
        int m = left + (right - left) / 2; 

        mergesort(Array, left, m); 
        mergesort(Array, m + 1, right); 
        merge(Array, left, m, right); 
    }
}

void merge_char(char Array[], int start, int mid, int end) 
{
	int temp[end - start + 1];
	int x = start, y = mid+1, k = 0;

	while(x <= mid && y <= end) 
    {
        int minus = 0;
        if(Array[x] > 96)
            minus = 32;

        int minus2 = 0;
        if(Array[y] > 96)
            minus2 = 32;
        
		if(Array[x] - minus <= Array[y] - minus2) 
        {
			temp[k] = Array[x];
			k += 1; x+= 1;
		}
		else 
        {
			temp[k] = Array[y];
			k += 1; y += 1;
		}
	}
	while(x <= mid) 
    {
		temp[k] = Array[x];
		k += 1; x += 1;
	}

	while(y <= end) 
    {
		temp[k] = Array[y];
		k += 1; y += 1;
	}

	for(x = start; x <= end; x += 1) 
    {
		Array[x] = temp[x - start];
	}
}

void mergesort_char(char Array[], int start, int end) 
{
	if(start < end) 
    {
		int mid = (start + end) / 2;
		mergesort_char(Array, start, mid);
		mergesort_char(Array, mid+1, end);
		merge_char(Array, start, mid, end);
	}
}