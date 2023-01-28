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


/*
** reserved codes:
** -1 - malloc error
**  0 - OK
**  33...126 - flag not supported
*/
int main(/*int argc, char **argv*/)
{
	t_ls	ls;
	int		err;
//	int		exitcode;

//	exitcode = 0;
	err = init_ls(&ls);
	printf("%s\n", ls.sflags);
	ls.func[0](1);
	ls.func[1](1);
	ls.func[2](1);
	ls.func[3](1);
	ls.func[4](1);
//	err = 0;
////	write(1, "init\n", 5);
//	err_printer_and_cleaner(&ls, err, 1);
//	err = parse(&ls, argc, argv);
////	write(1, "parse\n", 6);
//	err_printer_and_cleaner(&ls, err, 1);
//	err = execute(&ls);
//	err_printer_and_cleaner(&ls, err, exitcode);
	return (0);
}
