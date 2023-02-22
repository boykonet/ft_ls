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

char	**copy_filenames(char **srcs)
{
	char	**arr;
	int		i;
	size_t	len;

	i = 0;
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

// void	print_malloc_error_and_exit(int errcode)
// {
// 	write(CSTDERR, MALLOC_ERROR, ft_strlen(MALLOC_ERROR));
// 	exit(errcode);
// }

char	*parse_flags(char ***data, t_err *err)
{
	char	*param;
	char 	*flags;

	flags = ft_calloc(MAX_FLAGS + 1, sizeof(char));
	if (!flags)
	{
		if (malloc_error(err) == -1)
			print_malloc_error_and_exit(1);
		return (NULL);
	}
	while (*data)
	{
		param = **data;
		if (*param == '-')
		{
			param++;
			while (*param != '\0')
			{
				if (!is_flag_support(CONST_FLAGS, *param))
				{
					if (flag_not_support_error(err, *param) == -1)
						print_malloc_error_and_exit(1);
					return (NULL);
				}
				add_flag(flags, *param);
				param++;
			}
		} else
			break ;
		(*data)++;
	}
	return (flags);
}

char	**copy_files_info(char **data, t_err *err)
{
	char	**filenames;

	filenames = copy_filenames(data);
	if (!filenames)
	{
		if (malloc_error(err) == -1)
			print_malloc_error_and_exit(1);
		return (NULL);
	}
	return (filenames);
}

char	**parse_filenames(char ***data, t_err *err)
{
	char	**filenames;
	char	*base_dirs[2] = {".", NULL};

	// If no filenames, returns NULL in each case
	if (len_2_pointer_array((const void**)(*data)) > 0)
		filenames = copy_files_info(*data, err);
	else
		filenames = copy_files_info(base_dirs, err);
	return (filenames);
}
