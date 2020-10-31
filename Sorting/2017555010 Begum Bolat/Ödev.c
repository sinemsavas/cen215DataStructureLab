#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

/* Insertion Sort */
void insertionNumber(int num[], int n)
{
	int i,j,key;
	for(i = 1 ;i<n;i++)
	{
		key = num[i];
		j = i-1;
		while (j >= 0 && num[j] > key)
		{
			num [j+1] = num [j];
			j -=1;
		}
		num [j+1]=key;
	}
}

void insertionName(char name[], int n)
{
	int i,j,key;
	for(i = 1 ;i<n;i++)
	{
		key = name[i];
		j = i-1;
		while (j >= 0 && name[j] > key)
		{
			name [j+1] = name [j];
			j -=1;
		}
		name [j+1]=key;
	}
}

void swapNumber(int *num1, int *num2)  
{  
    int temp = *num1;  
    *num1 = *num2;  
    *num2 = temp;  
}  

void swapName(int *let1, int *let2) // let=letter
{  
    int temp = *let1;  
    *let1 = *let2;  
    *let2 = temp;  
}  

/* Selection Sort */
void selectionNumber(int num[], int n)
{
	int i,j,key;
	for(i=0;i<n-1;i++)
	{
		key = i;
		for(j=i+1; j<n ;j++)
		{
			if(num[j]< num[i])
				key = j;
		}
		swapNumber(&num[key],&num[i]);
	}
}

void selectionName(char name[], int n)
{
	int i,j,key;
	for(i=0;i<n-1;i++)
	{
		key = i;
		for(j=i+1;j<n;j++)
		{
			if(name[j]<name[i])
				key = j;
		}
		swapName(&name[key],&name[i]);
	}
}

/* Merge Sort */
void merge(int num[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid-left+1; 
    int n2 = right-mid; 
    int L[n1], R[n2]; 
 
    for (i=0;i<n1;i++) 
        L[i] = num[left+i]; 
    for (j=0;j<n2;j++) 
        R[j] = num[mid+1+j]; 
    i = 0;
    j = 0;
    k = left; 
    while (i<n1 && j<n2) 
	{ 
        if (L[i] <= R[j]){ 
            num[k]=L[i]; 
            i++; 
        } 
        else{ 
            num[k]=R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i<n1) 
	{ 
        num[k]=L[i]; 
        i++; 
        k++; 
    } 
 
    while (j<n2) 
	{ 
        num[k]=R[j]; 
        j++; 
        k++; 
    } 
} 
 
void mergeNumber(int num[], int left, int right) 
{ 
    if (left<right) 
	{ 
        int mid=left+(right-left)/2; 
        mergeNumber(num,left,mid); 
        mergeNumber(num,mid+1,right); 
        merge(num,left,mid,right); 
    } 
} 
void mergeSName(char name[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid-left+1; 
    int n2 = right-mid; 
    int L[n1], R[n2]; 
 
    for (i=0;i<n1;i++) 
        L[i] = name[left+i]; 
    for (j=0;j<n2;j++) 
        R[j] = name[mid+1+j]; 
    i = 0;
    j = 0;
    k = left; 
    while (i<n1 && j<n2) 
	{ 
        if (L[i] <= R[j]){ 
            name[k]=L[i]; 
            i++; 
        } 
        else{ 
            name[k]=R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i<n1) 
	{ 
        name[k]=L[i]; 
        i++; 
        k++; 
    } 
 
    while (j<n2) 
	{ 
        name[k]=R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeName(char name[], int left, int right) 
{ 
    if (left<right) 
	{ 
        int mid=left+(right-left)/2; 
        mergeName(name,left,mid); 
        mergeName(name,mid+1,right); 
        mergeSName(name,left,mid,right); 
    } 
} 

/* Bubble Sort */
void bubbleNumber(int num[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(num[j]>num[j+1])
			{
				swapNumber(&num[i],&num[j]);
			}
		}
	}
}

void bubbleName(char name[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<j-i-1;j++)
		{
			if(name[j]>name[j+1])
			{
				swapName(&name[i],&name[j]);
			}
		}
	}
}

int main()
{
	int number [] = {2,0,1,7,5,5,5,0,1,0};
	char name [] = "begum bolat";
	int s_number = sizeof(number) / sizeof(number[0]);
	int s_name = strlen(name);
	
	clock_t start,end;
	double time_used;
	
	// Insertion Sort
	start = clock();
	insertionNumber(number,s_number);	
	printf("Insertion Sort number array:\t"); 
	printArray(number,s_number);
	
	insertionName(name,s_name);
	printf("Insertion Sort name array: %s\n",name);
	end = clock();
	time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Insertion Sort time:%f\n",time_used);
	
	// Selection Sort
	start = clock();
	selectionNumber(number, s_number); 
    printf("\nSelection Sort number array:\t"); 
    printArray(number, s_number); 

    selectionName(name,s_name);
    printf("Selection Sort name array: %s\n",name);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort time:%f\n",time_used);
    
    //Merge Sort
    start = clock();
    mergeNumber(number, 0, s_number-1);
	printf("\nMerge Sort number array:\t");
	printArray(number,s_number);
	
	mergeName(name, 0 ,s_name-1);
	printf("Merge Sort name array: %s\n",name);
	end = clock();
	time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
	printf("Merge Sort time:%f\n",time_used);
	
	//Bubble Sort
	start = clock();
    bubbleNumber(number,s_number);
    printf( "\nBubble Sort number array:\t");
    printArray(number,s_number);
    
    bubbleName(name,s_name);
    printf("Bubble Sort name array:%s\t",name);
    end = clock();
    time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    printf("\nBubble Sort time:%f",time_used);
    
	return 0;
}
