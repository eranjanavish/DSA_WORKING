#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../Token_Generator/token.h"



typedef struct Queue
{
    struct token* front;
    struct token* rear;
    int size;
} Queue;




extern int normalCount;
extern int tokenType[1000];

extern Queue PriorityQueue;
extern Queue NormalQueue;
extern Queue MissQueue;




/* Node */


// /* Queue Operations */
// void INIT_QUEUE(Queue* Q);
// int IS_EMPTY(Queue Q);
// int TOKEN_EXISTS(Queue Q, int value);

// void ENQUEUE(Queue* Q, int value);
// int DEQUEUE(Queue* Q);

// void DISPLAY(Queue Q);

// /* System Functions */
// void CALL_NEXT();
// void ADD_TO_MISS_QUEUE(int value);
void peek(struct Queue* queue);
struct token* dequeue(struct Queue *q);
void enqueue(struct Queue *q, struct token *newToken);
void init_queue(struct Queue *q);
#endif
