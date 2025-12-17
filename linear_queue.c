#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void push() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }

    printf("Enter the item to insert: ");
    scanf("%d", &item);

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = item;
    printf("Item %d added successfully\n", item);
}

void pop() {
    if (front == -1) {
        printf("Queue underflow\n");
        return;
    }

    printf("Deleted element is %d\n", queue[front]);
    front++;

    if (front > rear) {
        
        front = -1;
        rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1 -> Insert\n");
        printf("2 -> Delete\n");
        printf("3 -> Display\n");
        printf("4 -> Exit\n");
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
                display();
                break;
            case 4:
                printf("Exit program \n");
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}

