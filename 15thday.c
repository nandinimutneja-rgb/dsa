#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int primarySum = 0, secondarySum = 0;

    for(i = 0; i < n; i++) {
        primarySum += matrix[i][i];             // primary diagonal
        secondarySum += matrix[i][n - 1 - i];   // secondary diagonal
    }

    printf("Sum of primary diagonal: %d\n", primarySum);
    printf("Sum of secondary diagonal: %d\n", secondarySum);

    return 0;
}