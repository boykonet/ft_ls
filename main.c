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


void	initialization(t_ls *ls)
{
	init_ls(ls);
}

void	parsing(t_ls *ls, int argc, char **argv)
{
	if (parse(ls, argc, argv) == -1)
		print_error_message_and_exit(ls);
}

void	execution(t_ls *ls)
{
	execute(ls);
}

/*
** reserved codes:
** -1 - malloc error
**  0 - OK
**  32...126 - flag not supported
*/
int main(int argc, char **argv)
{
	t_ls	ls;

	initialization(&ls);
	write(1, "init\n", 5);

	parsing(&ls, argc, argv);
	write(1, "parse\n", 6);

	lexicography_sort(&ls.files);
	int i = 0;
	while (ls.files[i])
	{
		printf("filename [%s]\n", ls.files[i]);
		i++;
	}
//	err = execute(&ls);
//	write(1, "execute\n", 8);
//	err_printer_and_cleaner(&ls, err, exitcode);
	return (0);
}

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
//	while (ls.files[i] != NULL) {
//		printf("HEY AGAIN\n");
//		printf("folder [-%s]\n", ls.files[i]);
//		i++;
//	}
// -----------------------

// // test dir function
//int main(int argc, char **argv)
//{
//	t_list *l, *d;
//	size_t count_elements;
//	char **elems;
//
//	if (argc <= 1)
//	{
//		printf("NOT ARGUMENT STUPID\n");
//		return (0);
//	}
//
//	printf("argument [%s]\n", argv[1]);
//	l = dir(argv[1]);
//
//	count_elements = ft_lstsize(l);
//
//	elems = (char**)calloca_to_2d(count_elements);
//	if (elems == NULL)
//	{
//		printf("MALLOC ERROR");
//		return (-1);
//	}
//
//	char *dirpath = ft_strjoin(argv[1], "/");
//
//	size_t i = 0;
//	while (l != NULL)
//	{
//		char *fname = ((struct dirent*)(l->content))->d_name;
//		if (ft_memcmp(fname, ".", ft_strlen(fname)) == 0
//		|| ft_memcmp(fname, "..", ft_strlen(fname)) == 0)
//		{
//			l = l->next;
//			continue ;
//		}
//		elems[i] = ft_strjoin(dirpath, fname);
//		if (elems[i] == NULL)
//		{
//			free_double_char_array(elems);
//			printf("MALLOC ERROR");
//			return (-1);
//		}
//		printf("name [%s]\n", fname);
//		l = l->next;
//		i++;
//	}
//
//	free(dirpath);
//
//	d = clstat(elems);
//	if (d == NULL)
//		return (1);
//	return (0);
//
////	// group and user name
////	while (d != NULL)
////	{
////		gid_t gid = ((struct stat*)(d->content))->st_gid;
////		uid_t uid = ((struct stat*)(d->content))->st_uid;
////
////		char *group_name = get_group(gid);
////		char *user_name = get_user(uid);
////
////		printf("group [%s]\n", group_name);
////		printf("user [%s]\n", user_name);
////
////		printf("gid [%u]\n", gid);
////		d = d->next;
////	}
//}

//int main(int argc, char **argv)
//{
//	if (argc <= 1)
//	{
//		printf("NO ARGUMENT STUPID\n");
//		return (1);
//	}
//
//	ssize_t buflen, keylen, vallen;
//	char	*buf, *key, *val;
//
//	buflen = listxattr(argv[1], NULL, 0, 0);
//	if (buflen == -1)
//	{
//		perror("listxattr");
//		return (1);
//	}
//	if (buflen == 0)
//	{
//		printf("[%s] has no attributes\n", argv[1]);
//		return (0);
//	}
//
//	buf = ft_calloc(buflen, sizeof(char));
//	if (buf == NULL)
//	{
//		perror("malloc");
//		return (1);
//	}
//
//	buflen = listxattr(argv[1], buf, buflen, 0);
//	if (buflen == -1)
//	{
//		perror("listxattr");
//		return (1);
//	}
//
//	key = buf;
//
//	while (buflen > 0)
//	{
//		printf("attribute key [%s]\n", key);
//
//		vallen = getxattr(argv[1], key, NULL, 0, 0, 0);
//		if (vallen == -1)
//		{
//			perror("getxattr");
//			return (1);
//		}
//
//		if (vallen > 0)
//		{
//			val = ft_calloc(vallen + 1, sizeof(char));
//			if (val == NULL)
//			{
//				perror("malloc");
//				return (1);
//			}
//			vallen = getxattr(argv[1], key, val, vallen, 0, 0);
//			if (vallen == -1)
//			{
//				perror("getxattr");
//			}
//			else
//			{
//				val[vallen] = 0;
//				printf("attribute value [%s]\n", val);
//			}
//			free(val);
//		}
//		else if (vallen == 0)
//		{
//			printf("<no value>");
//		}
//
//		printf("\n");
//
//		keylen = ft_strlen(key) + 1;
//		buflen -= keylen;
//		key += keylen;
//	}
//	free(buf);
//	return (0);
//}


//int main(int argc, char **argv)
//{
//	if (argc <= 0)
//	{
//		printf("NOT ARGUMENT STUPID\n");
//		return (1);
//	}
//
//	char *filename = creadlink(argv[1]);
//	printf("readlink returned [%s] for [%s]\n", filename, argv[1]);
//
////	if (readlink(argv[1], buf, sizeof(buf)) < 0)
////	{
////		perror("readlink");
////		return (1);
////	}
////	else
////	{
////		printf("readlink returned [%s] for [%s]\n", buf, argv[1]);
////	}
//	return (0);
//}

//int main()
//{
//	t_list *l;
//
//	char *err = dir(&l, ".");
//	if (*err != '\0')
//		printf("ERROR [%s]\n", err);
//
//	while (l)
//	{
//		printf("{%s}\n", ((struct dirent*)(l->content))->d_name);
//		l = l->next;
//	}
//}


//int main(int argc, char **argv, char **env)
//{
//	if (argc > 1 || len_double_char_array(argv) > 1)
//		return (1);
//	char *s = find_env(env, "PWD");
//	printf("[%s]\n", s);
//	free(s);
//}




