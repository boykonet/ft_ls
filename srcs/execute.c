#include "../ls.h"

int	handle_recursive_flag(int a)
{
	printf("handle_recursive_flag\n");
	return (a);
}


int	handle_a_flag(int a)
{
	printf("handle_a_flag\n");
	return (a);
}

int	handle_l_flag(int a)
{
	printf("handle_l_flag\n");
	return (a);
}

int	handle_r_flag(int a)
{
	printf("handle_r_flag\n");
	return (a);
}

int	handle_t_flag(int a)
{
	printf("handle_t_flag\n");
	return (a);
}

int is_recursive_flag(const char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'R')
			return (1);
		i++;
	}
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
	int		i, counter, is_recursive;

	i = 0;
	is_recursive = is_recursive_flag(ls->flags);
	while (1)
	{
		flag = ls->flags[i];

		counter = 0;
		while (counter < MAX_COUNT_FLAGS_PER_COMMAND)
		{
//			if (ls->sflags[counter] == ls->flags[i])
//			{
//				printf("flag - %c, result %d", flag, ls->func[counter](counter));
//			}
			counter++;
		}
		if (counter == MAX_COUNT_FLAGS_PER_COMMAND)
			return (flag);
		i++;
		if (i >= MAX_COUNT_FLAGS_PER_COMMAND)
			break ;
	}
	return (0);
}

