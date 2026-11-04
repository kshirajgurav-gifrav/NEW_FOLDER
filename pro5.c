#include <stdio.h>
#include <stdlib.h>

// Structure for the linked list node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Create a new node
Node* getNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Out of Memory\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
Node* insertionAtBegin(Node *head, int new_data) {
    Node *newNode = getNode(new_data);

    if (newNode == NULL)
        return head;

    newNode->next = head;
    head = newNode;

    return head;
}

// Insert at end
Node* insertionAtEnd(Node *head, int new_data) {
    Node *newNode = getNode(new_data);

    if (newNode == NULL)
        return head;

    if (head == NULL) {
        return newNode;
    }

    Node *lastNode = head;

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;

    return head;
}

// Insert at specific 1-based position
Node* insertAtPosition(Node *head, int position, int value) {
    if (position < 1) {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1) {
        return insertionAtBegin(head, value);
    }

    Node *current = head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position is beyond the end of the list.\n");
        return head;
    }

    Node *newNode = getNode(value);

    if (newNode == NULL)
        return head;

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Delete from beginning
Node* deleteFromBeginning(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Delete from end
Node* deleteFromEnd(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

// Delete first node with specific key
Node* deleteNodeWithKey(Node *head, int key) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    Node *current = head;
    Node *prev = NULL;

    if (current->data == key) {
        head = current->next;
        free(current);
        return head;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found in the list.\n");
        return head;
    }

    prev->next = current->next;
    free(current);

    return head;
}

// Traverse the linked list
void traverseLinkedList(Node *head) {
    Node *current = head;

    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int choice;
    int data;
    int position;
    int key;

    while (1) {
        printf("\n===== Linked List Menu =====\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete a node with a specific key\n");
        printf("7. Display the linked list\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertionAtBegin(head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertionAtEnd(head, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, position, data);
                break;

            case 4:
                head = deleteFromBeginning(head);
                break;

            case 5:
                head = deleteFromEnd(head);
                break;

            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                head = deleteNodeWithKey(head, key);
                break;

            case 7:
                printf("Linked List: ");
                traverseLinkedList(head);
                break;

            case 8:
                while (head != NULL) {
                    head = deleteFromBeginning(head);
                }

                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
