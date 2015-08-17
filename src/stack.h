// Implementation of a stack (LIFO) for integers, 
// using a single linked list

#ifndef __stack_h__
#define __stack_h__

#include <stdlib.h>
#include <stdio.h>
#include "dbg.h"

struct Stack{
	int key;
	struct Stack *prev;
};


struct Stack * Stack_create(int key){
	// Private
	struct Stack *new_node = malloc(sizeof(struct Stack));
	check_mem(new_node);

	new_node->key = key;
	new_node->prev = NULL;

	debug("Stack_create: new_node = %p, key = %i", new_node, key);

	return new_node;
error:
	return NULL;
}


struct Stack * Stack_push(int key, struct Stack *old_head){
	struct Stack *new_head = Stack_create(key);
	check_mem(new_head);

	if(old_head){
		new_head->prev = old_head;
	}

	return new_head;
error:
	return NULL;
}


int Stack_destroy(struct Stack *ptr){
	// Private
	check_mem(ptr);
	free(ptr);
	return 0;
error:
	return -1;
}


int Stack_destroy_all(struct Stack *ptr){
	check_mem(ptr);

	debug("ptr = %p, ptr->prev = %p.", ptr, ptr->prev);
	if(ptr->prev == NULL) {
		Stack_destroy(ptr);
		return 0;
	} else{
		Stack_destroy_all(ptr->prev);
	}
error:
	return -1;
}


struct Stack * Stack_pop(struct Stack *old_head){
	check_mem(old_head);

	struct Stack *new_head = old_head->prev;
	debug("Stack_pop: new_head = %p, old_head->prev = %p", new_head, old_head);
	debug("Stack_pop: &new_head = %p, &old_head->prev = %p", &new_head, &old_head);
	Stack_destroy(old_head);

	return new_head;
error:
	return NULL;
}


int Stack_print_head(struct Stack *head){
	check_mem(head);
	printf("%d\n", head->key);

	return 0;
error:
	return 1;
}

#endif


