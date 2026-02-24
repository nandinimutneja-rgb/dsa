#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MAX

int main() {
    int n, i, j;
    int min_sum = INT_MAX;
    int pair1, pair2;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check all pairs
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if(abs(sum) < min_sum) {
                min_sum = abs(sum);
                pair1 = arr[i];
                pair2 = arr[j];
            }
        }
    }

    printf("Pair with sum closest to zero: %d and %d\n", pair1, pair2);
    printf("Closest sum: %d\n", pair1 + pair2);

    return 0;
}