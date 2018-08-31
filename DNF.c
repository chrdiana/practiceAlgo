/*
 * DNF.c: Dutch National Flag
 *
 *  Created on: Aug 21, 2018
 *      Author: dichris
 */

#include "app.h"

int swap_count=0;

int* swap (int arr[], int id1, int id2) {
	swap_count++;
	int tmp = arr[id1];
	arr[id1] = arr[id2];
	arr[id2] = tmp;
	return arr;
}

void printArray(int arr[], int size) {
	for (int i = 0; i<size; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

int* dnf (int arr[], int size, int pivot) {

	if (!arr || size == 0) {
		printf("Error: array is empty\n");
		return NULL;
	}

	if (size == 1) {
		return arr;
	}

	int start, end, small;
	start = 0;
	end = size-1;
	small = 0;

	printf("Pivot: %d\n", pivot);

	while (start <= end) {

		if (arr[start] > pivot) {
			arr = swap(arr, start, end);
			end--;
		} else if (arr[start] < pivot) {
			arr = swap(arr, small, start);
			start++;
			small++;
		} else {
			start++;
		}
	}

	return arr;
}

int testDNF () {

	int arr[] = {0};
	int len = (sizeof(arr)/sizeof(int));
	int *newarr = dnf(arr, len, 1);
	printArray(newarr, len);
	printf("Swap counts: %d\n", swap_count);
	return 0;
}
