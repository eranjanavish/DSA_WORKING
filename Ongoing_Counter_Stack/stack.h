#ifndef STACK_H
#define STACK_H

#include "../Token_Generator/token.h"

// Stack structure
struct Stack {
    struct token *top;
};

// Function declarations
void init_stack(struct Stack* stack);
void push(struct Stack* stack, struct token* token);
void pop(struct Stack* stack);
void print_stack(struct Stack* stack);

#endif