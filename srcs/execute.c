#include "../ls.h"

# define MALLOC_ERROR	"malloc error"
# define FLAG_NOT_SUPPORT_1 "ls: illegal option -- "
# define FLAG_NOT_SUPPORT_2 "\nusage: ls [-Ralrt] [file ...]"

static int	flag_not_support(char **emessage, char flag)
{
	size_t	cbytes;
	char	*ptr;
	size_t	lfns1;
	size_t	lfns2;
	
	cbytes = 0;
	ptr = NULL;
	lfns1 = ft_strlen(FLAG_NOT_SUPPORT_1);
	lfns2 = ft_strlen(FLAG_NOT_SUPPORT_2);
	if (alloc_to((void**)emessage, lfns1 + 1 + lfns2) == -1)
	{
		*emessage = ft_strdup(MALLOC_ERROR);
		return (-1);
	}
	ptr = *emessage;
	cbytes += ft_strlcpy(&ptr[0], FLAG_NOT_SUPPORT_1, lfns1);
	cbytes += ft_strlcpy(&ptr[cbytes - 1], (char*)&flag, 1);
	cbytes += ft_strlcpy(&ptr[cbytes - 1], FLAG_NOT_SUPPORT_2, lfns2);
	return (-1);
}

int	handle_recursive_flag(int a)
{
	return (a);
}


int	handle_a_flag(int a)
{
	return (a);
}

int	handle_l_flag(int a)
{
	return (a);
}

int	handle_r_flag(int a)
{
	return (a);
}

int	handle_t_flag(int a)
{
	return (a);
}

typedef int (*f) (int);

int	execute(t_ls *ls, char **emessage)
{
	char	flag;
	int		i, counter;
	char	flags[MAX_COUNT_FLAGS_PER_COMMAND] = { 'R', 'a', 'l', 'r', 't' };
	f		func[5] = { &handle_recursive_flag, &handle_a_flag, &handle_l_flag, &handle_r_flag, &handle_t_flag };

	i = 0;
	while (1)
	{
		flag = ls->flags[i];

		counter = 0;
		while (counter < MAX_COUNT_FLAGS_PER_COMMAND)
		{
			if (flags[counter] == ls->flags[i])
			{
				printf("flag - %c, result %d", flag, func[counter](counter));
			}
			counter++;
		}
		if (counter == MAX_COUNT_FLAGS_PER_COMMAND)
			return flag_not_support(emessage, flag);
		i++;
		if (i >= MAX_COUNT_FLAGS_PER_COMMAND)
			break ;
	}
	return (0);
}

