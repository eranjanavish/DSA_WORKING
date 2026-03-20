// token_queue.h
#ifndef TOKEN_QUEUE_H
#define TOKEN_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../Token_Generator/token.h"  // Make sure this path is correct
#include "../Counter_Mangment_System/CMS.h"

// ------------------------
// Queue structure
// ------------------------
struct Queue {
    struct token *front;  // front of the queue
    struct token *rear;   // rear of the queue
    int size;             // number of items
};

// ------------------------
// Function prototypes
// ------------------------

// Initialize the queue
void init_queue(struct Queue *q);

// Add a token to the end of the queue
void enqueue(struct Queue *q, struct token *node);

// Remove a token from the front of the queue
struct token* dequeue(struct Queue *q);
void peek(struct Queue* queue);




#endif // TOKEN_QUEUE_H