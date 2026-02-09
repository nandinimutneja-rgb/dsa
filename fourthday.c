#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 0;
    }

    if (n <= 0) {
        printf("No elements\n");
        return 0;
    }

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
