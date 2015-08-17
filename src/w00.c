#include <stdio.h>
#include "IO.h"
#include "dbg.h"


int main (int argc, char **argv){

	int rc, len;
	int *num = NULL;

	len = 2;
	num = malloc(len * sizeof(int));

	rc = get_ints(len, num);
	check(rc == 0, "Failed to read ints.") //If not, then error!

	printf("%d", num[1] + num[0]);

	free(num);
	return 0;

error:
	if(num) free(num);
	return -1;
}
