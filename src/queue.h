
#ifndef __queue_h__
#define __queue_h__

#include <stdlib.h>
#include <stdio.h>
#include "dbg.h"

struct Queue{
	int key;
	struct Queue *next;
	struct Queue *tail;
};

struct Queue * Queue_create(int key){
	//Private
	struct Queue *new_node = malloc(sizeof(struct Queue));
	check_mem(new_node);
	new_node->key = key;
	new_node->tail = new_node;
	new_node->next = NULL;

	return new_node;
error:
	return NULL;
}

struct Queue * Queue_enqueue(int key, struct Queue *head){
	struct Queue *new_node = Queue_create(key);
	check_mem(new_node);

	if(head != NULL){
		head->tail->next = new_node;
		head->tail = new_node;
		return head;
	} else {
		return new_node;
	}
error:
	return NULL;
}

struct Queue * Queue_delete(struct Queue *head){
	// Private
	check_mem(head);
	struct Queue * new_head = head->next;
	debug("Queue_delete: *head->next = %p", head->next);

	free(head);
	debug("Queue_delete: *head = %p", head);
	debug("Queue_delete: *new_head = %p", new_head);

	return new_head;
error:
	return NULL;
}

struct Queue * Queue_dequeue(struct Queue *head){
	check_mem(head);

	if(head->next != NULL){
		head->next->tail = head->tail;		
	}

	return Queue_delete(head);
error:
	return NULL;
}

// recursive delete all

void Queue_print_head(struct Queue *head){
	printf("%d\n", head->key);
}





#endif