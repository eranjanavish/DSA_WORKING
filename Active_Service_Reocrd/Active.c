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
        list->tail->next=list->head;         
    }
    
    
}

struct token* print_Active_Queue(struct Queue *queue,struct Active *ASR){
    if(queue->front==NULL){
        printf("Currnetly the queue is empty\n");
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
        printf("\n========================================\n");
        printf("            TOKEN DETAILS               \n");
        printf("========================================\n");
    
        printf(" %-22s : %d\n",  "Token ID", temp->token_id);
        printf(" %-22s : %s\n",  "Customer Name", temp->name);
        printf(" %-22s : %s\n",  "Customer NIC", temp->nic);
        printf(" %-22s : %d\n",  "Phone Number", temp->phone_number);
        printf(" %-22s : %s\n",  "Address", temp->address);
        printf(" %-22s : %lld\n","Issue Date", temp->date/1000000);
        printf(" %-22s : %s\n",  "Service Type", temp->service);
    
        printf("========================================\n\n");
        char answer = question_answer("Select/Go back - s | Next - n\n==>");

        if (answer == 's') {
            return temp;
        } 
        else if (answer == 'n') {
            temp = temp->next;
        } 
        else if (answer == 'e') {
            return NULL;
        } 
        else {
            printf("Wrong Answer\n");
        }

    } while (temp);  
    printf("No selection made.\n");
    return NULL;
}