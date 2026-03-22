#ifndef STACK_H
#define STACK_H

#include "../Token_Generator/token.h"


struct Stack {
    struct token *top;
};


void init_stack(struct Stack* stack);
void push(struct Stack* stack, struct token* token);
struct token* pop(struct Stack* stack); 
void print_stack(struct Stack* stack);
void correct_last_service(struct Stack *completed, struct Stack *problem);
void clear_stack(struct Stack *stack);

#endif
