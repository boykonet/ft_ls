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
**  32...126 - flag not supported
*/
//int main(int argc, char **argv)
//{
//	t_ls	ls;
//	int		err;
//	int		exitcode;
//
//	exitcode = 0;
//	err = init_ls(&ls);
//	write(1, "init\n", 5);
//	err_printer_and_cleaner(&ls, err, 1);
//	err = parse(&ls, argc, argv);
//	write(1, "parse\n", 6);
////	err_printer_and_cleaner(&ls, err, 1);
////	err = execute(&ls);
////	write(1, "execute\n", 8);
////	err_printer_and_cleaner(&ls, err, exitcode);
//	return (0);
//}

// -----------------------
//	printf("flag [- %c]\n", ls.flags[0]);
//	printf("len flags %zu\n", ft_strlen(ls.flags));

//	int i = 0;
//	while (ls.flags[i] != '\0') {
//		printf("HEY\n");
//		printf("flag [-%c]\n", ls.flags[i]);
//		i++;
//	}
//	i = 0;
//	while (ls.folders[i] != NULL) {
//		printf("HEY AGAIN\n");
//		printf("folder [-%s]\n", ls.folders[i]);
//		i++;
//	}
// -----------------------


 // test dir function
int main(int argc, char **argv)
{
	t_list *l, *d;
	size_t count_elements;
	char **elems;

	if (argc <= 1)
	{
		printf("NOT ARGUMENT STUPID\n");
		return (0);
	}

	printf("argument [%s]\n", argv[1]);
	l = dir(argv[1]);

	count_elements = ft_lstsize(l);

	elems = (char**)calloca_to_2d(count_elements);
	if (elems == NULL)
	{
		printf("MALLOC ERROR");
		return (-1);
	}

	char *dirpath = ft_strjoin(argv[1], "/");

	size_t i = 0;
	while (l != NULL)
	{
		char *fname = ((struct dirent*)(l->content))->d_name;
		if (ft_memcmp(fname, ".", ft_strlen(fname)) == 0
		|| ft_memcmp(fname, "..", ft_strlen(fname)) == 0)
		{
			l = l->next;
			continue ;
		}
		elems[i] = ft_strjoin(dirpath, fname);
//		printf("ELEMS[i] = [%s]\n", elems[i]);
//		printf("len elems [%d]\n", len_double_char_array(elems));
		if (elems[i] == NULL)
		{
			free_double_char_array(elems);
			printf("MALLOC ERROR");
			return (-1);
		}
		printf("name [%s]\n", fname);
		l = l->next;
		i++;
	}

	free(dirpath);

	printf("LEN DFILE [%D]\n", len_double_char_array(elems));

	d = clstat(elems);
	if (d == NULL)
		return (1);

	while (d != NULL)
	{
		gid_t gid = ((struct stat*)(d->content))->st_gid;
		uid_t uid = ((struct stat*)(d->content))->st_uid;

		struct group *grp;

		if ((grp = getgrgid(gid)) != NULL)
		{
			printf("[%8.8s]\n", grp->gr_name);
		}

		struct passwd *pwd;

		if ((pwd = getpwuid(uid)) != NULL)
		{
			printf("[%-8.8s]\n", pwd->pw_name);
		}

		printf("gid [%u]\n", gid);
		d = d->next;
	}

	return (0);
}


