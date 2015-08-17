
#include <stdlib.h>
#include "dbg.h"
#include "IO.h"

int binary_search(int low, int high, int key, int *num){
	// Recursive binary search.
	// Assumes num is organized in non-decreasing order
	int mid = (low + high)/2; //implicit floor
	debug("binary_search: low = %d, high = %d, key = %d, m = %d, num[%d] = %d",
							   low, 	 high, 		key, 	mid,	mid, num[mid]);

	if (key == num[mid]) return mid;
	else if (low >= high) return -1;
	else if (key < num[mid]) return binary_search(low, mid-1, key, num);
	else if (key > num[mid]) return binary_search(mid+1, high, key, num);
	return -2;
}


int merge(int len1, int *a1, int len2, int *a2, int len_merged, int *merged ){
	//Given two sorted arrays of integers, create one sorted array.
	//The arrays don't need to point to different peices of memory

	#ifndef NDEBUG
	printf("merge: len1 = %d - ", len1);
	int_print(len1, a1);
	printf("merge: len2 = %d - ", len2);
	int_print(len2, a2);
	printf("merge: len_merged = %d - ", len_merged);
	int_print(len_merged, merged);
	#endif

	int *tmp = malloc(len_merged * sizeof(int));

	check(len1 + len2 == len_merged, 
		"merge: Bad length arguments, %d + %d != %d.", len1, len2, len_merged);
	//check(a1 && a2 && len_merged, "merged: Bad pointers.");

	int i1 = 0; int i2 = 0; int i_merged = 0; int i;

	for(i_merged = 0; i_merged < len_merged; i_merged++){
		debug("");
		debug("merge: i_merged = %d", i_merged);
		if(i1 == len1){
			debug("merge: i1 = %d == %d = len1", i1, len1);
			for(; i2 < len2; i2++){
				tmp[i_merged++] = a2[i2];
				debug("merge: i_merged = %d, i2 = %d", i_merged, i2+1);
				debug("merge: tmp[i_merged] = %d, a2[i2] = %d", tmp[i_merged], a2[i2+1]);
			}
		} else if(i2 == len2){
			debug("merge: i2 = %d == %d = len2", i2, len2);
			for(; i1 < len1; i1++){
				tmp[i_merged++] = a1[i1];
				debug("merge: i_merged = %d, i1 = %d", i_merged, i1+1);
				debug("merge: tmp[i_merged] = %d, a1[i1] = %d", tmp[i_merged], a1[i1+1]);
			}
		} else {
			tmp[i_merged] = (a1[i1] < a2[i2]) ? a1[i1++] : a2[i2++];
			debug("merge: tmp[i_merged] = %d", tmp[i_merged]);
			debug("merge: a1[i1] = %d, a2[i2] = %d", a1[i1], a2[i2]);

		}
	}

	for(i = 0; i < len_merged; i++){
		merged[i] = tmp[i];
	}

	free(tmp);
	return 0;
error:
	if(tmp) free(tmp);
	return 1;
}


int merge_sort(int len, int *num){
	debug("merge_sort: len = %d", len);
	#ifndef NDEBUG
	int_print(len, num);
	#endif

	if(len == 1){
		return 0;
	}

	int mid = len/2; //implicit floor
	
	merge_sort(mid, num);
	merge_sort(len-mid, &num[mid]);
	merge(mid, num, len-mid, &num[mid], len, num);
	return 0;
}
