#ifndef __data_structure_h__
#define __data_structure_h__

#include <stdlib.h>
#include <stdio.h>
#include "dbg.h"


struct Single_link{
	void ** key;
	struct Single_link *ptr;
};

struct Single_link * sl_create(void **key){
	// Private
	struct Single_link *new_node = malloc(sizeof(struct Single_link));
	check_mem(new_node);

	new_node->key = (void**) malloc(sizeof(*key));
	check_mem(new_node->key);
	new_node->key = *key;

	new_node->ptr = NULL;

	// debug("sl_create: new_node->key = %d", (int) new_node->key);
	return new_node;

	error:
	return NULL;
}

int sl_destroy(struct Single_link *node){
	// Private
	check_mem(node);
	free(node->key);
	free(node);
	return 0;

	error:
	return -1;
}

int sl_destroy_all(struct Single_link *node){
	check_mem(node);

	if(node->ptr == NULL){
		sl_destroy(node);
		return 0;
	} else{
		sl_destroy_all(node->ptr);
	}

	error:
	return -1;
}

int sl_print(char *type, struct Single_link *node){
	check_mem(node);

	if (! strcmp(type, "%d")){
		printf("%d\n", (int) node->key);
		return 0;
	} else if(! strcmp(type, "%c")){
		printf("%s\n", (char*) node->key);
		return 0;		
	}


	log_err("Didn't recognize type = %s.", type);
	error:
	return -1;
}

#endif


