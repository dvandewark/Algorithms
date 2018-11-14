#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void quickSort(int arr[], int min, int max);
int part(int arr[], int min, int max);

//has the same bug as mergeSort, seems like some kind of memory leak?
int main() {
	int myArray[] = {2,5,1,6,23,653,23423,76,4,23,67,21,5,3,-1,1,2,5,0,2};
	int numEls = sizeof(myArray) / sizeof(int);

	printf("Before sort: ");
	for (int i = 0; i < numEls; i++) {
		printf("%d ", myArray[i]);
	}

    clock_t start = clock();

	quickSort(myArray, 0, numEls);

    clock_t end = clock();

	printf("\nAfter sort: ");
	for (int i = 0; i < numEls; i++) {
		printf("%d ", myArray[i]);
	}
	
    double timeTaken = (double)(end-start) / CLOCKS_PER_SEC;
	printf("\nTaking %f seconds\n", timeTaken);

    return 0;
}


void quickSort(int arr[], int min, int max) {
    if (min < max) {
        int p = part(arr, min, max);
        quickSort(arr, min, p);
        quickSort(arr, p+1, max);
    }
}

//for quicksort
int part(int arr[], int min, int max) {
    int pivot = arr[min];
    int i = min-1;
    int j = max+1;

    while (true) {
        do {
            i++; //find largest leftmost element
        } while (arr[i] < pivot);

        do {
            j--; //find smallest rightmost element
        } while (arr[j] > pivot);

        //index where pointers meet
        if (i >= j) {
            return j;
        }

        //swap elements
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


