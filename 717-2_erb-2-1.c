#include <stdio.h>

int main() {
	int n, x;
	int dif = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		dif -= x;
	}
	printf("%d", dif);
}
