#include <stdio.h>

int main() {
    int n, k, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k (positions to rotate): ");
    scanf("%d", &k);

    // Handle cases where k > n
    k = k % n;

    int temp[k];

    // Step 1: store last k elements in temp
    for(i = 0; i < k; i++)
        temp[i] = arr[n - k + i];

    // Step 2: shift first n-k elements to the right
    for(i = n - 1; i >= k; i--)
        arr[i] = arr[i - k];

    // Step 3: copy k elements from temp to start
    for(i = 0; i < k; i++)
        arr[i] = temp[i];

    // Print rotated array
    printf("Rotated Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}