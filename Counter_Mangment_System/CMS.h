#ifndef CMS_H
#define CMS_H

#include "../Token_Generator/token.h"
#include "../Queue_managment_system/Queue.h"
#include "../Ongoing_Counter_Stack/stack.h"
#include "../Ongoing_Counter_Stack/missing.h"

extern int number_of_counters;

struct Counter
{
    
    int id;
    struct Stack *stack;
    struct Queue *queue;
    
    struct Missing_list *Missing;
    struct Stack *problem;


};

/* Function Prototypes */

struct Counter* assign_counter_id(int id);

void insert_counter(struct Counter* counters[], struct Counter *counter, int index);

void create_counters(struct Counter* counter_list[]);

void sort_counters(struct Counter* counter_list[]);

void display_counter(struct Counter* counter_list[], struct token *token);
struct Counter* display_counter_rtn_Q(struct Counter* counter_list[]);

#endif
