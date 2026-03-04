#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* newNode(int coeff, int exp) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}

int main() {
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int coeff, exp;

        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);

        struct Node* temp = newNode(coeff, exp);

        if (head == NULL)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    printf("Polynomial: ");

    struct Node* current = head;

    while (current != NULL) {
        if (current->exp == 0)
            printf("%d", current->coeff);
        else if (current->exp == 1)
            printf("%dx", current->coeff);
        else
            printf("%dx^%d", current->coeff, current->exp);

        if (current->next != NULL)
            printf(" + ");

        current = current->next;
    }

    return 0;
}