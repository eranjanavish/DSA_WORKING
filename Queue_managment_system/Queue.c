void init_queue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

void enqueue(struct Queue *q, struct token *newToken) {
    if (!newToken) return;

    if (q->front == NULL) {
        q->front = newToken;
        q->rear = newToken;
        newToken->next = NULL;
    } else if (newToken->priority == 1) {
        if (q->front->priority != 1) {
            newToken->next = q->front;
            q->front = newToken;
        } else {
            struct token *temp = q->front;
            while (temp->next != NULL && temp->next->priority == 1) {
                temp = temp->next;
            }
            newToken->next = temp->next;
            temp->next = newToken;

            if (newToken->next == NULL) {
                q->rear = newToken;
            }
        }
    } else {
        q->rear->next = newToken;
        newToken->next = NULL;
        q->rear = newToken;
    }

    q->size++;
}

struct token* dequeue(struct Queue *q) {
    if (q->front == NULL) return NULL; 

    struct token *node = q->front;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = node->next;
    }

    node->next = NULL;
    q->size--;

    return node;
}

void peek(struct Queue* queue){
    if (queue->front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct token *token = queue->front;
    printf("\n===================\n");
    printf("Token id : %d\n",token->token_id);
    printf("Customer name : %s\n",token->name);
    printf("Customer id : %s\n",token->nic);
    printf("Customer Phone number : %d\n",token->phone_number);
    printf("CUstomer Address: %s\n",token->address);
    printf("Service type : %s\n",token->service);
    printf("\n===================\n");
}
