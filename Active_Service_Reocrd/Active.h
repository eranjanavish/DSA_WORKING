#ifndef ACTIVE_H
#define ACTIVE_H

#include "../Token_Generator/token.h"
#include "../Queue_managment_system/Queue.h"
#include "../Ongoing_Counter_Stack/stack.h"

// Active list structure (Circular Linked List)
struct Active {
    struct token *head;
    struct token *tail;
};

// Function declarations
void init_Active(struct Active *list);
void insert_Active(struct Active *list, struct token *token);
struct token* print_Active_Queue(struct Queue *queue,struct Active *ASR);
struct token* search_token_manager(struct Active *list);
struct token* print_Active_Stack(struct Stack *stack,struct Active *ASR);

#endif