#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
void enq(int data);
void deq(); 
void display();
void init();

int count = 0;

void main()
{
    int n, ch;
    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
    init();
    do
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &n);
            enq(n);
            break;
        case 2:
            deq();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice, re-enter!");
            break;
        }
    }while(ch!=4);
}

void init()
{
    front = rear = NULL;
}

void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->data = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->ptr = temp;
        temp->data = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->data);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->data);
}

void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Queue is empty cannot display!");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->data);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}














