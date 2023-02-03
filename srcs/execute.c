#include "../ls.h"

int	handle_recursive_flag(void *p)
{
	t_ls *ls = (t_ls*)p;
	int i = 0;
	while (i < len_double_char_array(ls->folders))
	{
		printf("handle_recursive_flag %s\n", ls->folders[i]);
	}
	return (0);
}


int	handle_a_flag(void *p)
{
	t_ls *ls = (t_ls*)p;
	printf("handle_a_flag %s\n", ls->flags);
	return (0);
}

int	handle_l_flag(void *p)
{
	t_ls *ls = (t_ls*)p;
	printf("handle_l_flag %s\n", ls->flags);
	return (0);
}

int	handle_r_flag(void *p)
{
	t_ls *ls = (t_ls*)p;
	printf("handle_r_flag %s\n", ls->flags);
	return (0);
}

int	handle_t_flag(void *p)
{
	t_ls *ls = (t_ls*)p;
	printf("handle_t_flag %s\n", ls->flags);
	return (0);
}

int is_recursive_flag(const char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'R')
		{
			// TODO: remove this flag
			return (1);
		}
		i++;
	}
	return (0);
}

//int	remove_flag(char **flags)
//{
//
//}

int	if_not_dirs_or_dot(char *dir)
{
	if (dir == NULL)
		return (1);
	if (ft_strncmp(dir, ".", ft_strlen(dir)) == 0)
		return (1);
	return (0);
}

/*
** -1 - malloc error
** 0 - OK
** 33...126 - flag not support and number is flag from ascii table (only for decimal)
*/
int	execute(t_ls *ls)
{
	char	flag;
	int		i, is_recursive;
	t_list	*rs;

	i = 0;
	is_recursive = is_recursive_flag(ls->flags);
	while (is_recursive && i < MAX_COUNT_FLAGS_PER_COMMAND)
	{
		if (is_recursive)
		{
			flag = 'R';
			is_recursive = 0;
		}
		else
			flag = ls->flags[i++];

		int j = 0;
		while (j < MAX_COUNT_FLAGS_PER_COMMAND)
		{
			if (ls->sflags[j] == flag)
				ls->func[j]((void*)ls);
			j++;
		}
		// TODO: remove after test
		i++;
	}
	return (0);
}


/*
 *                . -> . -> | -> . -> . -> . -> . -> . -> . -> . -> |
 *                          . -> . -> | -> . -> |                   . -> |
 *                                    . -> .    . -> . -> .
 *
 */

