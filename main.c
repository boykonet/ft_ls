#include "ls.h"

/*
** -a      Include directory entries whose names begin with a dot (.).
** -l      (The lowercase letter ``ell''.)  List in long format.  (See below.)  If the output is to a terminal, a total sum for all the file sizes
**         is output on a line before the long listing.
** -R      Recursively list subdirectories encountered.
** -r      Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest files last, if combined with
**         sort by size
** -t      Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.
*/

int main(int argc, char **argv)
{
	t_ls	ls;
	int		err;
	char	*emessage;

	err = init_ls(&ls);
	write(1, "init\n", 5);
	if (!err)
		return err_printer_and_cleaner(&ls, "ls: error create ls struct");
	err = parse(&ls, argc, argv);
	write(1, "parse\n", 6);
	if (!err)
		return err_printer_and_cleaner(&ls, "ls: error parse input data");
	err = execute(&ls, &emessage);
	if (!err)
		return err_printer_and_cleaner(&ls, emessage);
	clear_ls(&ls);
    return (0);
}
