    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include "../Service_List/service_list.h"
    #include "token.h"



    void initialize_token_list(struct token_list *list){
        list->head=NULL;
        list->tail=NULL;
        printf(" *** List Initialized succesfully! ***\n\n");
    }

    struct token_list_item* createToken(int id){
        struct token_list_item *token;
        token = (struct token_list_item*)malloc(sizeof(struct token_list_item));
        token->id = id;
        token->next=NULL;
        return token;



    }

    void insertToken(struct token_list *list, struct token_list_item *token){
        if (list->head==NULL){
            list->head=token;
            list->tail=token;
            token->next = token;
            
            
        }
        else{
            list->tail->next=token;
            list->tail=token;
            list->tail->next=list->head;
            

            
        }
        
    }

    void create_tokens_1_100(struct token_list *list){
        //create tokens and assign id to them and add them to the list
        for(int i=1;i<=3;i++){
            struct token_list_item *token = createToken(i);
            insertToken(list,token);
        }
        printf(" *** Daily Tokens Created ***\n\n");
    }

    


    long long gettime(){
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        return (long long)(t->tm_year + 1900) * 10000000000 +
            (long long)(t->tm_mon + 1) * 100000000 +
            (long long)t->tm_mday * 1000000 +
            (long long)t->tm_hour * 10000 +
            (long long)t->tm_min * 100 +
            (long long)t->tm_sec;
    }


int getHour(){
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    int hour = t->tm_hour;
    return hour;
            
}

struct token* gather_info(int id){
    struct token *token = (struct token*)malloc(sizeof(struct token));
    token->token_id = id;
    token->date = gettime();
    printf("\n========================================\n");
    printf("         CREATE NEW TOKEN               \n");
    printf("========================================\n\n");
    printf(" **          Token No : %d           **\n",token->token_id);
    printf("Enter Customer Name          : ");
    scanf("%s",token->name);
    printf("\nEnter Customer NIC         : ");
    scanf("%s",token->nic);
    printf("\nEnter Customer Adress      : ");
    scanf("%s",token->address);
    printf("\nEnter Customer Phone number   :");
    scanf("%d",&token->phone_number);
    select_service(token); 
    printf("\n Select Priority Level\n");
    printf("   1 -> High Priority\n");
    printf("   2 -> Low Priority\n");
    printf(" Enter choice : ");
    scanf("%d",&token->priority);
    
    printf("\n========================================\n");
    printf("        TOKEN CREATED SUCCESSFULLY      \n");
    printf("========================================\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n");
    return token;
}

int can_issue = 1;
struct token* issue_token(struct token_list *list){
        struct token_list_item *curr_token = list->head;
        list->head=list->head->next;
        list->tail=curr_token;
        
        int id = curr_token->id;

        if(curr_token->id == 3 && getHour()<12)
            {   
                can_issue = 0;
            }
        else if(curr_token->id < 3 && getHour()>=12){
            can_issue = 1;
        }
        else if(curr_token->id == 3 && getHour()>12){
            can_issue = 0;
        }

        if(can_issue){
            return gather_info(id);

        }
        else{
            printf("Token Limit Reached...\nResseting after next session\n\n");
            return NULL;
        }
        
       
        
        
        
        

    }

    long long service_time(struct token *token){
        return token->serviced_date - token->date; //get how many second it took to service a token
    }

    char question_answer(char q[20]){
        char answer;

        printf("%s",q);
        scanf(" %c",&answer);
        return answer;

    }

    struct token* copy_token(struct token* token){
        struct token *newNode = malloc(sizeof(struct token)); //copy a token from one struct to another
        *newNode = *token;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;


    }



