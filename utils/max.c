#include <unistd.h>

void	max_spaces(size_t *first, size_t second)
{
	if (first == NULL)
		return ;
	if (*first < second)
		*first = second;
}
