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
    long long date;
    long long serviced_date;
};

struct token_list 
{
    struct token_list_item *head;
    struct token_list_item *tail;
};

struct token_list_item{
    int id;
    struct token_list_item *next;
};

/* Function Prototypes */

void initialize_token_list(struct token_list *list);
struct token_list_item* createToken(int id);
void insertToken(struct token_list *list, struct token_list_item *token);
void create_tokens_1_100(struct token_list *list);

struct token* issue_token(struct token_list *list);
char question_answer(char q[]);
struct token* copy_token(struct token* token);
long long gettime();
long long service_time(struct token *token);
#endif