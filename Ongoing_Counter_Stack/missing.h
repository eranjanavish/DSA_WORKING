#ifndef MISSING_H
#define MISSING_H

#include "../Token_Generator/token.h"

// Circular linked list of missing tokens
struct Missing_list {
    struct token *head;
    struct token *tail;
};

// Function declarations
void init_Missing_list(struct Missing_list *list);
void insert(struct Missing_list *list, struct token* token);
void delete_id(struct Missing_list *list, struct token* token);
struct token* search_missing(struct Missing_list *list);

#endif