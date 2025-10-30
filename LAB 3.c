#include <stdio.h>
#define MAX 100

int front = -1;
int rear = -1;
int queue[MAX];

void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        int val;
        printf("Enter the value to be inserted: ");
        scanf("%d", &val);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted element is: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("The elements are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter 1 for enqueue, 2 for dequeue, 3 for display, and 4 for exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}












