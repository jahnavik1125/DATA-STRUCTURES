#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
     }node;

node* insertfront(node *first) {
   int value;
   printf("Enter the value to insert at front:\n");
   scanf("%d",&value);

   node *newnode = (node*)malloc(sizeof(node));
   newnode->data=value;
   newnode->next=first;

   return newnode;
}

node* insertrear(node *first) {
    int value;
   printf("Enter the value to insert at rear:\n");
   scanf("%d",&value);

   node *newnode = (node*)malloc(sizeof(node));
   newnode->data=value;
   newnode->next=NULL;

   if (first==NULL)
    return newnode;
   node *temp=first;
   while(temp->next!=NULL)
     temp=temp->next;
     temp->next=newnode;
     return first;
}

    node* deletefront(node *first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    node *temp = first;
    printf("Deleted: %d\n", temp->data);
    first = first->next;
    free(temp);

    return first;
}

node* deleterear(node *first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (first->next == NULL) {
        printf("Deleted: %d\n", first->data);
        free(first);
        return NULL;
    }
    node *temp = first;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;

    return first;
}

void display(node *first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = first;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node *first = NULL;
    int choice;

    while (1) {
        printf("\n--MENU--\n");
        printf("1. Insert FRONT\n");
        printf("2. Insert REAR\n");
        printf("3. Delete FRONT\n");
        printf("4. Delete REAR\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: first = insertfront(first);
             break;
            case 2: first = insertrear(first);
            break;
            case 3: first = deletefront(first);
             break;
            case 4: first = deleterear(first);
            break;
            case 5: display(first);
            break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
