#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

int queue[MAX];
int front = -1;
int rear = -1;

void insert() {
    int item;

    
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow (Full)\n");
        return;
    }

    printf("Enter the item to insert: ");
    scanf("%d", &item);

   
    if (front == -1) {
        front = 0;
        rear = 0;
    }
   
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    queue[rear] = item;
    printf("Item %d inserted successfully\n", item);
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow (Empty)\n");
        return;
    }

    printf("Deleted element is %d\n", queue[front]);

    
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    
    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else {
        for (i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (i = 0; i <= rear; i++)
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
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

