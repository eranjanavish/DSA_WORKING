#include <stdio.h>
#include <stdlib.h>
#include "../Token_Generator/token.h"
#include "../Counter_Mangment_System/CMS.h"
#include "Queue.h"

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

int normalCount = 0;
int tokenType[1000]; // 1 = Priority , 2 = Normal

Queue PriorityQueue;
Queue NormalQueue;
Queue MissQueue;


/* CREATE NODE */
Node* CREATE_NODE(int value)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = value;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}


/* INITIALIZE QUEUE */
void INIT_QUEUE(Queue* Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}


/* CHECK EMPTY */
int IS_EMPTY(Queue Q)
{
    return (Q.front == NULL);
}


/* CHECK TOKEN EXIST */
int TOKEN_EXISTS(Queue Q, int value)
{
    Node* current = Q.front;

    while (current != NULL)
    {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}


/* ENQUEUE */
void ENQUEUE(Queue* Q, int value)
{

    Node* NewNode = CREATE_NODE(value);

    if (Q->front == NULL)
    {
        Q->front = NewNode;
        Q->rear = NewNode;
    }
    else
    {
        Q->rear->next = NewNode;
        NewNode->prev = Q->rear;
        Q->rear = NewNode;
    }
}


/* DEQUEUE */
int DEQUEUE(Queue* Q)
{

    if (Q->front == NULL)
    {
        printf("Queue Empty\n");
        return -1;
    }

    Node* temp = Q->front;
    int value = temp->data;

    Q->front = temp->next;

    if (Q->front != NULL)
        Q->front->prev = NULL;
    else
        Q->rear = NULL;

    free(temp);

    return value;
}


/* DISPLAY QUEUE */
void DISPLAY(Queue Q)
{

    Node* current = Q.front;

    if (current == NULL)
    {
        printf("Empty\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}


/* CALL NEXT CUSTOMER */
void CALL_NEXT()
{

    if (!IS_EMPTY(PriorityQueue))
    {

        printf("\nServing Token: %d\n", DEQUEUE(&PriorityQueue));
        normalCount = 0;

    }
    else
    {

        if (normalCount < 2 && !IS_EMPTY(NormalQueue))
        {

            printf("\nServing Token: %d\n", DEQUEUE(&NormalQueue));
            normalCount++;

        }
        else if (!IS_EMPTY(MissQueue))
        {

            printf("\nServing Token: %d\n", DEQUEUE(&MissQueue));
            normalCount = 0;

        }
        else if (!IS_EMPTY(NormalQueue))
        {

            printf("\nServing Token: %d\n", DEQUEUE(&NormalQueue));

        }
        else
        {

            printf("\nNo Customers in Queue\n");

        }
    }
}


/* ADD MISSED TOKEN */
void ADD_TO_MISS_QUEUE(int value)
{

    /* check if token ever existed */
    if (tokenType[value] == 0)
    {
        printf("Error: Token was never in Priority or Normal queue\n");
        return;
    }

    /* prevent duplicates */
    if (TOKEN_EXISTS(PriorityQueue, value) ||
            TOKEN_EXISTS(NormalQueue, value) ||
            TOKEN_EXISTS(MissQueue, value))
    {

        printf("Token already exists in a queue!\n");
        return;
    }

    /* if it was priority -> give special facility */
    if (tokenType[value] == 1)
    {

        printf("Missed Priority Customer Added back to Priority Queue\n");
        ENQUEUE(&PriorityQueue, value);

    }
    else if (tokenType[value] == 2)
    {

        printf("Missed Normal Customer Added to Miss Queue\n");
        ENQUEUE(&MissQueue, value);

    }
}


