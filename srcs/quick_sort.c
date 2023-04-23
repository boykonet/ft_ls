#include "../ls.h"

static void	swap(void **first, void **second)
{
	char *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

static int	partition(void **elems, size_t l, size_t r, int (*compare_func)(void*, void*, int), int is_inverted)
{
	size_t 	pivot;
	size_t	result;

	result = l;
	pivot = r;
	while (l < r)
	{
		if (compare_func(elems[pivot], elems[l], is_inverted))
		{
			swap(&elems[result], &elems[l]);
			++result;
		}
		++l;
	}
	swap(&elems[pivot], &elems[result]);
	return (result);
}

static void	quick_sort_impl(void ***elems, int l, int r, int (*compare_func)(void*, void*, int), int is_inverted)
{
	int	q;

	if (l < r)
	{
		q = partition(*elems, l, r - 1, compare_func, is_inverted);
		quick_sort_impl(elems, l, q, compare_func, is_inverted);
		quick_sort_impl(elems, q + 1, r, compare_func, is_inverted);
	}
}

void	quick_sort(void ***elems, size_t count, int (*compare_func)(void*, void*, int), int is_inverted)
{
	if (count > 0)
		quick_sort_impl(elems, 0, count, compare_func, is_inverted);
}