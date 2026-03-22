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
         
    }
    else {
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
            temp->next=NULL;
            list->tail=temp;
        }
        else{
            temp->next=temp->next->next;
        }
    }
    
}


struct token* search_missing(struct Missing_list *list){
    if (list->head==NULL){
        printf("*** Mising List is Empty ***\n");
        return NULL;
    }
    struct token *temp = list->head;
    while (1){
        if(temp==NULL){
            printf("End of the list reached...\n\n");
            return NULL;
        }
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
        char answer = question_answer("Select - s | Next - n\n==>");
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