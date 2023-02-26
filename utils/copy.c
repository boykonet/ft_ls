#include "../ls.h"

char	**copy(const char **srcs, size_t len)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (srcs == NULL)
		return (NULL);
	arr = (char**)calloca_to_2d(len + 1);
	if (!arr)
		return (NULL);
	while (srcs[i] && i < len) {
		arr[i] = ft_strdup(srcs[i]);
		if (!arr[i])
		{
			free_2array((void**)arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
