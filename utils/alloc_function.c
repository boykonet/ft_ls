#include "utils.h"

int alloc_to(void **ptr, int size)
{
	*ptr = malloc(size * sizeof(void*));
	if (!*ptr)
		return (-1);
	return (0);
}

