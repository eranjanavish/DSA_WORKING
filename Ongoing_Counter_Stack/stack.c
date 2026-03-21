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

struct token* pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is Empty!\n");
        return NULL;
    }

    struct token* temp = stack->top;   
    stack->top = stack->top->next; 
    temp->next = NULL;

    return temp;
}

void print_stack(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    struct token* current = stack->top;

    printf("Stack (top to bottom):\n");
    while (current != NULL) {
        printf("%s -> ", current->name); 
        current = current->next;
    }
    printf("NULL\n");
}

void correct_last_service(struct Stack *completed, struct Stack *problem) {
    struct token *token = pop(completed);
    if (token != NULL) {
        push(problem, token);
        printf("\n** Last completed service moved to problem stack **\n");
        printf("Token ID: %d | Name: %s\n", token->token_id, token->name);
    } else {
        printf("\n** No completed services to correct **\n");
    }
}

void clear_stack(struct Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is already empty\n");
        return;
    }
    while (stack->top != NULL) {
        pop(stack);
    }
    printf("Stack cleared\n");
}

