#include <stdio.h>

int main() {
    int m, n, i, j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    printf("Boundary-to-Center Matrix Walk:\n");

    while(top <= bottom && left <= right) {
        // Top row
        for(i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // Right column
        for(i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Bottom row
        if(top <= bottom) {
            for(i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // Left column
        if(left <= right) {
            for(i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    printf("\n");
    return 0;
}