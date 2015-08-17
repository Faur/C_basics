#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "IO.h"
#include "search.h"

int main (){
	int rc, len_num;
	int *num = NULL;

	rc = get_ints(1, &len_num);
	check(rc == 0, "Did not read len_num properly.");
	if(len_num) {
		num = malloc(len_num * sizeof(int));
		rc = get_ints(len_num, num);
		check(rc == 0, "Did not read num propperly.");		

		rc = merge_sort(len_num, num);
		rc = int_print(len_num, num);
		check(rc == 0, "int_print failed.")
	}

	if(num) free(num);
	return 0;

error:
	if(num) free(num);
	return 1;
}