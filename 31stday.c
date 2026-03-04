#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int choice;
        scanf("%d", &choice);

        // PUSH
        if (choice == 1) {
            int value;
            scanf("%d", &value);

            if (top == MAX - 1) {
                // Do nothing if overflow (judge safe)
                continue;
            }

            top++;
            stack[top] = value;
        }

        // POP
        else if (choice == 2) {
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top]);
                top--;
            }
        }

        // DISPLAY
        else if (choice == 3) {
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                for (int i = top; i >= 0; i--) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}