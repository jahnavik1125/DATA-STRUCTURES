#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define SIZE 10
int queue[SIZE];
int front=-1,rear=-1;

void enqueueRear()
{
    int value;
    char ch;
    if(rear==SIZE-1)
    {
        printf("\nQueue is full");
        return;
    }
    do
    {
        printf("\nEnter value to be inserted:");
        scanf("%d",&value);
        if(front==-1) front=0;
        rear++;
        queue[rear]=value;
        printf("Do you want to continue insertion Y/N:");
        ch=getch();
    }while(ch=='Y'||ch=='y');
}

void enqueueFront()
{
    int value;
    char ch;
    if(front==0)
    {
        printf("\nQueue is full");
        return;
    }
    do
    {
        printf("\nEnter value to be inserted:");
        scanf("%d",&value);
        if(front==-1)
        {
            front=rear=0;
            queue[front]=value;
        }
        else
        {
            front--;
            queue[front]=value;
        }
        printf("Do you want to continue insertion Y/N:");
        ch=getch();
    }while(ch=='Y'||ch=='y');
}

void dequeueFront()
{
    if(front==-1)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nDeleted element is %d",queue[front]);
    if(front==rear)
        front=rear=-1;
    else
        front++;
}

void dequeueRear()
{
    if(rear==-1)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nDeleted element is %d",queue[rear]);
    if(front==rear)
        front=rear=-1;
    else
        rear--;
}

void display()
{
    int i;
    if(front==-1)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nElements in queue are:\n");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n1.Enqueue Rear\n2.Enqueue Front\n3.Dequeue Front\n4.Dequeue Rear\n5.Display\n6.Exit\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enqueueRear();
                    break;
            case 2:enqueueFront();
                    break;
            case 3:dequeueFront();
                    break;
            case 4:dequeueRear();
                    break;
            case 5:display();
                    break;
            case 6:exit(0);
            default:printf("\nInvalid choice");
        }
    }
}
