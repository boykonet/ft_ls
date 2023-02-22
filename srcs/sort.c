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
	char	**ptr;
	int		i, j;
	int		len;

	if (!array || !*array)
		return ;

	ptr = *array;
	len = len_2_pointer_array((const void**)ptr);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			size_t	isize = ft_strlen(ptr[i]);
			size_t	jsize = ft_strlen(ptr[j]);
			if (ft_strncmp(ptr[i], ptr[j], isize > jsize ? isize : jsize) > 0)
				bubble(&ptr[i], &ptr[j]);
			j++;
		}
		i++;
	}
}
