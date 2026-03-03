#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Get length of linked list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection node
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }

    // Traverse together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, i;

    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    // First list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* temp = newNode(val);

        if (head1 == NULL)
            head1 = tail1 = temp;
        else {
            tail1->next = temp;
            tail1 = temp;
        }
    }

    // Second list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);

        struct Node* temp = newNode(val);

        if (head2 == NULL)
            head2 = tail2 = temp;
        else {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    /*
       IMPORTANT:
       Manually create intersection for testing.
       Here we connect second list to 3rd node of first list.
       (Change value if needed)
    */

    struct Node* temp = head1;
    while (temp != NULL && temp->data != 30) {
        temp = temp->next;
    }

    if (temp != NULL) {
        tail2->next = temp;
    }

    // Find intersection
    struct Node* result = findIntersection(head1, head2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}