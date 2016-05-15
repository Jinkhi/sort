#include <stdio.h>
#include <stdlib.h>

#define MAX 99999

void merge(int *A, int low, int mid, int high){
	int *B = NULL, *C = NULL;
	int len1 = mid - low + 1;
	int len2 = high - mid;
	
	B = (int *)malloc(sizeof(int) * (len1 + 1));
	C = (int *)malloc(sizeof(int) * (len2 + 2));
	
	for(int i = 0; i < len1; i++){
		B[i] = A[low + i];
	}	
	B[len1] = MAX;
	
	for(int j = 0; j < len2; j++){
		C[j] = A[mid + j + 1];
	}
	C[len2] = MAX;
	
	int i = 0, j = 0, k = low;
	while((i < len1) && (j < len2)){
		if((B[i] <= C[j])){
			A[k] = B[i];
			i++;
		} else{
			A[k] = C[j];
			j++;
		}
		k++;
	}
	
	while(i < len1){
		A[k] = B[i];
		i++;
		k++;
	}
	
	while(j < len2){
		A[k] = C[j];
		j++;
		k++;
	}
	
	free(B);
	free(C);
}

void mergeSort(int *A, int low, int high){
	int mid = 0;
	
	if(low < high){
		mid = (low + high)/2;
		mergeSort(A, low, mid);
		mergeSort(A, mid+1, high);
		merge(A, low, mid, high);
	}
}

int main(){
	int A[10] = {3, 2, 0, 1, 6, 5, 8, 7, 9, 4};
	mergeSort(A, 0, 9);
	
	printf("Merge Sort\n");
	for(int i = 0; i < 10; i++){
		printf("%d ", A[i]);
	}
	
	return 0;
}
