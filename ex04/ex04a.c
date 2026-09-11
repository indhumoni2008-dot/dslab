#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push operation
void push(int element) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack overflow. Memory allocation failed.\n");
        return;
    }

    newNode->data = element;
    newNode->next = top;
    top = newNode;

    printf("Element pushed: %d\n", element);
}

// Pop operation
int pop() {
    struct Node *temp;
    int element;

    if (top == NULL) {
        printf("Stack underflow. Stack is empty.\n");
        return -1;
    }

    temp = top;
    element = top->data;
    top = top->next;

    free(temp);

    return element;
}

// Display operation
void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    temp = top;

    printf("Stack elements: ");

    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice, element;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;

            case 2:
                element = pop();

                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

