#include "srcs.h"


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

int	parse(t_ls *ln, char **argv)
{
	char	**params;
	int		counter;
	int		i;
	size_t	largv;

	counter = 1;
	params = NULL;
	largv = 0;
	while (argv[counter])
	{
		i = 0;
		params = argv[counter];
		if (params[i++] == '-')
		{
			while (params[i] != '\0')
				add_flag((char**)&(ln->flags), params[i++]);
		}
		else
			break ;
		counter++;
	}
	if (!alloc_to((void**)ln->folders, len_double_char_array(&argv[counter])))
		return (-1);
	i = 0;
	while (argv[counter])
	{
		largv = ft_strlen(argv[counter]);
		if (!alloca_to((void**)&(ln->folders[i]), largv))
		{
			free_double_char_array(ln->folders);
			return (-1);
		}
		ft_memcpy(ln->folders[i++], argv[counter++], largv);
	}
	return (0);
}
