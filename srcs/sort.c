#include "../ls.h"

static void	bubble(char **first, char **second)
{
	char *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

void	lexicography_sort(char ***array)
{
	int i, j;
	int len = len_double_char_array((const char**)*array);

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strncmp(*array[i], *array[j], ft_strlen(*array[i]) > ft_strlen(*array[j]) ? ft_strlen(*array[i]) : ft_strlen(*array[j])) > 0)
				bubble(array[i], array[j]);
			j++;
		}
		i++;
	}
}
