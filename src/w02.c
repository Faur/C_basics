//#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "IO.h"
#include "search.h"

# define ALGORITHM 2

int main (){

	int rc, i, len_num, len_key, ans;
	int *num = NULL;
	int *key = NULL;
	int *num_both = NULL;

	rc = get_ints(1, &len_num);
	check(rc == 0, "Did not read len_num properly.");
	num = malloc(len_num * sizeof(int));
	rc = get_ints(len_num, num);
	check(rc == 0, "Did not read num propperly.");

	rc = get_ints(1, &len_key);
	check(rc == 0, "Did not read len_key properly.");	
	key = malloc(len_key * sizeof(int));
	rc = get_ints(len_key, key);
	check(rc == 0, "Did not read key propperly.");


	switch(ALGORITHM){
		case 1:
			if(len_num == 0){
				// No numbers are part of the empty list
				ans = -1;
				rc = int_print(1, &ans);
				check(rc == 0, "int_print failed.")
				free(num);
				free(key);
				return 0;
			}
			for(i = 0; i < len_key; i++){
				debug("Main for loop; i = %d", i);
				rc = binary_search(0, len_num-1, key[i], num);
				check(rc >= -1, "binary_search failed with key[%d] = %d",
					i, key[i]);
				ans = rc;
				rc = int_print(1, &ans);
				check(rc == 0, "int_print failed.")
			}
			break;
		case 2:
			rc = 2;
			int len_both = len_num + len_key;
			num_both = malloc(len_both * sizeof(int));
			rc = merge(len_num, num, len_key, key, len_both, num_both);
			rc = int_print(len_both, num_both);
			check(rc == 0, "int_print failed.")
			break;
		default:
			log_err("Bad ALGORITHM argument");
	}

	free(num);
	free(key);
	if(num_both) free(num_both);
	return 0;

error:
	if(num) free(num);
	if(key) free(key);
	if(num_both) free(num_both);
	return 1;
}