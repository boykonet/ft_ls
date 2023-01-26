#include "../ls.h"

int alloc_to(void **ptr, int size)
{
	*ptr = malloc(size * sizeof(void*));
	if (!*ptr)
		return (-1);
	return (0);
}


/* [][][][][][][][][][] */

/* [][][][][][][][][][] */
/* [][][][][][][][][][] */

/* int i = 100; */
/* int j = 50; */

/* alloca_to_2d(void ***ptr, int rows, int cols) { */
/* } */

/* char **suka = malloc(sizeof(char*) * i); */


/* int k = 0; */
/* char **sukap = suka; */
/* while (j > 0) */
/* { */
/* 	*sukap = malloc(sizeof(char) * j); */
/* 	sukap++; */
/* 	j++; */
/* } */

