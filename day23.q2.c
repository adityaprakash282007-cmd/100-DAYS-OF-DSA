#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Create cycle at position pos (0-based index)
void createCycle(struct Node* head, int pos) {
    if (pos == -1) return;

    struct Node *temp = head, *cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos)
            cycleNode = temp;

        temp = temp->next;
        index++;
    }

    temp->next = cycleNode;
}

// Detect cycle using Floyd Algorithm
bool hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    int n, x, pos;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Enter cycle position (pos): ");
    scanf("%d", &pos);

    createCycle(head, pos);

    if (hasCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}