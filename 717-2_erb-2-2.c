#include <stdio.h>
#include <math.h>

int main() {
	int n, x;
	int S = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (i % 2 != 0) {
			S += pow(x, 3);
		}
	}
	printf("%d", S);
}
