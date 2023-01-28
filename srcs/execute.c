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

//typedef int (*f) (int);

/*
** -1 - malloc error
** 0 - OK
** 33...126 - flag not support and number is flag from ascii table (only for decimal)
*/
int	execute(t_ls *ls)
{
	char	flag;
	int		i, counter;
//	char	flags[MAX_COUNT_FLAGS_PER_COMMAND] = { 'R', 'a', 'l', 'r', 't' };
//	f		func[MAX_COUNT_FLAGS_PER_COMMAND] = { &handle_recursive_flag, &handle_a_flag, &handle_l_flag, &handle_r_flag, &handle_t_flag };

	i = 0;
	while (1)
	{
		flag = ls->flags[i];

		counter = 0;
		while (counter < MAX_COUNT_FLAGS_PER_COMMAND)
		{
			if (ls->sflags[counter] == ls->flags[i])
			{
				printf("flag - %c, result %d", flag, ls->func[counter](counter));
			}
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

