#ifndef COMPLETE_H
#define COMPLETE_H

#include "../Token_Generator/token.h"
#include "../Ongoing_Counter_Stack/stack.h"
#include "../Counter_Mangment_System/CMS.h"

// ============================
// Struct: Complete List
// ============================
struct complete {
    struct token *head;
    struct token *tail;
};


// ============================
// Function Declarations
// ============================

// Initialize complete list
void init_complete(struct complete *list);

// Insert token into complete list (circular doubly linked list)
void inser_to_complete(struct complete *list, struct token *token);

// Extract tokens from a counter's stacks
void extract_from_stack(struct Counter *counter, struct complete *list);

// Generate final report from all counters
void final_report(struct Counter* counter_list[], struct complete *list);
void complete_list_view(struct complete *list);

#endif