#include <stdlib.h>

void **calloca_to_2d(size_t size)
{
	void	**ptr;
	size_t 	i;

	i = 0;
	ptr = malloc(sizeof(void*) * size);
	if (ptr == NULL)
		return (NULL);
	while (i < size)
		ptr[i++] = NULL;
	return ptr;
}