#include <stdio.h>

int main() {
    int n, i, j, flag = 1;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    // Check identity matrix conditions
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j && matrix[i][j] != 1) {
                flag = 0;   // diagonal element not 1
                break;
            }
            if(i != j && matrix[i][j] != 0) {
                flag = 0;   // off-diagonal element not 0
                break;
            }
        }
        if(flag == 0)
            break;
    }

    if(flag)
        printf("The matrix is an identity matrix.\n");
    else
        printf("The matrix is NOT an identity matrix.\n");

    return 0;
}