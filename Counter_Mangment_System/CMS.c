#include <stdio.h>
#include <stdlib.h>
#include "../Token_Generator/token.h"
#include "../Queue_managment_system/Queue.h"
#include "../Ongoing_Counter_Stack/stack.h"
#include "CMS.h"
#include "../Ongoing_Counter_Stack/missing.h"

int number_of_counters = 2;





struct Counter* assign_counter_id(int id){
    struct Counter *counter;
    counter = (struct Counter*)malloc(sizeof(struct Counter));
    counter->id = id;
    counter->queue = (struct Queue*)malloc(sizeof(struct Queue));
    counter->stack = (struct Stack*)malloc(sizeof(struct Stack));
    counter->Missing = (struct Missing_list*)malloc(sizeof(struct Missing_list));
    counter->problem = (struct Stack*)malloc(sizeof(struct Stack));
    init_queue(counter->queue);
    init_stack(counter->stack);
    init_Missing_list(counter->Missing);
    init_stack(counter->problem);
    return counter;



}


void insert_counter(struct Counter* counters[], struct Counter *counter, int index){
    counters[index] = counter;
}

void create_counters(struct Counter* counter_list[]){
    
    for(int i=0;i<2;i++){
        struct Counter *counter = assign_counter_id(i+1);
        insert_counter(counter_list, counter, i);
    }
    printf(" *** Counters Created ***\n\n");
}

void sort_counters(struct Counter* counter_list[]) {

        int n = 2; // number of counters (since you created 2)
    
        for (int i = 0; i < n - 1; i++) {
    
            int min_index = i;
    
            for (int j = i + 1; j < n; j++) {
                if (counter_list[j]->queue->size < counter_list[min_index]->queue->size) {
                    min_index = j;
                }
            }
    
            // swap pointers
            if (min_index != i) {
                struct Counter *temp = counter_list[i];
                counter_list[i] = counter_list[min_index];
                counter_list[min_index] = temp;
            }
        }
    }
    

void display_counter(struct Counter* counter_list[],struct token *token){
    printf(" ** Select a Counter **\n");
    sort_counters(counter_list);
    int index=0;
    while (1)
    {
        if (index<0) index=0;
        else if (index>1) index=1;
        printf("\n\n___________________________________________\n");
        printf("\n|  Counter Number    |   Active Token No  |   \n");
        printf("\n|       %d            |        %d           |\n", counter_list[index]->id, counter_list[index]->queue->size);
        printf("___________________________________________\n");
        printf("\n\n----------------------------------\n");
        printf("prev - p | select - s | next - n   \n");
        printf("----------------------------------\n===>");
        char answer;
        scanf(" %c",&answer);
        if(answer=='p')
            index--;
        else if (answer=='n')
            index++;
        else if (answer=='s')
        {   enqueue(counter_list[index]->queue,token);
            printf("Entered to the counter - %d",counter_list[index]->id);
            break;
        }
        
        
        
    }
    

    printf("\n\n\n\n");
    
}


struct Counter* display_counter_rtn_Q(struct Counter* counter_list[]){
    
    printf("Select Counter\n");
    int index=0;
    while (1)
    {
        if (index<0) index=0;
        else if (index>1) index=1;
        printf("\n\n___________________________________________\n");
        printf("\n|  Counter Number    |   Active Token No  |   \n");
        printf("\n|       %d            |        %d           |\n", counter_list[index]->id, counter_list[index]->queue->size);
        printf("___________________________________________\n");
        printf("\n\n----------------------------------\n");
        printf("prev - p | select - s | next - n   \n");
        printf("----------------------------------\n===>");
        char answer;
        scanf(" %c",&answer);
        if(answer=='p')
            index--;
        else if (answer=='n')
            index++;
        else if (answer=='s')
        {   return counter_list[index];
            break;
        }
        
        
        
    }
    

    printf("\n\n\n\n");
    
}