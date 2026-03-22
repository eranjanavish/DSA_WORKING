#include <stdio.h>
#include <stdbool.h>
#include "../Token_Generator/token.h"
#include "../Counter_Mangment_System/CMS.h"
#include "../Queue_managment_system/Queue.h"
#include "Active.h"
#include "../Ongoing_Counter_Stack/stack.h"


void init_Active(struct Active *list){
    list->head=NULL;
    list->tail=NULL;
}

void insert_Active(struct Active *list, struct token* token) {

    
    if (list->head == NULL) {
        list->head = token;
        list->tail = token;
        token->next = token; 
    }
    else {
        token->next = list->head;   
        list->tail->next = token;   
        list->tail = token;         
    }
    
    
}

struct token* print_Active_Queue(struct Queue *queue,struct Active *ASR){
    if(queue->front==NULL){
        printf("Counter queue is empty\n");
        return NULL;
    }
    struct token *token = queue->front;
    while(token!=NULL){
        struct token *newNode =  copy_token(token);
        
        
        insert_Active(ASR,newNode);
        token=token->next;

    }
    printf("Counter Queue is ready to be reviewed.\n");
    return search_token_manager(ASR);
}

struct token* print_Active_Stack(struct Stack *stack,struct Active *ASR){
    if(stack->top==NULL){
        printf("Counter queue is empty\n");
        return NULL;
    }
    struct token *token = stack->top;
    while(token!=NULL){
        struct token *newNode = malloc(sizeof(struct token));
        *newNode = *token;     // copy data
        newNode->next = NULL;
        
        insert_Active(ASR,newNode);
        token=token->next;

    }
    printf("Counter Stack is ready to be reviewed.\n");
    return search_token_manager(ASR);
}

struct token* search_token_manager(struct Active *list) {
    if (list->head == NULL) {
        printf("List is Empty\n");
        return NULL;
    }

    struct token *temp = list->head;

    do {
        printf("============\n");
        printf("Token id : %d\n",temp->token_id);
        printf("Customer name : %s\n",temp->name);
        printf("Customer id : %s\n",temp->nic);
        printf("Customer Phone number : %d\n",temp->phone_number);
        printf("CUstomer Address: %s\n",temp->address);
        printf("Service type : %s\n",temp->service);
        printf("============\n");
        char answer = question_answer("Select/Go back - s | Next - n\n");

        if (answer == 's') {
            return temp;
        } 
        else if (answer == 'n') {
            temp = temp->next;
        } 
        else {
            printf("Wrong Answer\n");
        }

    } while (temp);  
    printf("No selection made.\n");
    return NULL;
}