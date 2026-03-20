#include <stdio.h>
#include <stdlib.h>
#include "../Token_Generator/token.h"
#include "stack.h"




void init_stack(struct Stack* stack){
    stack->top=NULL;
}

void push(struct Stack* stack,struct token* token){
    if (stack->top==NULL){
        stack->top=token;
    }
    else{
        token->next=stack->top;
        stack->top=token;
    }
}

void pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    struct token* temp = stack->top;   // store top node
    stack->top = stack->top->next;     // move top down

    free(temp); // return popped node
}

void print_stack(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    struct token* current = stack->top;

    printf("Stack (top to bottom):\n");
    while (current != NULL) {
        printf("%s -> ", current->name); // change 'value' if your struct uses another field
        current = current->next;
    }
    printf("NULL\n");
}