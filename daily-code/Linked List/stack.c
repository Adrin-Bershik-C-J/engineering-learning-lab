// Stack using linked list:-
// Stack Operations:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Exit

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *right;
};

struct Node *top = NULL;

void push();
void pop();
void peek();

int main() {
    int choice;
    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Enter a valid input\n");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    int value;
    printf("Enter the node value: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->value = value;
    newNode->right = top; 
    top = newNode; 
    printf("%d pushed onto the stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow!\n");
        return;
    }

    printf("%d removed from the stack!\n", top->value);
    struct Node *temp = top;
    top = top->right;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Nothing to display!\n");
        return;
    }
    printf("Top element: %d\n", top->value);
}
