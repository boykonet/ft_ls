//#include "ls.h"
//
///*
//** -a      Include directory entries whose names begin with a dot (.).
//** -l      (The lowercase letter ``ell''.)  List in long format.  (See below.)  If the output is to a terminal, a total sum for all the file sizes
//**         is output on a line before the long listing.
//** -R      Recursively list subdirectories encountered.
//** -r      Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest dirs last, if combined with
//**         sort by size
//** -t      Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.
//*/
//
//
//void	initialization(t_ls *ls)
//{
//	init_ls(ls);
//}
//
//int		separate_filenames(char **filenames, char ***files, char ***dirs)
//{
//	int		errcode;
//	size_t	len, i;
//
//	if (!files || !dirs || !filenames)
//		return (-2);
//	len = len_2array((const void**)filenames);
////	printf("LEN [%zu]\n", len);
//	i = 0;
//	while (i < len)
//	{
////		printf("*p [%s]\n", filenames[i]);
//		errcode = if_dir_or_file(filenames[i]);
////		printf("AFTER DIR [%zu], errcode [%d]\n", i, errcode);
//		if (errcode == 0) // directory
//		{
////			printf("errcode before errcode == 0 [%d]\n", errcode);
////			for (int j = 0; j < len_2array((const void **) *dirs); j++)
////				printf("dirs[%d] = %s\n", j, *dirs[j]);
//			errcode = add_value_2array(dirs, filenames[i]);
////			printf("errcode after errcode == 0 [%d]\n", errcode);
//			if (errcode != 0)
//				return (errcode);
//		}
//		else if (errcode == 1) // files
//		{
//			errcode = add_value_2array(files, filenames[i]);
//			if (errcode != 0)
//				return (errcode);
//		}
//		else if (errcode == -1 || errcode == -2) // some unexpected error
//			return (errcode);
////		printf("counter [%zu]\n", i);
//		i++;
//	}
////	printf("end\n");
//	return (0);
//}
//
//void	parsing(t_ls *ls, char **data)
//{
//	char	**filenames;
//	int		errcode;
//
//	data += 1;
//	errcode = parse_flags(&data, (char**)&ls->flags, &ls->epatterns);
////	printf("first\n");
//	handle_error(errcode, ls->epatterns);
//	errcode = parse_filenames(data, &filenames);
////	printf("second\n");
//	handle_error(errcode, ls->epatterns);
//	errcode = separate_filenames(filenames, &ls->files, &ls->dirs);
////	printf("third\n");
//	free_2array((void**)filenames);
//	handle_error(errcode, ls->epatterns);
//}
//
//void	execution(t_ls *ls)
//{
//	execute_files(ls->files, ls->flags, &ls->epatterns);
//	execute_dirs(ls->dirs, ls->flags, &ls->epatterns);
//}
//
//
///*
//** reserved codes:
//** -1 - malloc error
//**  0 - OK
//**  32...126 - flag not supported
//*/
//int main(int argc, char **argv)
//{
//	t_ls	ls;
//
//	(void)argc;
//	initialization(&ls);
//	write(1, "init\n", 5);
//
//	parsing(&ls, argv);
//	write(1, "parse\n", 6);
//
//	int i = 0;
//
////	printf("len dirs [%d], len files [%d]\n", len_2array((const void **) ls.dirs), len_2array(
////			(const void **) ls.files));
////	while (ls.dirs && ls.dirs[i])
////	{
////		printf("dirs[%d] =  [%s]\n", i, ls.dirs[i]);
////		i++;
////	}
////	i = 0;
////	while (ls.files && ls.files[i])
////	{
////		printf("files[%d] = [%s]\n", i, ls.files[i]);
////		i++;
////	}
//
//	lexicography_sort(&ls.dirs);
//	lexicography_sort(&ls.files);
//
//	i = 0;
//	while (ls.dirs && ls.dirs[i])
//	{
//		printf("dirs[%d] =  [%s]\n", i, ls.dirs[i]);
//		i++;
//	}
//	i = 0;
//	while (ls.files && ls.files[i])
//	{
//		printf("files[%d] = [%s]\n", i, ls.files[i]);
//		i++;
//	}
////	err = execute(&ls);
////	write(1, "execute\n", 8);
////	err_printer_and_cleaner(&ls, err, exitcode);
//	return (0);
//}
//
//// -----------------------
////	printf("flag [- %c]\n", ls.flags[0]);
////	printf("len flags %zu\n", ft_strlen(ls.flags));
//
////	int i = 0;
////	while (ls.flags[i] != '\0') {
////		printf("HEY\n");
////		printf("flag [-%c]\n", ls.flags[i]);
////		i++;
////	}
////	i = 0;
////	while (ls.dirs[i] != NULL) {
////		printf("HEY AGAIN\n");
////		printf("folder [-%s]\n", ls.dirs[i]);
////		i++;
////	}
//// -----------------------
//
//// // test dir function
////int main(int argc, char **argv)
////{
////	t_list *l, *d;
////	size_t count_elements;
////	char **elems;
////
////	if (argc <= 1)
////	{
////		printf("NOT ARGUMENT STUPID\n");
////		return (0);
////	}
////
////	printf("argument [%s]\n", argv[1]);
////	l = dir(argv[1]);
////
////	count_elements = ft_lstsize(l);
////
////	elems = (char**)calloca_to_2d(count_elements);
////	if (elems == NULL)
////	{
////		printf("MALLOC ERROR");
////		return (-1);
////	}
////
////	char *dirpath = ft_strjoin(argv[1], "/");
////
////	size_t i = 0;
////	while (l != NULL)
////	{
////		char *fname = ((struct dirent*)(l->content))->d_name;
////		if (ft_memcmp(fname, ".", ft_strlen(fname)) == 0
////		|| ft_memcmp(fname, "..", ft_strlen(fname)) == 0)
////		{
////			l = l->next;
////			continue ;
////		}
////		elems[i] = ft_strjoin(dirpath, fname);
////		if (elems[i] == NULL)
////		{
////			free_double_char_array(elems);
////			printf("MALLOC ERROR");
////			return (-1);
////		}
////		printf("name [%s]\n", fname);
////		l = l->next;
////		i++;
////	}
////
////	free(dirpath);
////
////	d = clstat(elems);
////	if (d == NULL)
////		return (1);
////	return (0);
////
//////	// group and user name
//////	while (d != NULL)
//////	{
//////		gid_t gid = ((struct stat*)(d->content))->st_gid;
//////		uid_t uid = ((struct stat*)(d->content))->st_uid;
//////
//////		char *group_name = get_group(gid);
//////		char *user_name = get_user(uid);
//////
//////		printf("group [%s]\n", group_name);
//////		printf("user [%s]\n", user_name);
//////
//////		printf("gid [%u]\n", gid);
//////		d = d->next;
//////	}
////}
//
////int main(int argc, char **argv)
////{
////	if (argc <= 1)
////	{
////		printf("NO ARGUMENT STUPID\n");
////		return (1);
////	}
////
////	ssize_t buflen, keylen, vallen;
////	char	*buf, *key, *val;
////
////	buflen = listxattr(argv[1], NULL, 0, 0);
////	if (buflen == -1)
////	{
////		perror("listxattr");
////		return (1);
////	}
////	if (buflen == 0)
////	{
////		printf("[%s] has no attributes\n", argv[1]);
////		return (0);
////	}
////
////	buf = ft_calloc(buflen, sizeof(char));
////	if (buf == NULL)
////	{
////		perror("malloc");
////		return (1);
////	}
////
////	buflen = listxattr(argv[1], buf, buflen, 0);
////	if (buflen == -1)
////	{
////		perror("listxattr");
////		return (1);
////	}
////
////	key = buf;
////
////	while (buflen > 0)
////	{
////		printf("attribute key [%s]\n", key);
////
////		vallen = getxattr(argv[1], key, NULL, 0, 0, 0);
////		if (vallen == -1)
////		{
////			perror("getxattr");
////			return (1);
////		}
////
////		if (vallen > 0)
////		{
////			val = ft_calloc(vallen + 1, sizeof(char));
////			if (val == NULL)
////			{
////				perror("malloc");
////				return (1);
////			}
////			vallen = getxattr(argv[1], key, val, vallen, 0, 0);
////			if (vallen == -1)
////			{
////				perror("getxattr");
////			}
////			else
////			{
////				val[vallen] = 0;
////				printf("attribute value [%s]\n", val);
////			}
////			free(val);
////		}
////		else if (vallen == 0)
////		{
////			printf("<no value>");
////		}
////
////		printf("\n");
////
////		keylen = ft_strlen(key) + 1;
////		buflen -= keylen;
////		key += keylen;
////	}
////	free(buf);
////	return (0);
////}
//
//
////int main(int argc, char **argv)
////{
////	if (argc <= 0)
////	{
////		printf("NOT ARGUMENT STUPID\n");
////		return (1);
////	}
////
////	char *filename = creadlink(argv[1]);
////	printf("readlink returned [%s] for [%s]\n", filename, argv[1]);
////
//////	if (readlink(argv[1], buf, sizeof(buf)) < 0)
//////	{
//////		perror("readlink");
//////		return (1);
//////	}
//////	else
//////	{
//////		printf("readlink returned [%s] for [%s]\n", buf, argv[1]);
//////	}
////	return (0);
////}
//
////int main()
////{
////	t_list *l;
////
////	char *err = dir(&l, ".");
////	if (*err != '\0')
////		printf("ERROR [%s]\n", err);
////
////	while (l)
////	{
////		printf("{%s}\n", ((struct dirent*)(l->content))->d_name);
////		l = l->next;
////	}
////}
//
//
////int main(int argc, char **argv, char **env)
////{
////	if (argc > 1 || len_double_char_array(argv) > 1)
////		return (1);
////	char *s = find_env(env, "PWD");
////	printf("[%s]\n", s);
////	free(s);
////}
//
//
//
//





// ---------------------------------------------------


#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/errno.h>
#include "ls.h"


// собираешь в одно место
// сортируешь в соответсвии с теми флагами, которые пришли
// выводишь на экран
// пробегаешься еще раз по всем файлам, находишь директорию, рекурсивно вызываешь свою функцию




//void	list_files(const char *dirname)
//{
//	struct dirent	*pointers[100];
//	size_t			max_len;
//
//	bzero(pointers, sizeof(struct dirent*) * 100);
//	DIR *dir = opendir(dirname);
//	if (dir == NULL)
//	{
//		printf("dir is NULL - dirname [%s]\n", dirname);
//		return ;
//	}
//
//	struct dirent *entity;
//
//	max_len = 0;
//	int i = 0;
//	while ((entity = readdir(dir)) != NULL)
//	{
//		pointers[i++] = entity;
//		size_t	current_len = strlen(entity->d_name);
//		if (max_len < current_len)
//			max_len = current_len;
//	}
//	if (entity == NULL && errno != 0)
//	{
//		printf("entity is NULL, errno [%s]\n", strerror(errno));
//		exit(1);
//	}
//	closedir(dir);
//	i = 0;
//	printf("%s:\n", dirname);
//	printf("    ");
//	while (pointers[i])
//	{
//		printf("%s", pointers[i]->d_name);
//		printf("    ");
//		i++;
//	}
//	printf("\n");
//
//	i = 0;
//	while (pointers[i])
//	{
//		if (pointers[i]->d_type == DT_DIR && strcmp(pointers[i]->d_name, ".") != 0 && strcmp(pointers[i]->d_name, "..") != 0)
//		{
//			char path[200] = {0};
//			bzero(path, sizeof(char) * 200);
//			strcat(path, dirname);
//			strcat(path, "/");
//			strcat(path, pointers[i]->d_name);
//			if (strcmp(path, "../ex/dir4") == 0)
//			{
//				printf("dirname [%s] d_name [%s] path [%s]\n\n", dirname, pointers[i]->d_name, path);
//				int j = 0;
//				while (pointers[j])
//				{
//					printf("pointers[%d] = %s\n", j, pointers[j]->d_name);
//					j++;
//				}
//			}
//			list_files(path);
////			printf("\n");
//		}
//		i++;
//	}
//}

static void	bubble(void **first, void **second)
{
	void *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}


// file mode
// number of links
// owner name
// group name
// number of bytes in the file
// abbreviated month
// day-of-month file was last modified, hour file last modified, minute file last modified
// and the pathname
typedef struct s_iresource
{
	int		filetype;
	char	*name;
//	char	*link;
//	char	*username;
//	char	*groupname;
//	int 	size;
} t_iresource;

typedef struct s_fileinfo
{
	char		name[255 + 1];
	int			type;
	char		filemode[11 + 1];
	char		nlinks[5 + 1]; // because nlinks_t type is cast for unsigned short, maximum value is 65535
	char		oname[255 + 1]; // owner name
	char		gname[255 + 1]; // group name
	long long	nbytes; // number of bytes
	char		amonth[3 + 1]; // abbreviated month ---> Jan
	char		day_lm[2 + 1]; // day last modified ---> 31
	char		time_lm[5 + 1]; // time last modified ---> 12:23
	char		link[255 + 1]; // only if type == DT_LNK
} t_fileinfo;

t_fileinfo	*new_fileinfo(char *name, int type)
{
	t_fileinfo *f;

	f = ft_calloc(1, sizeof(t_fileinfo));
	if (!f)
		return (NULL);
	ft_memcpy(f->name, name, ft_strlen(name));
	f->type = type;
	ft_memcpy(f->filemode, "---------- ", 11);
	return (f);
}

void	alphabetical_sort_files(t_fileinfo ***array)
{
	t_fileinfo	**p;
	size_t		i, j, len;

	if (!array)
		return ;
	p = *array;
	len = len_2array((const void**)p);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (strcmp(p[i]->name, p[j]->name) > 0)
				bubble((void**)&p[i], (void**)&p[j]);
			j++;
		}
		i++;
	}
}

char	**copy_dirs(t_fileinfo **files)
{
	char	**dirs;
	size_t	i, j, count;

	if (!files)
		return (ft_calloc(0, sizeof(char*)));
	count = 0;
	i = 0;
	while (files[i])
	{
		if (files[i]->type == 4)
			count++;
		i++;
	}

	dirs = (char**)ft_calloc(count + 1, sizeof(char*));
	if (!dirs)
		return (NULL);
	i = 0;
	j = 0;
	while (files[i])
	{
		if (files[i]->type == 4)
		{
			dirs[j] = ft_strdup(files[i]->name);
			if (!dirs[j])
			{
				free_2array((void**)dirs);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (dirs);
}

char	*join_file(t_fileinfo *finfo)
{
	char	*res;

	res = ft_strjoin("", finfo->filemode);
	res = ft_strjoin(res, " ");
	res = ft_strjoin(res, finfo->nlinks);
	res = ft_strjoin(res, " ");
	res = ft_strjoin(res, finfo->oname);
	res = ft_strjoin(res, "  ");
	res = ft_strjoin(res, finfo->gname);
	res = ft_strjoin(res, "  ");
	res = ft_strjoin(res, ft_itoa(finfo->nbytes));
	res = ft_strjoin(res, " ");
	res = ft_strjoin(res, finfo->amonth);
	res = ft_strjoin(res, " ");
	res = ft_strjoin(res, finfo->day_lm);
	res = ft_strjoin(res, " ");
	res = ft_strjoin(res, finfo->time_lm);
	res = ft_strjoin(res, " ");
	res = ft_strjoin(res, finfo->name);
	if (finfo->type == DT_LNK)
	{
		res = ft_strjoin(res, " -> ");
		res = ft_strjoin(res, finfo->link);
	}
	res = ft_strjoin(res, "\n");

	return (res);
}

void	cstrmode(mode_t mode, char *buf)
{
	const char	permissions[4] = "rwx";
	size_t		i;

	i = 0;
	while (i < 9)
	{
		buf[i] = (mode & (1 << (8 - i))) ? permissions[i % 3] : '-';
		i++;
	}
}

typedef struct s_filetypes
{
	int		filetype;
	char	replacement;
} t_filetypes;

void	set_filetype(char *filetype, int type)
{
	t_filetypes	filetypes[FILETYPES_SIZE] = {
			{.filetype = DT_BLK, .replacement = 'b'},
			{.filetype = DT_CHR, .replacement = 'c'},
			{.filetype = DT_DIR, .replacement = 'd'},
			{.filetype = DT_LNK, .replacement = 'l'},
			{.filetype = DT_SOCK, .replacement = 's'},
			{.filetype = DT_FIFO, .replacement = 'p'},
			{.filetype = DT_REG, .replacement = '-'},
			{.filetype = DT_UNKNOWN, .replacement = '?'}, // TODO: check the information about unknown file
	};

	for (int i = 0; i < FILETYPES_SIZE; i++)
	{
		if (type == filetypes[i].filetype)
		{
			*filetype = filetypes[i].replacement;
			break ;
		}
	}
}


// file mode
// number of links
// owner name
// group name
// number of bytes in the file
// abbreviated month
// day-of-month file was last modified, hour file last modified, minute file last modified
// and the pathname
char	*configure_l_option(t_fileinfo *finfo, long long *total)
{
	struct stat		st;

	if (lstat(finfo->name, &st) == -1)
	{
		perror("ls");
		exit(1);
	}

	*total += st.st_blocks;

	char *nlinks = ft_itoa(st.st_nlink);
	ft_memcpy(finfo->nlinks, nlinks, ft_strlen(nlinks));
	free(nlinks);
	nlinks = NULL;

	cstrmode(st.st_mode, &finfo->filemode[1]);

	set_filetype(&finfo->filemode[0], finfo->type);

	finfo->nbytes = st.st_size;

	char	**t = ft_split(ctime((const time_t*)&st.st_mtimespec.tv_sec), ' ');
	if (!t)
	{
		perror("malloc");
		exit(1);
	}
	*ft_strrchr(t[3], ':') = '\0';

	ft_memcpy(finfo->amonth, t[1], 3);
	ft_memcpy(finfo->day_lm, t[2], 2);
	ft_memcpy(finfo->time_lm, t[3], 5);

	ft_memcpy(finfo->oname, get_user(st.st_uid), 255);
	ft_memcpy(finfo->gname, get_group(st.st_gid), 255);

	if (finfo->type == DT_LNK)
		ft_memcpy(finfo->link, creadlink(finfo->name), 255);

	char *res = join_file(finfo);
	free_2array((void**)t);
	t = NULL;
	return (res);
}

void	print_files(t_fileinfo	**files, int flag_a, int flag_l)
{
	size_t		i = 0;
	char		*res;
	long long	total;

	res = ft_strdup("");
	total = 0;
	size_t	lfiles = len_2array((const void**)files);
	while(files[i])
	{
		if (flag_a == 0 && strncmp(files[i]->name, ".", 1) == 0)
		{
			i++;
			continue ;
		}
		char	*message, *p = NULL;
		if (flag_l == 1)
			message = configure_l_option(files[i], &total);
		else
		{
			if (i == lfiles - 1)
				message = ft_strjoin(files[i]->name, "\n");
			else
				message = ft_strjoin(files[i]->name, "    ");
		}
		p = res;
		res = ft_strjoin(res, message);
		free(p);
		p = NULL;
		free(message);
		message = NULL;
		i++;
	}
	if (flag_l == 1)
		printf("total %lld\n", total);
	if (res != NULL)
		write(1, res, ft_strlen(res));
	free(res);
	res = NULL;
}

void rec_dirs(char *path, int flag_r, int flag_a, int flag_l, int counter)
{
	DIR				*dir;
	t_fileinfo 		**files;
	struct dirent	*ep;
	char			newdir[512];

	dir = opendir(path);
	if(!dir)
	{
		perror("ls");
		exit(1);
	}
	files = (t_fileinfo**)ft_calloc(1, sizeof(t_fileinfo*));
	if (!files)
	{
		perror("ls");
		exit(1);
	}
	while ((ep = readdir(dir)))
	{
		t_fileinfo *fi = new_fileinfo(ep->d_name, ep->d_type);
		if (fi == NULL)
		{
			perror("ls");
			exit(1);
		}
		size_t flen = len_2array((const void**)files);
		if (realloc_2array((void***)&files, flen + 1) != 0)
		{
			perror("ls");
			exit(1);
		}
		flen = len_2array((const void**)files);
		files[flen] = fi;
	}
	if (ep == NULL && errno)
	{
		// TODO: handle error
		// ls: ../ex/dir4: No such file or directory
		perror("ls");
		exit(1);
	}
	if (closedir(dir) == -1)
	{
		perror("ls");
		exit(1);
	}

	if (counter > 0)
		printf("%s:\n", path);

	alphabetical_sort_files(&files);
	char	**dirs = copy_dirs(files);

	print_files(files, flag_a, flag_l);

	size_t i;
	if (flag_r)
	{
		i = 0;
		while (dirs[i])
		{
			if (flag_a == 0 && ft_strncmp(dirs[i], ".", 1) == 0)
			{
				i++;
				continue ;
			}
			size_t	ldname = ft_strlen(dirs[i]);
			if (ft_strncmp(dirs[i], ".", ldname > 1 ? ldname : 1) != 0 \
			&& ft_strncmp(dirs[i], "..", ldname > 2 ? ldname : 2) != 0)
			{
				ft_bzero(newdir, sizeof(char) * 512);
				strcat(newdir, path);
				strcat(newdir, "/");
				strcat(newdir, dirs[i]);
				rec_dirs(newdir, flag_r, flag_a, flag_l, counter + 1);
			}
			i++;
		}
	}
	free_2array((void**)dirs);
	free_2array((void**)files);
}

int main()
{
	rec_dirs(".", 0, 0, 1, 0);
	return (0);
}
