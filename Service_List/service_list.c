#include <stdio.h>
#include <string.h>
#include "../Token_Generator/token.h"
#include "service_list.h"

struct token;

char service_list[10][50] = {
    "ID & Personal Documents",
    "Transport Services",
    "Administrative Services",
    "Financial & Tax Services",
    "-1"
};

int size_service() {
    int i = 0;

    while (strcmp(service_list[i], "-1") != 0) {
        i++;
    }

    return i;
}

void select_service(struct token *token){
    bubble_sort();
    printf("\n\n +++ Service List +++\n");
    for(int i=0;i<size_service();i++){
        printf("%d). %s\n",i+1,service_list[i]);
    }
    
    while (1)
    {
        printf(" +++ Enter service number +++\n");
        int n;
        scanf("%d",&n);
        
        if(n>0 && n<=size_service()){
            
            strcpy(token->service,service_list[n-1]);
            break;
        }
        else
        {
            printf("Wrong Index\n");
        }
    }
    
    
    
}

void enter_new(){
    int size = size_service();
    if (size >= 9) {
        printf("++++ Service list is full! ++++\n");
        return;
    }
    printf("=== Enter New service ===\n");
    char new_service[50];
    scanf(" %[^\n]", new_service);
    
    strcpy(service_list[size],new_service);
    strcpy(service_list[size+1],"-1");
    printf("+++ Service Entered to the System +++\n");
    
    
}

void bubble_sort(){
    int size = size_service();

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){

            if(service_list[j][0] > service_list[j+1][0]){  // descending

                char temp[50];

                strcpy(temp, service_list[j]);
                strcpy(service_list[j], service_list[j+1]);
                strcpy(service_list[j+1], temp);
            }
        }
    }
}
