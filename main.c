#include "ls.h"

/*
** -a      Include directory entries whose names begin with a dot (.).
** -l      (The lowercase letter ``ell''.)  List in long format.  (See below.)  If the output is to a terminal, a total sum for all the file sizes
**         is output on a line before the long listing.
** -R      Recursively list subdirectories encountered.
** -r      Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest dirs last, if combined with
**         sort by size
** -t      Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.
*/

int main(int argc, char **argv)
{
	t_ls	ls;
	int 	ecode;

	(void)argc;
	initialization(&ls);
	parsing(&ls, argv + 1);
	execution(&ls);
	ecode = ls.global_ecode;
	clear_ls(&ls);
	return (ecode);
}
