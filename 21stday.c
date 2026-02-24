#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print list
void traverseList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = createNode(value);

        if(head == NULL) {
            head = newNode;    // First node
            temp = head;
        } else {
            temp->next = newNode;  // Link new node
            temp = newNode;        // Move temp
        }
    }

    // Traverse and print
    traverseList(head);

    return 0;
}