#include<stdio.h>
#include<time.h>
#include<math.h>

int argc;
char argv[100];
int min;

//print functions


void printarray(int array[]) {
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n");

}
void printchararray(char array[]) {
	int i;
	//sondaki NULL karakteri almamas� i�in i'yi 1'den ba�latt�m.
	for (i = 1; i < 11; i++) {
		printf("%c\t ", array[i]);
	}
	printf("\n");
}
void printarraymergesort(int array[],int size){
	int i;
	for (i = 0; i < size; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n");

}
void printarraymergesortchar(char array[],int size){
	int i;
	for (i = 0; i < size; i++) {
		printf("%c\t", array[i]);
	}
	printf("\n");

}

//insertionsort functions

void insertionsort(int array[]) {
	int i, j;
	for (i = 1; i < 10; i++) {
		argc = array[i];
		j = i - 1;
		while (argc < array[j] && j >= 0) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = argc;
	}

}
void insertionsortchar(char array[]) {
	int i, j;
	char argc;
	for (i = 1; i < 11; i++) {
		argc = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > argc) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = argc;
	}
}

//selectionsort functions

void selectionsort(int array[]) {
	int i, j,temp;
	for (i = 0; i < 9; i++) {
		min = i;
		for (j = i + 1; j < 10; j++) {
			if (array[j] < array[min])
				min = j;
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}
void selectionsortchar(char array[]) {
	int i, j, temp;
	for (i = 0; i < 9; i++) {
		min = i;
		for (j = i + 1; j < 10; j++) {
			if (array[j] < array[min])
				min = j;
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	
}
}

//bubblesort functions

void bubblesort(int array[]) {
	int i, j, temp;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
void bubblesortchar(char array[]) {
	int i, j, temp;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}


//mergesort functions

void mergechar(char array[],int l,int m,int r){
	int i,j,k,n1,n2;
	n1=m-l+1;
	n2=r-m;
	
	int L[n1], R[n2];
	
	for(i=0;i<n1;i++){
	
	L[i]=array[l+i];}
	
	for(j=0;j<n2;j++){
	
	R[j]=array[m+1+j];}
	
	i=0;j=0;k=l;
	
	while(i<n1&&j<n2){
		if (L[i]<=R[j]){
		
		array[k]=L[i];
		i++;
	}
	else{
		array[k]=R[j];
		j++;
	}
	k++;}
	while(i<n1){
		array[k]=L[i];
		k++;
		i++;
	
	}
	while(j<n2){
		array[k]=R[j];
		k++;
		j++;
	}
}
void mergesortchar(char array[],int l,int r){
if(l<r){
	int m=(l+r)/2;
	mergesortchar(array,l,m);
	mergesortchar(array,m+1,r);
	mergechar(array,l,m,r);
}
}
void merge(int array[],int l,int m,int r){
	int i,j,k,n1,n2;
	n1=m-l+1;
	n2=r-m;
	
	int L[n1], R[n2];
	
	for(i=0;i<n1;i++){
	
	L[i]=array[l+i];}
	
	for(j=0;j<n2;j++){
	
	R[j]=array[m+1+j];}
	
	i=0;j=0;k=l;
	
	while(i<n1&&j<n2){
		if (L[i]<=R[j]){
		
		array[k]=L[i];
		i++;
	}
	else{
		array[k]=R[j];
		j++;
	}
	k++;}
	while(i<n1){
		array[k]=L[i];
		k++;
		i++;
	
	}
	while(j<n2){
		array[k]=R[j];
		k++;
		j++;
	}
}
void mergesort(int array[],int l,int r){

if(l<r){
	int m=(l+r)/2;
	mergesort(array,l,m);
	mergesort(array,m+1,r);
	merge(array,l,m,r);
}
}

// main function

int main() {
	
	clock_t start,end;
	double time_used;
	
	int num[] = { 2,0,1,8,5,5,6,0,6,7 };
	char name[] = "Ceren Ulus";
	int size = sizeof(num) / sizeof(num[0]);
	
	printf("**num to be listed: 2018556067. \n");
	printf("**name to be listed: Ceren Ulus. \n\n");
	
	//instertionsort
	printf("******The insertionsort order*****\n");
	start = clock();
	insertionsort(num);
	printarray(num);
    

	insertionsortchar(name);
	printchararray(name);
	end = clock();
	time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Insertion Sort time:%f\n\n",time_used);
	
	//selectionsort

    printf("*****The selectionsort order*****\n");
    start=clock();
	selectionsort(num);
	printarray(num);

	
	selectionsortchar(name);
	printchararray(name);
	end = clock();
	time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("selection Sort time:%f\n\n",time_used);
	
	//bubblesort
	

    printf("*****The bubblesort order*****\n");
     start=clock();
	bubblesort(num);
	printarray(num);


	bubblesortchar(name);
	printchararray(name);
	end = clock();
	time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("bubble Sort time:%f\n\n",time_used);
	
	//mergesort
	

    printf("*****The mergesort order*****\n");
    start=clock();
    mergesort(num,0,size-1);
	printarraymergesort(num,size);
	
	mergesortchar(name,0,size-1);
	printarraymergesortchar(name,size+1);
	end = clock();
	time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("merge Sort time:%f\n\n",time_used);

	

	return 0;
}
