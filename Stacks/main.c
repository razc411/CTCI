#include <stdio.h>
#include "stack.h"
#include "stackset.h"

int main(){
    StackSet * ss = allocateStackSet(3);
    pushSet(ss, 5);
    pushSet(ss, 4);
    pushSet(ss, 3);
    pushSet(ss, 2);
    pushSet(ss, 1);
    
    for(int i = 0; i < 5; i++){
	int value;
	printf("Set: %d, Index: %d\n", ss->sets, ss->index);
	popSet(ss, &value);
	printf("-->%d\n", value);
    }
    printf("\n");

    deleteStackSet(ss);
    
    return 0;
}
