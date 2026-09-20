#include <stdio.h>
#include <string.h>

#define SIZE 5

char queue[SIZE][50];
int front = -1;
int rear = -1;

// Enqueue
void enqueue(char name[])
{
    // Queue is full
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is Full\n");
        return;
    }

    // First element
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    strcpy(queue[rear], name);
    printf("%s inserted\n", name);
}

// Dequeue
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("%s deleted\n", queue[front]);

    // Only one element was present
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Display
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    i = front;

    while (1)
    {
        printf("%s ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    enqueue("Vishal");
    enqueue("Aman");
    enqueue("Mohan");
    enqueue("Naman");
    enqueue("Sohan");

    display();

    dequeue();
    dequeue();

    display();

    enqueue("Karan");
    enqueue("Raj");

    display();

    return 0;
}

