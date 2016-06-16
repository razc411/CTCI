#ifndef STACKSET_H
#define STACKSET_H

#include <stdlib.h>
#include <strings.h>

typedef struct StackSet{
    int index;
    int sets;
    int stack_size;
    Stack ** stacks;
}StackSet;

StackSet* allocateStackSet(int);
void pushSet(StackSet*, int);
int popSet(StackSet*, int*);
void addNewStack(StackSet*);
void deleteStackInSet(StackSet*);
void deleteStackSet(StackSet*);

StackSet * allocateStackSet(int size){
    StackSet * new_stackset = (StackSet*) malloc(sizeof(StackSet));
    new_stackset->index = 0;
    new_stackset->sets = 1;
    new_stackset->stack_size = size;
    new_stackset->stacks = (Stack**) malloc(sizeof(Stack*));
    new_stackset->stacks[0] = (Stack*) malloc(sizeof(Stack));

    return new_stackset;
}

void pushSet(StackSet * ss, int value){
    if(ss->index != (ss->stack_size - 1)){
	pushStack(ss->stacks[ss->sets - 1], value);
	ss->index++;
    } else if(ss->index == (ss->stack_size - 1)){ 
	addNewStack(ss);
	pushStack(ss->stacks[ss->sets - 1], value);
    }
}

int popSet(StackSet * ss, int * value){
    if(ss->index != 0){
	popStack(ss->stacks[ss->sets - 1], value);
	ss->index--;
	return 0;
    } else if (ss->index == 0 && ss->sets > 1){
        popStack(ss->stacks[ss->sets - 1], value);
	deleteStackInSet(ss);
	return 1;
    }
    
    return -1;
}

void addNewStack(StackSet * ss){ 
    Stack * new_stack = allocateStack(ss->stack_size);

    ss->sets++;
    ss->index = 0;
    realloc(ss->stacks, sizeof(Stack*) * ss->sets);
    ss->stacks[ss->sets - 1] = new_stack;
}

void deleteStackInSet(StackSet * ss){
    ss->sets--;
    ss->index = ss->stack_size - 1;
    free(ss->stacks[ss->sets]);
}

void deleteStackSet(StackSet * ss){
    for(int i = 0; i < ss->sets; i++){
	free(ss->stacks[i]); 
    }
    free(ss);
}

#endif
