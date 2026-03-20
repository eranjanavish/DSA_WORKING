#ifndef TOKEN_H
#define TOKEN_H
#include "../Service_List/service_list.h"
struct token
{
    int token_id;
    int phone_number;
    char nic[15];
    char name[20];
    char address[30];
    int priority;
    struct token *next;
    struct token *prev;
    char service[50];
};

struct token_list 
{
    struct token *head;
    struct token *tail;
};

/* Function Prototypes */

void initialize_token_list(struct token_list *list);
struct token* assign_token_id(int id);
void insert_token(struct token_list *list, struct token *token);
void create_tokens_1_100(struct token_list *list);
void Display(struct token_list *list);
struct token* issue_token(struct token_list *list);
char question_answer(char q[]);
struct token* copy_token(struct token* token);

#endif