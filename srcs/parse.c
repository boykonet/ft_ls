#include "../ls.h"

static int	is_flag_support(const char *cflags, char flag)
{
	int i;

	i = 0;
	while (i < MAX_FLAGS)
	{
		if (cflags[i++] == flag)
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

static char	**copy_filenames(char **data)
{
	char	**filenames;
	char	*base_dirs[2] = {".", NULL};

	// If no filenames, returns NULL in each case
	if (len_2array((const void **) data) > 0)
		filenames = copy((const char**)data, len_2array((const void **) data));
	else
		filenames = copy((const char**)base_dirs, len_2array((const void **) base_dirs));
	return (filenames);
}

int		parse_flags(char ***data, char *flags[MAX_FLAGS + 1], t_list **patterns)
{
	char	*param;
	int 	errcode;

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
					errcode = add_pattern(patterns, PATTERN_FLAG_NOT_SUPPORT, (char[2]){*param, '\0'});
					return (errcode != 0 ? errcode : -4);
				}
				add_flag(*flags, *param);
				param++;
			}
		} else
			break ;
		(*data)++;
	}
	return (0);
}

int		parse_filenames(char **data, char ***filenames)
{
	if (!filenames || !data)
		return (-2);
	*filenames = copy_filenames(data);
	if (!(*filenames))
		return (-1);
	return (0);
}
