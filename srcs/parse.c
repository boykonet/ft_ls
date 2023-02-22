#include "../ls.h"

static int	is_flag_support(const char *sflags, char flag)
{
	int i;

	i = 0;
	while (i < MAX_FLAGS)
	{
		if (sflags[i++] == flag)
			return (1);
	}
	return (0);
}

static void	add_flag(char flags[MAX_FLAGS + 1], char new_flag)
{
	int i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == new_flag)
			return ;
		i++;
	}
	if (i == MAX_FLAGS)
		return ;
	flags[i] = new_flag;
}

static char	**copy(char **srcs)
{
	int		i;
	size_t	len;

	i = 0;
	if (!srcs)
		return (NULL);
	len = len_2_pointer_array((const void**)srcs);
	arr = (char**)calloca_to_2d(len + 1);
	if (!arr)
		return (NULL);
	while (srcs[i]) {
		arr[i] = ft_strdup(srcs[i]);
		if (!arr[i])
		{
			free_2_pointer_array((void**)arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

int		parse_flags(char ***data, char *flags, t_err *err)
{
	char	*param;

	while (*data)
	{
		param = **data;
		if (*param == '-')
		{
			param++;
			while (*param != '\0')
			{
				if (!is_flag_support(CONST_FLAGS, *param))
					return (flag_not_support_error(err, *param));
				add_flag(flags, *param);
				param++;
			}
		} else
			break ;
		(*data)++;
	}
	return (0);
}

static char	**copy_filenames(char **data)
{
	char	**filenames;
	char	*base_dirs[2] = {".", NULL};

	// If no filenames, returns NULL in each case
	if (len_2_pointer_array((const void**)data) > 0)
		filenames = copy(data);
	else
		filenames = copy(base_dirs);
	return (filenames);
}

int		parse_filenames(char **data, char ***filenames, t_err *err)
{
	if (!filenames)
		return (-1);
	*filenames = copy_filenames(data);
	if (!(*filenames))
		return (sww(err, MALLOC_ERROR));
	return (0);
}
