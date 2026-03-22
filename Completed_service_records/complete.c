#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Token_Generator/token.h"
#include "../Queue_managment_system/Queue.h"
#include "../Ongoing_Counter_Stack/stack.h"
#include "../Counter_Mangment_System/CMS.h"
#include "../Ongoing_Counter_Stack/missing.h"
#include "complete.h"



void init_complete(struct complete *list){
    list->head = NULL;
    list->tail = NULL;
}

void inser_to_complete(struct complete *list,struct token *token){
    if (list->head==NULL)
    {
        list->head=token;
        list->tail=token;
        token->next=token;
        token->prev = token;
    }
    else{
        list->tail->next=token;
        token->next=list->head;
        token->prev=list->tail;
        list->tail=token;
        list->head->prev=list->tail;

    }
    
}

void extract_from_stack(struct Counter *counter,struct complete *list){
    int counter_completed = 0;
    int counter_problem = 0;
    if (counter->stack==NULL){
        printf("Completed stack is empty");
    }
    else{
        struct token *token = counter->stack->top;
        while(token!=NULL){
            struct token *cpy_token = copy_token(token);
            inser_to_complete(list,cpy_token);
            token=token->next;
            counter_completed++;
        }
    }
    if (counter->problem==NULL){
        printf("Completed stack is empty");
    }
    else{
        struct token *token = counter->problem->top;
        while(token!=NULL){
            
            token=token->next;
            counter_problem++;
        }
    }
    printf("\n=== Operations of Counter %d === \n\n\n",counter->id);
    printf("Completed Tokens : %d\n",counter_completed);
    printf("Problem Tokens : %d\n",counter_problem);
    
}


void swap_data(struct token *a, struct token *b) {
    int temp_id = a->token_id;
    int temp_phone = a->phone_number;
    int temp_priority = a->priority;

    char temp_nic[15];
    char temp_name[20];
    char temp_address[30];

    strcpy(temp_nic, a->nic);
    strcpy(temp_name, a->name);
    strcpy(temp_address, a->address);

    a->token_id = b->token_id;
    a->phone_number = b->phone_number;
    a->priority = b->priority;

    strcpy(a->nic, b->nic);
    strcpy(a->name, b->name);
    strcpy(a->address, b->address);

    b->token_id = temp_id;
    b->phone_number = temp_phone;
    b->priority = temp_priority;

    strcpy(b->nic, temp_nic);
    strcpy(b->name, temp_name);
    strcpy(b->address, temp_address);
}

void selectionSort(struct complete *list) {
    if (list->head == NULL)
        return;

    struct token *current = list->head;

    do {
        struct token *min = current;
        struct token *temp = current->next;
        while (temp != list->head) {
            if (temp->date < min->date) {
                min = temp;
            }
            temp = temp->next;
        }
        if (min != current) {
            swap_data(current, min);
        }
        current = current->next;

    } while (current != list->head);
}

void final_report(struct Counter* counter_list[],struct complete *list){
    for(int i=0;i<2;i++){
        extract_from_stack(counter_list[i],list);
    }
    selectionSort(list);
    complete_list_view(list);
}

void complete_list_view(struct complete *list){
    if (list->head==NULL){
        printf("List is Empty\n");
    }
    else{
        struct token *token = list->head;
        int is_on = 1;
        while (is_on)
    {
        printf("\n===================\n");
        printf("Token id : %d\n",token->token_id);
        printf("Customer name : %s\n",token->name);
        printf("Customer id : %s\n",token->nic);
        printf("Customer Phone number : %d\n",token->phone_number);
        printf("CUstomer Address: %s\n",token->address);
        printf("Issued Date : %lld\n",(token->date)/1000000);
        printf("Serviced Date : %lld\n",(token->serviced_date)/1000000);
        printf("Service Time : %llds\n",service_time(token));
        printf("Service type : %s\n",token->service);
        printf("\n===================\n");
        char answer = question_answer(" Prev - p | Next - n | Exit - e \n");
        if(answer=='p')
            token=token->prev;
        else if (answer=='n')
            token=token->next;
        else if (answer=='e')
        {   
            is_on=0;
            break;
        }
        
        
        
    }
    }
}
#include <string.h>

