#include "srcs.h"
#include "../utils/utils.h"

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

static int	execute_by_flag(char flag, char **emessage)
{
	if (flag == 'R')
	{
		handle_recursive_option();
	}
	else if (flag == 'a')
	{
		handle_a_option();
	}
	else if (flag == 'l')
	{
		handle_l_option();
	}
	else if (flag == 'r')
	{
		handle_r_option();
	}
	else if (flag == 't')
	{
		handle_t_option();
	}
	else
	{
		return flag_not_support(emessage, flag);
	}
}

int	execute(t_ls *ls, char **message)
{
	

	return (0);
}
