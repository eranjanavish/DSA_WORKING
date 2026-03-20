#include <stdio.h>
#include <stdlib.h>

#include "../Token_Generator/token.h"
#include "missing.h"

void init_Missing_list(struct Missing_list *list){
    list->head=NULL;
    list->tail=NULL;
}


void insert(struct Missing_list *list, struct token* token) {

    
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
    printf("Added To missing list\n");
}

void delete_id(struct Missing_list *list, struct token* token) {
    struct token *temp = list->head;
    if (token->token_id==temp->token_id){
        list->head=list->head->next;
        temp->next=NULL;
    }
    else{
        while(temp->next->token_id!=token->token_id){
            temp=temp->next;
        }
        if(temp->next==list->tail){
            list->tail=temp;
            list->tail->next=list->head;
        }
        else{
            temp->next=temp->next->next;
        }
    }
    
}


struct token* search_missing(struct Missing_list *list){
    if (list->head==NULL){
        printf("Mising List is Empty\n");
        return NULL;
    }
    struct token *temp = list->head;
    while (1){
        printf("============\n");
        printf("Token id : %d\n",temp->token_id);
        printf("Customer name : %s\n",temp->name);
        printf("Customer id : %s\n",temp->nic);
        printf("Customer Phone number : %d\n",temp->phone_number);
        printf("CUstomer Address: %s\n",temp->address);
        printf("Service type : %s\n",temp->service);
        printf("============\n");
        char answer = question_answer("Select - s | Next - n\n");
        switch (answer)
        {
        case 'n':
            temp=temp->next;
            break;
        case 's':
            delete_id(list,temp);
            return temp;
            exit(0);
            break;
        default:
            printf("Wrong Answer\n");
            break;
        }

    }
}