/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:19:05 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:19:05 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

static void	swap(void **first, void **second)
{
	char *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

static size_t	partition(void **elems, size_t l, size_t r, int (*compare_func)(void*, void*, unsigned short), unsigned short flags)
{
	size_t 	pivot;
	size_t	result;

	result = l;
	pivot = r;
	while (l < r)
	{
		if (compare_func(elems[pivot], elems[l], flags))
		{
			swap(&elems[result], &elems[l]);
			++result;
		}
		++l;
	}
	swap(&elems[pivot], &elems[result]);
	return (result);
}

static void	quick_sort_impl(void ***elems, size_t l, size_t r, int (*compare_func)(void*, void*, unsigned short), unsigned short flags)
{
	size_t	q;

	if (l < r)
	{
		q = partition(*elems, l, r - 1, compare_func, flags);
		quick_sort_impl(elems, l, q, compare_func, flags);
		quick_sort_impl(elems, q + 1, r, compare_func, flags);
	}
}

void	quick_sort(void ***elems, size_t count, int (*compare_func)(void*, void*, unsigned short), unsigned short flags)
{
	if (count > 0)
		quick_sort_impl(elems, 0, count, compare_func, flags);
}
