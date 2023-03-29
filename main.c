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

void	sort_by_flags(t_fileinfo **files, unsigned char flags)
{
	if (is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 0)
	{
		sort_fileinfo(&files, order_cmp_by_filename, FLAG_INVERTED_NO);
	}
	else if (is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 1)
	{
		sort_fileinfo(&files, order_cmp_by_filename, FLAG_INVERTED_YES);
	}

	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 1 \
		&& is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 0)
	{
		sort_fileinfo(&files, order_cmp_by_tlastmod, FLAG_INVERTED_NO);
	}
	else if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 1 \
		&& is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 1)
	{
		sort_fileinfo(&files, order_cmp_by_tlastmod, FLAG_INVERTED_YES);
	}
}

int main(int argc, char **argv)
{
	t_ls	ls;

	(void)argc;
	initialization(&ls);
	parsing(&ls, argv + 1);
	execution(&ls);
	cleaner(&ls, 0);
	return (0);
}



//f1r5s15% ./ft_ls -tl ex
//
//total 8
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:40 tw
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:40 el
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:40 ten
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 nine
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 eight
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 seven
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 six
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 five
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 first
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 second		(2) (115)
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 third		(3) (116)
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 fouth		(1) (102)
//srwxr-xr-x  1 gkarina  piscine    0 Feb  3 23:52 socket.sock
//prw-r--r--  1 gkarina  piscine    0 Feb  3 23:51 myfifo
//drwxr-xr-x  7 gkarina  piscine  238 Feb  3 22:57 dir1
//drwxr-xr-x  2 gkarina  piscine   68 Feb  3 22:57 dir2
//lrwxr-xr-x  1 gkarina  piscine    4 Jan 31 22:42 link -> file
//-rw-r--r--  1 gkarina  piscine    0 Jan 31 22:42 file
//f1r5s15% ls -tl ex
//total 8
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:40 tw
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:40 el
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:40 ten
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 nine
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 eight
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 seven
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 six
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 five
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 first
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 fouth		1 (102)
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 second		2 (115)
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 third		3 (116)
//srwxr-xr-x  1 gkarina  piscine    0 Feb  3 23:52 socket.sock
//prw-r--r--  1 gkarina  piscine    0 Feb  3 23:51 myfifo
//drwxr-xr-x  7 gkarina  piscine  238 Feb  3 22:57 dir1
//drwxr-xr-x  2 gkarina  piscine   68 Feb  3 22:57 dir2
//lrwxr-xr-x  1 gkarina  piscine    4 Jan 31 22:42 link -> file
//-rw-r--r--  1 gkarina  piscine    0 Jan 31 22:42 file

