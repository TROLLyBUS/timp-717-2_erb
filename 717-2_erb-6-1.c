#include <stdio.h>

int cxmbsxrt(int *arr, int arr_len) {
    int d = arr_len, i, temp;
    int isswap = 1;
    while (d > 1 || isswap){
            if (d > 1){
                d /= 1.24733;
            }
            else{
                d = 1;
            }
            isswap = 0;
            for (i = 0; i + d < arr_len; ++i){
                if (arr[i + d] < arr[i]){
                    temp = arr[i];
                    arr[i] = arr[i + d];
                    arr[i + d] = temp;
                    isswap = 1;
                }
            }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    cxmbsxrt(a, n);
    for(int i = 0; i < n; i++){
        if(i!=n-1){
            printf("%d", a[i]);
            printf(" ");
        }
        else{
            printf("%d", a[i]);
        }
    }
    printf("\n");
}
