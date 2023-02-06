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

int	copy_folders(char ***dest, char **srcs, char **env)
{
	int		i;
	char	*value;

	i = 0;
	while (srcs[i]) {
		if (!ft_strncmp(srcs[i], ".", ft_strlen(srcs[i])))
			value = find_env(env, "PWD");
		else
			value = ft_strdup(srcs[i]);
		if (!value)
			return (-1);
		*dest[i++] = value;
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
	int		i;

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
		ls->files = (char**)calloca_to_2d(len_double_char_array(&argv[counter]) + 1);
		if (ls->files == NULL)
			return (-1);
		if (copy_folders(&ls->files, &argv[counter], env) == -1)
		{
			free_double_char_array(ls->files);
			return (-1);
		}
	}
	else
	{
		ls->files = (char**)calloca_to_2d(1 + 1);
		if (ls->files == NULL)
			return (-1);
		ls->files[0] = find_env(env, "PWD");
		if (ls->files[0] == NULL)
		{
			free_double_char_array(ls->files);
			return (-1);
		}
	}
	return (0);
}
