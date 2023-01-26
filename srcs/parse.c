#include "../ls.h"


static void	add_flag(char **flags, char new_flag)
{
	int i;
	char *p;

	p = ft_strchr(*flags, new_flag);
	if (!p)
		return ;
	i = 0;
	while (i < MAX_COUNT_FLAGS_PER_COMMAND && *flags[i] != '\0')
	{
		if (*flags[i] == new_flag)
			return ;
		i++;
	}
	if (i == MAX_COUNT_FLAGS_PER_COMMAND)
		return ;
	*flags[i] = new_flag;
}

int	create_and_copy_folders(char ***dest, char **srcs)
{
	int		i;
	char	*value;

	i = 0;
	while (srcs[i]) {
		value = ft_strdup(srcs[i]);
		if (!value)
			return (-1);
		*dest[i++] = value;
	}
	return (0);
}

int	parse(t_ls *ls, int argc, char **argv)
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
			if (param[i++] == '-')
			{
				while (param[i] != '\0')
					add_flag((char **) &(ls->flags), param[i++]);
			} else
				break;
			counter++;
		}
		if (alloc_to((void **)ls->folders, len_double_char_array(&argv[counter])) == -1)
			return (-1);
		if (create_and_copy_folders(&ls->folders, &argv[counter]) == -1)
		{
			free_double_char_array(ls->folders);
			return (-1);
		}
	}
	return (0);
}
