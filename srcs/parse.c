#include "../ls.h"

static int	is_flag_support(const char *sflags, char flag)
{
	int i;

	i = 0;
	while (i < MAX_COUNT_FLAGS_PER_COMMAND)
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
	if (i == MAX_COUNT_FLAGS_PER_COMMAND)
		return ;
	*flags[i] = new_flag;
}

int	copy_folders(char ***dest, char **srcs)
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
			if (param[i] == '-')
			{
				i++;
				while (param[i] != '\0')
				{
					if (is_flag_support(ls->sflags, param[i]) == 0)
						return (param[i]);
					add_flag(&ls->flags, param[i]);
					i++;
				}
			} else
				break ;
			counter++;
		}
		// Allocates memory for an array of pointers
		ls->folders = (char**)calloca_to_2d(len_double_char_array(&argv[counter]) + 1);
		if (ls->folders == NULL)
			return (-1);
		if (copy_folders(&ls->folders, &argv[counter]) == -1)
		{
			free_double_char_array(ls->folders);
			return (-1);
		}
	}
	return (0);
}
