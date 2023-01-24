#include "headers/srcs.h"
#include "headers/utils.h"
#include "headers/ls.h"

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

	if (argc == 1)
	{
		write(CSTDOUT, "\n", 1);
		return (0);
	}
	err = 0;
	err = init_ls(&ls);
	if (!err)
		return err_printer_and_cleaner(&ls, "Error: create ls struct");
	err = parse(&ls, argv);
	if (!err)
		return err_printer_and_cleaner(&ls, "Error: parse input data");
	err = execute(&ls, &emessage);
	if (!err)
		return err_printer_and_cleaner(&ls, emessage);
	clear_ls(&ls);
    return (0);
}
