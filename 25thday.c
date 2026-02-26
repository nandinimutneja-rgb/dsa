#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create linked list
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input key
    printf("Enter key to count: ");
    scanf("%d", &key);

    // Count occurrences
    int count = 0;
    temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    // Output result
    printf("Number of occurrences of %d: %d\n", key, count);

    // Free memory
    temp = head;
    while (temp != NULL) {
        struct Node* deleteNode = temp;
        temp = temp->next;
        free(deleteNode);
    }

    return 0;
}