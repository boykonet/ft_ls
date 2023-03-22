#include "../ls.h"

char	**copy(const char **srcs, size_t len)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (srcs == NULL)
		return (ft_calloc(1, sizeof(char*)));
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

static int	count_of_dirs(t_fileinfo **files)
{
	size_t	i, count;

	count = 0;
	i = 0;
	while (files[i])
	{
		if (files[i]->type == S_IFDIR)
			count++;
		i++;
	}
	return (count);
}

char	**copy_dirs(t_fileinfo **files)
{
	char	**dirs;
	size_t	i, j, count;

	if (files == NULL)
		return (ft_calloc(1, sizeof(char*)));

	count = count_of_dirs(files);
	dirs = (char**)ft_calloc(count + 1, sizeof(char*));
	if (!dirs)
		return (NULL);
	i = 0;
	j = 0;
	while (files[i])
	{
		if (files[i]->type == S_IFDIR)
		{
			dirs[j] = ft_strdup(files[i]->filename);
			if (!dirs[j])
			{
				free_2array((void**)dirs);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (dirs);
}
