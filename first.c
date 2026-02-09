#include <stdio.h>

int main() {
    int a[100], n, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    for (int i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos - 1] = value;
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
