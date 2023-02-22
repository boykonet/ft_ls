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


void	initialization(t_ls *ls)
{
	init_ls(ls);
}


int		add_value_to_2array(char ***data, const char *value)
{
	char	**p;
	char	**res;
	size_t	size;

	if (!data)
		return (-2);
	p = *data;
	size = len_2_pointer_array((const void**)p);
	res = (char**)calloca_to_2d(size + 1 + 1);
	if (!res)
		return (-1);
	size_t	i = 0;
	while (p)
	{
		res[i] = *p;
		p++;
		i++;
	}
	res[i] = ft_strdup(value);
	if (!res[i])
	{
		free(res);
		return (-1);
	}
	free_2_pointer_array((void**)*data);
	*data = res;
	return (0);
}

int		sort_filenames(char **filenames, char ***files, char ***dirs)
{
	char	**p;
	int		err;

	if (!files || !dirs || !filenames)
		return (-2);
	p = filenames;
	while (p)
	{
		err = if_dir_or_file(*p);
		if (err == 0) // directory
		{
			if (add_value_to_2array(dirs, *p) == -1)
				return (-1);
		}
		else if (err == 1) // file
		{
			if (add_value_to_2array(files, *p) == -1)
				return (-1);
		}
		else // some unexpected error
			return (-1);
		p++;
	}
	return (0);
}

// sww - something went wrong
// amessage - additional message
int		sww(t_err *err, char *amessage)
{
	ft_memcpy(err->message, SWW, ft_strlen(SWW));
	err->exitcode = 1;
	int errcode = add_pattern(&err->patterns, "{{message}}", amessage);
	if (errcode != 0)
	{
		clear_err(err);
		return (-1);
	}
	return (0);
}

int		handle_error_codes(int errcode, t_err *err)
{
	if (!errcode)
		return (0);
	else if (errcode == -1)
	{
		if (sww(err, MALLOC_ERROR) == -1)
			return (-1);
	}
	else if (errcode == -2)
	{
		if (sww(err, NULL_PARAMETER) == -1)
			return (-1);
	}
	return (0);
}

int		separate_filenames(char **filenames, char ***files, char ***dirs, t_err *err)
{
	int errcode = sort_filenames(filenames, files, dirs);
	return (handle_error_codes(errcode, err));
}

void	parsing(t_ls *ls, char **data)
{
	data += 1;
	ls->flags = parse_flags(&data, &ls->err);
	if (!ls->flags)
		print_error_message_and_exit(ls);
	ls->filenames = parse_filenames(&data, &ls->err);
	if (!ls->filenames)
		print_error_message_and_exit(ls);
	int errcode = sort_filenames(ls->filenames, &ls->files, &ls->dirs);
	if (errcode != 0)
		handle_error_codes(errcode, &ls->err);

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

	(void)argc;
	initialization(&ls);
	write(1, "init\n", 5);

	parsing(&ls, argv);
	write(1, "parse\n", 6);

	lexicography_sort(&ls.dirs);
	int i = 0;
	while (ls.dirs[i])
	{
		printf("filename [%s]\n", ls.dirs[i]);
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
//	while (ls.dirs[i] != NULL) {
//		printf("HEY AGAIN\n");
//		printf("folder [-%s]\n", ls.dirs[i]);
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




