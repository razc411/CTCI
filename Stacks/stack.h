#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct Node{
    struct Node * next;
    int data;
}Node;

typedef struct Stack{
    int current_size;
    int max_size;
    Node * head;
}Stack;

Stack* allocateStack(int);
void pushStack(Stack*, int);
int popStack(Stack*, int*);
void deleteStack(Stack*);

Stack * allocateStack(int size){
    Stack * new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->max_size = size;
    new_stack->current_size = 0;
    new_stack->head = (Node*) malloc(sizeof(Node));

    return new_stack;
}

void pushStack(Stack * st, int value){
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if(st->current_size == 0){
	st->head = new_node;
    } else {
	new_node->next = st->head;
	st->head = new_node;
    }

    st->current_size++;
}

int popStack(Stack * st, int * value){
    if(st->head != NULL){
	*value = st->head->data;
	Node * temp = st->head;
	st->head = temp->next;
	free(temp);
    } else {
	*value = 0;
	return -1;
    }
    return 0;
}

void deleteStack(Stack * st){
    Node * current = st->head;
    while(current != NULL){
	Node * temp = current;
	current = current->next;
	free(temp);
    }
    free(st);
}

#endif
