#include <stdio.h>
#define SIZE 5

int dq[SIZE];
int front = -1, rear = -1;

void insert_front(int x) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
        printf("Deque Full\n");
    else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0)
            front = SIZE - 1;
        else
            front--;
        dq[front] = x;
        printf("Inserted %d at front\n", x);
    }
}

void insert_rear(int x) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
        printf("Deque Full\n");
    else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == SIZE - 1)
            rear = 0;
        else
            rear++;
        dq[rear] = x;
        printf("Inserted %d at rear\n", x);
    }
}

void delete_front() {
    if (front == -1)
        printf("Deque Empty\n");
    else {
        printf("Deleted %d from front\n", dq[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == SIZE - 1)
            front = 0;
        else
            front++;
    }
}

void delete_rear() {
    if (front == -1)
        printf("Deque Empty\n");
    else {
        printf("Deleted %d from rear\n", dq[rear]);
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = SIZE - 1;
        else
            rear--;
    }
}

void display() {
    if (front == -1)
        printf("Deque Empty\n");
    else {
        int i = front;
        printf("Deque: ");
        while (1) {
            printf("%d ", dq[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &x); insert_front(x); break;
            case 2: printf("Enter value: "); scanf("%d", &x); insert_rear(x); break;
            case 3: delete_front(); break;
            case 4: delete_rear(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
