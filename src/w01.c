#define NDEBUG // if defined, no debug()

#include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#include "dbg.h"

#define ALGORITHM 3

int is_top(int i, int max, int *num){
	check(i >= 0 && max >= i && num, "is_top: Bad index values.");

debug("i = %d, max = %d, num[%d] = %d, num[%d] = %d, num[%d] = %d", 
	         i,     max,    i-1, num[i-1],  i, num[i],  i+1, num[i+1]);
	if(i == 0){
		if(num[0] >= num[1]) return 1;
		return 0;
	} else if(i == max){
		if(num[max] >= num[max-1]) return 1;
		return 0;
	} else if(num[i-1] <= num[i] && num[i] >= num[i+1]) {
		return 1;
	}
	return 0;

error:
	return -1;
}

int toppunkt1(int num_size, int *num){
	//linear search to a toppoint
	int i, rc;

	for(i = 0; i < num_size; i++){
		debug("toppunkt1: i = %d", i);
		rc = is_top(i, num_size-1, num);
		debug("toppunkt1: rc = %d", rc);
		check(rc >= 0, "Didn't find a top point.") 
		if(rc) return i;
	}

error:
	return -1;
}

int find_max(int size, int *num){
	//linear search to the highest number
	check(size >= 0, "find_max: Bad size argument: %d", size);
	check_mem(num);

	int i, cur_max = 0;
	for(i = 0; i < size; i++){
		if(num[cur_max] < num[i]) cur_max = i;
	}
	return cur_max;

error:
	return -1;
}

int toppunkt3(int low, int high, int max, int *num){
	// Recursively look towards the center
	int m = (low + high)/2; //implicit floor

	if(is_top(m, max, num)) {
		return m;
	} else if(num[m] < num[m-1]) {
		return toppunkt3(low, m-1, max, num);
	} else if(num[m] < num[m+1]) {
		return toppunkt3(m + 1, high, max, num);
	}

	return -1;
}

int main(){ //int argc, char **argv

	int rc, ans, num_size;
	int *num = NULL;

	rc = get_ints(1, &num_size);
	check(rc == 0, "Didn't read num_size properly");
	debug("num_size = %d", num_size);

	num = malloc(num_size * sizeof(int));
	check_mem(num);
	rc = get_ints(num_size, num);
	check(rc == 0, "Didn't read num properly");

	switch(ALGORITHM){
		case 1:
			rc = toppunkt1(num_size, num);
			check(rc >= 0, "Failed to find a top point w. alg 1.");
			break;
		case 2:
			rc = find_max(num_size, num);
			check(rc >= 0, "Failed to find a maximum value.");
			break;
		case 3:
			rc = toppunkt3(0, num_size-1, num_size-1, num);
			check(rc >= 0, "Failed to find a top point w. alg 3.");
			break;
		default:
			log_err("Bad ALGORITHM argument: %d", ALGORITHM);
			break;
	}

	ans = rc;
	printf("%d\n", ans);

	free(num);
	return 0;

error:
	if(num) free(num);
	return 1;
}

