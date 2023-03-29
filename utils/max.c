#include <unistd.h>

int		max(int first, int second)
{
	return (first > second ? first : second);
}

void	max_spaces(size_t *first, size_t second)
{
	if (first == NULL)
		return ;
	if (*first < second)
		*first = second;
}
