#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "IO.h"
#include "queue.h"

#define WORD_SIZE 2

int main() {

	int rc, i, len, key;
	char command[WORD_SIZE];
	struct Queue *head = NULL;


	// Read first number
	rc = get_ints(1, &len);
	check(rc == 0, "Didn't read len properly");

	// Take that number of actions
	for(i = 0; i < len; i++){
		debug("main: OLD *head = %p", head);

		rc = read_word(WORD_SIZE, command);
		check(rc == WORD_SIZE-1, "Didn't read command properly, rc = %d", rc);

		if(! strcmp(command, "E")){
			rc = get_ints(1, &key);
			check(rc == 0, "Didn't read key properly, i = %d, key = %d", i, key);
			head = Queue_enqueue(key, head);
			check_mem(head);
			debug("main: NEW *head = %p", head);

		} else if(! strcmp(command, "D")){
			Queue_print_head(head);
			head = Queue_dequeue(head);
			debug("main: NEW *head = %p", head);

		} else{
			log_err("Bad command argument, i = %d, command = %s", i, command);
		}
	}

	return 0;
error:
	return 1;
}