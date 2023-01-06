#include "srcs/srcs.h"
#include "utils/utils.h"

/*
** -a      Include directory entries whose names begin with a dot (.).
** -l      (The lowercase letter ``ell''.)  List in long format.  (See below.)  If the output is to a terminal, a total sum for all the file sizes
**         is output on a line before the long listing.
** -R      Recursively list subdirectories encountered.
** -r      Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest files last, if combined with
**         sort by size
** -t      Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.
*/


#define MAX_COUNT_FLAGS_PER_COMMAND 5
#define

typedef struct s_ls
{
	char	*flags;
	char 	**folders;
} t_ls;

int alloc_to(void **ptr, int size);

int	init_ls(t_ls *ls)
{
	if (!alloc_to((void**)&ls->flags, MAX_COUNT_FLAGS_PER_COMMAND))
		return (-1);
	ls->folders = NULL;
	return (0);
}

void	clear_ls(t_ls *ls)
{
	free(ls->flags);
	free_double_array(ls->folders);
}

//void	freels(t_list *ls)
//{
//
//}

//char	**folders(char **argv)
//{
//}

//void logic()
//{
//
//}

void	add_flag(char **flags, char new_flag)
{
	int i;
	char *p;

	i = 0;
	p = ft_strchr(*flags, new_flag);
	if (!p)
		return ;

}

int alloc_to(void **ptr, int size)
{
	*ptr = malloc(size * sizeof(void*));
	if (!*ptr)
		return (-1);
	return (0);
}

int	parse(t_ls *ln, char **argv)
{
	int	counter;

	counter = 1;
	while (argv[counter])
	{
		char	*params;
		int		i;

		i = 0;
		params = argv[counter];
		if (params[i++] == '-')
		{
			while (params[i] != '\0')
				add_flag((char **)&((*ln).flags), params[i++]);
		}
		else
		{
			break ;
		}
	}
	if (!alloc_to((void**)(*ln).folders, len_double_array(&argv[counter])))
	{
		return (-1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_ls ls;
	int	err;

	err = 0;
	err = init_ls(&ls);
	if (!err && argc == 1)
	{
		write(STDOUT, "\n", 1);
		return (0);
	}

	clear_ls(&ls);
    return (err);
}