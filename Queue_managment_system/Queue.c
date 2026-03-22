#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void init_queue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

void enqueue(struct Queue *q, struct token *newToken) {
    if (!newToken) return;

    if (q->front == NULL) {
        q->front = newToken;
        q->rear = newToken;
        newToken->next = NULL;
    } else if (newToken->priority == 1) {
        if (q->front->priority != 1) {
            newToken->next = q->front;
            q->front = newToken;
        } else {
            struct token *temp = q->front;
            while (temp->next != NULL && temp->next->priority == 1) {
                temp = temp->next;
            }
            newToken->next = temp->next;
            temp->next = newToken;

            if (newToken->next == NULL) {
                q->rear = newToken;
            }
        }
    } else {
        q->rear->next = newToken;
        newToken->next = NULL;
        q->rear = newToken;
    }

    q->size++;
}

struct token* dequeue(struct Queue *q) {
    if (q->front == NULL) return NULL; 

    struct token *node = q->front;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = node->next;
    }

    node->next = NULL;
    q->size--;

    return node;
}

void peek(struct Queue* queue){
    if (queue->front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct token *token = queue->front;
    printf("\n========================================\n");
    printf("            TOKEN DETAILS               \n");
    printf("========================================\n");

    printf(" %-22s : %d\n",  "Token ID", token->token_id);
    printf(" %-22s : %s\n",  "Customer Name", token->name);
    printf(" %-22s : %s\n",  "Customer NIC", token->nic);
    printf(" %-22s : %d\n",  "Phone Number", token->phone_number);
    printf(" %-22s : %s\n",  "Address", token->address);
    printf(" %-22s : %lld\n","Issue Date", token->date/1000000);
    printf(" %-22s : %s\n",  "Service Type", token->service);

    printf("========================================\n\n");
}
