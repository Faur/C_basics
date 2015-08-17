#ifndef __IO_h__
#define __IO_h__

#include <stdio.h>
#include <stdlib.h> //malloc()
#include "dbg.h"

int get_ints(int len, int *num) {
	// Retrieve len white space seperated integers and place
	// them in the array num.	
	// http://stackoverflow.com/questions/2539796/c-reading-multiple-numbers-from-single-input-line-scanf
	
	if(len == 0) return 0; //Do nothing in case of empty list

	int i, rc;
	debug("get_ints: len = %d", len);
	for(i=0; i<len; i++){
		rc = scanf("%d", &num[i]);
		debug("get_ints: [%d] = %d", i, num[i]);
		check(rc > 0, "You have to enter a number");
	}

	return 0;
error:
	if(num) free(num);
	return 1;
}


			
int read_word(int max_len, char *target){
	// Ignores all leading whitespace and stops at the first whitespace or
	// when max_len is reached. target is always null-terminated
	char new_char;
	int i;

	while((new_char = fgetc(stdin) != ' ') && (new_char != '\n')
		&& (new_char != '\0') && (new_char == '\t'));

	for(i = 0; i < max_len - 1; i++){
		new_char = (char) fgetc(stdin);
		debug("read_word: i = %d, new_char = '%c'.", i, new_char);
		target[i] = new_char;

		if((new_char == ' ') || (new_char == '\n') 
			|| (new_char == '\0') || (new_char == '\t')){
			break;
		}
	}

	new_char = '\0';
	target[i] = new_char;
	debug("read_word: i = %d, new_char = '%c'", i, new_char);
	return i;
}


int int_print(int len, int *num){
	check(len >= 0, "int_print: bad argument: len = %d.", len);
	check_mem(num);
	int i;
	
	for(i = 0; i < len; i++){
		printf("%d ", num[i]);
	}
	printf("\n");

	return 0;
error:
	return 1;
}


#endif
