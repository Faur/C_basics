#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "IO.h"
#include "stack.h"

#define WORD_SIZE 3 //Number of character + 1 ('\0')


int main(){

	int rc, num_arg, key, i;
	char command[WORD_SIZE];
	struct Stack *head = NULL;

	rc = get_ints(1, &num_arg);
	check(rc == 0, "Couldn't read num_arg");

	for(i = 0; i < num_arg; i++){
		rc = read_word(WORD_SIZE, command);
		check(rc == WORD_SIZE-1, "Didn't read key properly; i = %d", rc);

		if(! strcmp(command, "PU")){
			rc = get_ints(1, &key);
			debug("key = %d", key);
			head = Stack_push(key, head);
			check_mem(head);
		} else if(! strcmp(command, "PO")){
			Stack_print_head(head);
			head = Stack_pop(head);
		}else {
			printf("command = '%s'.", command);
			log_err("main: bad 'command' argument,");
		}
		
	}

	debug("Stack_destroy_all(head)");
	Stack_destroy_all(head);
	return 0;
error:
	if(head) Stack_destroy_all(head);
	return 1;
}


