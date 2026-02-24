#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int freq[n]; // to store frequency of elements
    int visited = -1;

    for(i = 0; i < n; i++) {
        if(freq[i] == visited)
            continue;

        int count = 1;
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                freq[j] = visited; // mark as visited
            }
        }
        freq[i] = count;
    }

    printf("Frequency of elements:\n");
    for(i = 0; i < n; i++) {
        if(freq[i] != visited)
            printf("%d occurs %d times\n", arr[i], freq[i]);
    }

    return 0;
}