#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


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


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void sortList(struct Node* head) {
    struct Node* i;
    struct Node* j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL)
        return head2;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}


int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 5);

    
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 2);

    printf("List 1:\n");
    display(list1);

    printf("List 2:\n");
    display(list2);

    
    sortList(list1);
    printf("\nSorted List 1:\n");
    display(list1);

    
    list1 = reverseList(list1);
    printf("\nReversed List 1:\n");
    display(list1);

    
    list1 = concatenate(list1, list2);
    printf("\nConcatenated List:\n");
    display(list1);

    return 0;
}

