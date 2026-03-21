#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Token_Generator/token.h"
#include "Counter_Mangment_System/CMS.h"
#include "Queue_managment_system/Queue.h"
#include "Ongoing_Counter_Stack/stack.h"
#include "Ongoing_Counter_Stack/missing.h"
#include "Active_Service_Reocrd/Active.h"
#include "Completed_service_records/complete.h"
#include "Service_List/service_list.h"

void serve_customer(struct Stack *stack,struct token *token){
    char is_valid = question_answer("Is the token valid? (y/n)\n");
                            
                            if (is_valid=='n'){
                                printf("Token Deleted\n");
                                free(token);
                                
                            }
                            else{
                                push(stack,token);
                                printf(" ** Token is serviced ** \n\n");

                            }
}

// use this commnad to run the c file -  gcc main.c ./Token_Generator/token.c Counter_Mangment_System/CMS.c Queue_managment_system/Queue.c Ongoing_Counter_Stack/stack.c Ongoing_Counter_Stack/mising.c Active_Service_Reocrd/Active.c Completed_service_records/complete.c Service_List/service_list.c -o token_program
//And then -  ./token_program     
int main(){
    

        struct token_list token_list;
        initialize_token_list(&token_list);
        create_tokens_1_100(&token_list);

        struct Counter* counter_list[2];
        create_counters(counter_list);
    
        struct Stack manager_stack;
        init_stack(&manager_stack);
    
        
        
        //Starts the program
        while(1){

        printf("\n\n\n====== Office Managment System ======\n\n");
        printf("1. Issue a Token\n");
        printf("2. Counter Operator Access\n");
        printf("3. Department Manager Access\n");
        printf("4. Completed Service Records\n");
        printf("5. Exit\n\n");
        printf("======  ======\n");

        
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:

            printf("\n\n=== Token issuing terminal ===\n\n");
            struct token *token_o1 = issue_token(&token_list);
            display_counter(counter_list,token_o1);

            break;

            case 2:
                printf("=== Option 2 Selected ===\n\n");
                printf("\n==== Counter Operator Terminal ====\n");
                struct Counter *counter = display_counter_rtn_Q(counter_list);
                printf("============\n\n");
                printf("Selected Counter - %d\n",counter->id);

                
                bool is_on = true;
                while (is_on){
               char option = question_answer("\n\nAccess Queue - q | Find Missed Token - m | Correct Last Service - c | Exit to main menu - e\n");
                
                if(option=='q')
                       {
                        printf("Counter : %d Selected\n",counter->id);
                        peek(counter->queue);
                       
                        struct token *token_o2 = dequeue(counter->queue);
                        if(token_o2!=NULL){
                        char is_available = question_answer("Is the customer available? (y/n)\n");
                        if(is_available=='y'){
                            char is_problem = question_answer("Is there a problem?\n");
                            if(is_problem=='n')
                                {serve_customer(counter->stack,token_o2);}
                            else{
                                push(counter->problem,token_o2);
                                printf("== Reported to Manager ==\n");
                            }
                            
                        }
                        else{
                            insert(counter->Missing,token_o2);
                        }
                    }

                        
                        }
                else if(option=='m')
                        {
                            struct token *missing_token = search_missing(counter->Missing);
                            if(missing_token!=NULL)
                                serve_customer(counter->stack,missing_token);
                        
}
              else if(option=='c')
                     {
                            correct_last_service(counter->stack, counter->problem);
}
            else
                         {
                            is_on=false;
}
                        
                
              
            }
                

                

                
                break;

            case 3:
            printf("=== Department Manager Terminal ===\n");
            struct Active Active_service_record;
            init_Active(&Active_service_record);
           char answer = question_answer("Monitor Counter - m | Add new Service - s | End of Day Reset - r\n");
            if(answer=='m'){
                
                struct Counter *counter_03 = display_counter_rtn_Q(counter_list);
                char answer = question_answer("Monitor Queue - q | Monitor Completed tokens - s | Monitor Problems - p \n");

                switch (answer)
                {
                case 'q':
                    {
                    struct token *token = print_Active_Queue(counter_03->queue,&Active_service_record);
                    if(token !=NULL)
                    { serve_customer(counter_03->stack,token);}
                    break;}
                case 's':
                    print_Active_Stack(counter_03->stack,&Active_service_record);
                    break;

                case 'p':
                    serve_customer(counter_03->stack,print_Active_Stack(counter_03->problem,&Active_service_record));
                    break;
                default:
                    break;
                }
        }
        else if(answer=='s'){
            enter_new();
        }

        else if(answer=='r')
        {
                char confirm = question_answer("Are you sure? All records will be cleared (y/n)\n");
                    if(confirm=='y'){
                    for(int i=0;i<2;i++){
                    clear_stack(counter_list[i]->stack);
                    clear_stack(counter_list[i]->problem);
        }
        printf("\n** All stacks cleared. System reset for new day **\n");
    }
    else{
        printf("** Reset cancelled **\n");
    }
}    
        else{
            printf("** Wrong input selected **\n");
        }
            
            



            
            break;
;

            case 4:
            printf("=== Completed Token Terminal ===");
            struct complete complete_list;
            init_complete(&complete_list);
            final_report(counter_list,&complete_list);
            break;


            

            case 5:
                printf("\nExiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
        
    
    }

