#include <stdio.h>

int partition(int *A, int low, int high)
{
	int i = low-1, j = 0;
	int pivot = A[high];
	int temp = 0;
	
	for(j=low; j < high; j++){
		if (A[j] <= pivot){
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	temp = A[i+1];
	A[i+1] = A[high];
	A[high] = temp;
	return i+1;
}

void quickSort(int *A, int low, int high)
{
	int pivot = 0;

	if(low <= high){
		pivot = partition(A, low, high);
		quickSort(A, low, pivot-1);
		quickSort(A, pivot+1, high);
	}	
}

int main(int argc, char *argv[]) {
	int A[10] = {1, 5, 0, 4, 7, 2, 8, 3, 6, 9};
	
	quickSort(A, 0, 9);
	printf("Quick Sort\n");
	for(int i = 0; i < 10; i++){
		printf("%d ", A[i]);
	}
}
