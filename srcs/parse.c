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

void	del_file_struct(void *file)
{
	t_file *f = (t_file*)file;

	if (f->filename)
	{
		free(f->filename);
		f->filename = NULL;
	}

	if (f->path)
	{
		free(f->path);
		f->path = NULL;
	}
}

char	*get_path(char *haystack, char **env)
{
	char	*path;

	if (!ft_strncmp(haystack, ".", ft_strlen(haystack)))
		path = find_env(env, "PWD");
	else
		path = ft_strdup(haystack);
	return (path);
}

int	copy_folders(t_list **files, char **srcs, char **env)
{
	t_list	*ptr;
	t_file	*new;
	int		i;

	if (files == NULL || !len_double_char_array(srcs))
		return (-1);

	new = ft_calloc(1, sizeof(t_file));
	if (!new)
		return (-1);

	new->filename = ft_strdup(srcs[0]);
	new->path = get_path(srcs[0], env);
	if (!new->filename || !new->path)
	{
		del_file_struct(new);
		free(new);
		return (-1);
	}

	*files = ft_lstnew(new);
	ptr = *files;
	i = 1;
	while (srcs[i]) {
		new = ft_calloc(1, sizeof(t_file));
		if (!new)
		{
			ft_lstclear(files, del_file_struct);
			return (-1);
		}

		new->filename = ft_strdup(srcs[i]);
		new->path = get_path(srcs[i], env);
		if (!new->filename || !new->path)
		{
			del_file_struct(new);
			free(new);
			ft_lstclear(files, del_file_struct);
			return (-1);
		}
		ptr->next = ft_lstnew(new);
		ptr = ptr->next;
		i++;
	}
	return (0);
}

char	*find_env(char **env, char *name)
{
	int i, len;

	i = 0;
	len = len_double_char_array(env);
	while (i < len)
	{
		char *s = ft_strnstr(env[i], name, ft_strlen(name));
		if (&env[i][0] == &s[0])
		{
			s = ft_strchr(s, '=');
			if (*(s + 1) == '\0')
				return (NULL);
			return (ft_strdup(s + 1));
		}
		i++;
	}
	return (NULL);
}

int	parse(t_ls *ls, int argc, char **argv, char **env)
{
	char	*param;
	int		counter;
	size_t	i;

	counter = 1;
	if (argc > 1)
	{
		while (argv[counter])
		{
			i = 0;
			param = argv[counter];
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
			counter++;
		}
		// Allocates memory for an array of pointers
		if (copy_folders(&ls->files, &argv[counter], env) == -1)
		{
//			free_double_char_array(ls->files);
			return (-1);
		}
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
