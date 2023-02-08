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

static void	add_flag(char **flags, char new_flag)
{
	int i;

	i = 0;
	while (*flags[i] != '\0')
	{
		if (*flags[i] == new_flag)
			return ;
		i++;
	}
	if (i == MAX_FLAGS)
		return ;
	*flags[i] = new_flag;
}

//void	del_file_struct(void *file)
//{
//	t_file *f = (t_file*)file;
//
//	if (f->filename)
//	{
//		free(f->filename);
//		f->filename = NULL;
//	}
//
//	if (f->path)
//	{
//		free(f->path);
//		f->path = NULL;
//	}
//}

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

char	**copy_folders(char **srcs)
{
	char	**arr;
	int		i;
	size_t	len;

	i = 0;
	len = len_double_char_array((const char**)srcs);
	arr = ft_calloc(len, sizeof(char*));
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

//void	parse_flags(t_list *ls, char ***argv)
//{
//
//}

int	parse(t_ls *ls, int argc, char **argv)
{
	char	*param;
	size_t	i;

	if (argc > 1)
	{
		argv += 1;
		while (*argv)
		{
			i = 0;
			param = *argv;
			if (param[i] == '-')
			{
				i++;
				while (param[i] != '\0')
				{
					if (is_flag_support(CONST_FLAGS, param[i]) == 0)
						return (param[i]);
					add_flag(&ls->flags, param[i]);
					i++;
				}
			} else
				break ;
			argv++;
		}
		// Allocates memory for an array of pointers
		ls->files = copy_folders(argv);
		if (!ls->files)
			return (-1);
	}
	else
	{
//		ls->files = (char**)calloca_to_2d(1 + 1);
//		if (ls->files == NULL)
//			return (-1);
//		ls->files[0] = find_env(env, "PWD");
//		if (ls->files[0] == NULL)
//		{
//			free_double_char_array(ls->files);
//			return (-1);
//		}
	}
	return (0);
}
