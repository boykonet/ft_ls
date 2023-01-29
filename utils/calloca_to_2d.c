#include <stdlib.h>
#include "../ls.h"

void **calloca_to_2d(size_t size)
{
	void	**ptr;
	size_t 	i;

	i = 0;
	ptr = ft_calloc(size, sizeof(void*));
	if (ptr == NULL)
		return (NULL);
	while (i < size)
		ptr[i++] = NULL;
	return ptr;
}