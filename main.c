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

typedef struct s_ls
{
	char 	*program_name;
	int		*flags;
	char	**folders;
} t_ls;

//t_ls newls()
//{
//	t_ls ls;
//
//	ls.program_name = "ft_ls";
//	ls.flags = NULL;
//	ls.folders = NULL;
//	return (ls);
//}

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

t_list	*copy_to_list(char **argv)
{
	t_list	*list;
	int 	i;

	list = ft_lstnew(argv[0]);
	i = 1;
	while (argv[i])
		ft_lstadd_back(&list, ft_lstnew(argv[i++]));
	return (list);
}

int main(int argc, char **argv)
{
	t_list	*arguments;

	argc = 0;

	arguments = copy_to_list(argv);

    return (0);
}