#include "../ls.h"

int 	is_more_equal(long first, long second)
{
	return (first >= second);
}

int		is_more(long first, long second)
{
	return (first > second);
}

int		is_less_equal(long first, long second)
{
	return (first <= second);
}

int		is_less(long first, long second)
{
	return (first < second);
}
