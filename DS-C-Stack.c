#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

int pop(){
    if(top==NULL)
    printf("The stack is empty(Underflow)!!");
    else{
        struct node *temp = top;
        int t_data=top->data;
        top=top->next;
        free(temp);
        return t_data;
    }
}

void push(int val){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(top==NULL)
    newnode->next=NULL;
    else
        newnode->next=top;
    top=newnode;
    printf("\nNode is added!\n");
}

void display(){
    if(top==NULL)
    printf("The stack is empty(Underflow)!!");
    else{
        struct node *temp=top;
        while(temp->next!=NULL){
            printf("%d---", temp->data);
            temp=temp->next;
        }
        printf("%d---",temp->data);
    }
}

int main() {
    int choice, val;
    printf("\nImplementation of Stack using Linked List\n");
        
    do{
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }while (choice!=4);
}




























