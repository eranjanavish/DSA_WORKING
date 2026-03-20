#ifndef SERVICE_LIST_H
#define SERVICE_LIST_H

#include "../Token_Generator/token.h"  // needed

int size_service();
struct token;
void select_service(struct token *token);
void enter_new();
void bubble_sort();

#endif