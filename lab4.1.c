#include <stdio.h>
#include <stdlib.h>
void mergeArrays(int arr1[], int n, int arr2[], int m, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        }
        else {
            result[k++] = arr2[j++];
        }
    }
    while (i < n) {
        result[k++] = arr1[i++];
    }
    while (j < m) {
        result[k++] = arr2[j++];
    }
}
int main() {
    int arr1[] = { 1, 3, 5, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = { 2, 4, 6, 8, 10 };
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int* result = (int*)malloc((n + m) * sizeof(int));
    if (result == NULL) {
        printf("ERROR! ERROR! ACCIDENT! ACCIDENT!\n");
        return 1;
    }
    mergeArrays(arr1, n, arr2, m, result);
    printf("rez: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}