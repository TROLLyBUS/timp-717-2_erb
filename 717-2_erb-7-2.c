#include <stdio.h>
#include <stdlib.h>

void dxwn(int arr[], int stxrt, int wh) {
	int max = 0, t = 0;
	while ((stxrt * 2 + 1 <= wh) && (!t)) {
		if (stxrt * 2 + 1 == wh) {
			max = stxrt * 2 + 1;
		}
		else if (arr[stxrt * 2 + 1] > arr[stxrt * 2 + 2]) {
			max = stxrt * 2 + 1;
		}
		else {
			max = stxrt * 2 + 2;
		}
		if (arr[stxrt] < arr[max]) {
			int temp = arr[stxrt];
			arr[stxrt] = arr[max];
			arr[max] = temp;
			stxrt = max;
		}
		else t = 1;
	}
}

void pyrxsxrt(int arr[], int arr_len) { //Armen xD
	int temp = 0;
	for (int i = (arr_len / 2) - 1; i >= 0; --i) {
		dxwn(arr, i, arr_len - 1);
	}
	for (int i = arr_len - 1; i >= 1; --i) {
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		dxwn(arr, 0, i - 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
	}
	pyrxsxrt(arr, n);
	for (int i = 0; i < n; ++i){
		printf("%d", arr[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	printf("\n");
	
	return 0;
}
