#include <stdio.h>

int main() {
    int n, i, j, sum, count = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check all subarrays
    for(i = 0; i < n; i++) {
        sum = 0;
        for(j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0) {
                count++;
            }
        }
    }

    printf("Number of subarrays with sum 0: %d\n", count);

    return 0;
}