#include <stdio.h>
#include <stdlib.h>

void qxcksxrt(int arr[], int lw, int hg) {
	int i = lw, j = hg, d, m = arr[(lw + hg) / 2];
	while (i <= j) {
		while (arr[i] < m) {
			i++;
		}
		while (arr[j] > m) {
			j--;
		}
		if (i <= j) {
			d = arr[i];
			arr[i++] = arr[j];
			arr[j--] = d;
		}
	}
	if (lw < j) {
		qxcksxrt(arr, lw, j);
	}
	if (i < hg) {
		qxcksxrt(arr, i, hg);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	qxcksxrt(arr, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		printf("%d", arr[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
