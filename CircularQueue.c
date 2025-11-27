//Circular Queue..
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int front = -1;
int rear = -1;

int queue[SIZE];

// Enqueue Operation
int enqueue(int val)
{
    // Queue full condition
    if ((rear + 1) % SIZE == front)
    {
        printf("The Queue is full...\n");
        return -1;
    }

    // first element
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = val;
    return val;
}

// Dequeue Operation
int dequeue()
{
    if (front == -1)
    {
        printf("The Queue Is Empty.....\n");
        return -1;
    }

    int temp = queue[front];
    printf("Deleted: %d\n", temp);

    if (front == rear)
    {
        front = rear = -1; // only one element
    }
    else
    {
        front = (front + 1) % SIZE;
    }

    return temp;
}

// Peek Operation
int peek()
{
    if (front == -1)
    {
        printf("The Queue Is Empty ..\n");
        return -1;
    }

    printf("The Queue front element is : %d\n", queue[front]);
    return queue[front];
}

// Display Operation
int display()
{
    if (front == -1)
    {
        printf("The Queue Is Empty....\n");
        return -1;
    }

    printf("The Queue Elements are: ");

    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", queue[rear]); // print last element

    return 0;
}

int main()
{
    int n, choice;

    while (1)
    {
        printf("\n<- QUEUE MENU ->\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter the Element to Queue: ");
            scanf("%d", &n);
            enqueue(n);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid Choice.....\n");
        }
    }

    return 0;
}
