#include <stdio.h>

void mergeSort(int toSort[], int min, int max);
void merge(int arr[], int min1, int max1, int min2, int max2);

int main() {
	
	int myArray[] = {2,5,1,6,23,653,23423,76,4,23,67,21,5,3,0,1,2,5,2,2};
	int numEls = sizeof(myArray) / sizeof(int);

	printf("Before sort: ");
	for (int i = 0; i < numEls; i++) {
		printf("%d ", myArray[i]);
	}

	mergeSort(myArray, 0, numEls);

	printf("\nAfter sort: ");
	for (int i = 0; i < numEls; i++) {
		printf("%d ", myArray[i]);
	}
	
	printf("\n");
	return 0;
}

void mergeSort(int toSort[], int min, int max) {
	int mid;

	if (min < max) {
		mid = (min + max)/2;

		//split into left and right subarrays
		mergeSort(toSort, min, mid);
		mergeSort(toSort, mid+1, max);

		//merge two sorted subarrays
		merge(toSort,min,mid,mid+1,max);
	}
}

void merge(int arr[], int min1, int max1, int min2, int max2) {
	int temp[(max1-min1)+(max2-min2)+1];
	/*int num = sizeof(temp) / sizeof(int);
    printf("\n############# %d\n", num);
    for (int i = 0; i < (max1-min1)+(max2-min2); i++) {
		printf("%d ", temp[i]);
	}*/
	int i = min1;
	int j = min2;
	int k = 0;

	//merge the two subarrays into a sorted temp array
	while (i <= max1 && j<= max2) {
		if (arr[i]<arr[j]) {
			temp[k] = arr[i];
            k++;
            i++;
		} else {
			temp[k] = arr[j];
            k++;
            j++;
		}
	}

	//copy any leftover elements to the temp array
	while (i <= max1) { 
        temp[k] = arr[i]; 
        k++;
        i++;
    }

	while (j <= max2) { 
        temp[k] = arr[j]; 
        k++;
        j++;
    }

	//copy contents of temp to arr
	for (i = min1, j = 0; i <= max2; i++,j++) {
		arr[i] = temp[j];
	}
}







