#include "../ls.h"

//char	*get_path(char *haystack, char **env)
//{
//	char	*path;
//
//	if (!ft_strncmp(haystack, ".", ft_strlen(haystack)))
//		path = find_env(env, "PWD");
//	else
//		path = ft_strdup(haystack);
//	return (path);
//}

//char	*find_env(char **env, char *name)
//{
//	int i, len;
//
//	i = 0;
//	len = len_double_char_array(env);
//	while (i < len)
//	{
//		char *s = ft_strnstr(env[i], name, ft_strlen(name));
//		if (&env[i][0] == &s[0])
//		{
//			s = ft_strchr(s, '=');
//			if (*(s + 1) == '\0')
//				return (NULL);
//			return (ft_strdup(s + 1));
//		}
//		i++;
//	}
//	return (NULL);
//}

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

char	**copy_folders(char **srcs)
{
	char	**arr;
	int		i;
	size_t	len;

	i = 0;
	len = len_double_char_array((const char**)srcs);
	arr = (char**)calloca_to_2d(len + 1);
	if (!arr)
		return (NULL);
	while (srcs[i]) {
		arr[i] = ft_strdup(srcs[i]);
		if (!arr[i])
		{
			free_double_char_array(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

void	print_malloc_error_and_exit(int errcode)
{
	write(CSTDERR, MALLOC_ERROR, ft_strlen(MALLOC_ERROR));
	exit(errcode);
}

int	parse_flags(t_ls *ls, char ***argv)
{
	char	**p;
	char	*param;

	p = *argv;
	while (p)
	{
		param = *p;
		if (*param == '-')
		{
			param++;
			while (*param != '\0')
			{
				if (!is_flag_support(CONST_FLAGS, *param))
				{
					if (flag_not_support_error(&ls->err, *param) == -1)
						print_malloc_error_and_exit(1);
					return (-1);
				}
				add_flag(ls->flags, *param);
				param++;
			}
		} else
			break ;
		p++;
	}
	*argv = p;
	return (0);
}

int	parse(t_ls *ls, int argc, char **argv)
{
	char	*base_dirs[2] = {".", NULL};

	if (argc > 1)
	{
		argv += 1;
		if (parse_flags(ls, &argv) == -1)
			return (-1);
		// Allocates memory for an array of pointers
		ls->files = copy_folders(argv);
		if (!ls->files)
			return (-1);
	}
	else
	{
		ls->files = copy_folders(base_dirs);
		if (!ls->files)
			return (-1);
	}
	return (0);
}
