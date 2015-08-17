// #define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "IO.h"
#include "data_structure.h"

int main(){

	int a = 5;
	struct Single_link *head = sl_create( (void**)&a);

	printf("%d\n", *((int**)head->key) );
	// printf("%d\n", (int) head->key);

	char b[] = "asdf";
	struct Single_link * head2 = sl_create( (void**)&b);
	printf("%s\n", b);
	printf("%s\n", *(char**) head2->key);

	return 0;
}