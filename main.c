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
//
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
////		printf("filename [%s]\n", fname);
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
//////	// group and user filename
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


t_fileinfo	*new_fileinfo(char *path, char *filename, int type)
{
	t_fileinfo *f;

	f = ft_calloc(1, sizeof(t_fileinfo));
	if (!f)
		return (NULL);
	ft_memcpy(f->path, path, ft_strlen(path));
	ft_memcpy(f->filename, filename, ft_strlen(filename));
	f->type = type;
	ft_memcpy(f->filemode, "---------- ", 11);
	return (f);
}

void	set_spaces(char spaces[5][254 + 1], t_fileinfo *finfo, t_spaces maxs)
{
	int		cos[5] = {0}; // count of spaces
	size_t	i;

	cos[0] = maxs.s_link - ft_strlen(finfo->nlinks);
	cos[1] = maxs.s_oname - ft_strlen(finfo->oname);
	cos[2] = maxs.s_gname - ft_strlen(finfo->gname);
	cos[3] = maxs.s_bytes - ft_strlen(finfo->nbytes);
	cos[4] = maxs.s_day - ft_strlen(finfo->day_lm);

	i = 0;
	while (i < 5)
	{
		ft_memset(spaces[i], ' ', cos[i]);
		i++;
	}
}

void	print_fileinfo(t_fileinfo *finfo, t_spaces maxs)
{
	char	spaces[5][254 + 1] = {0};
	char	pattern[1024] = {0};

	set_spaces(spaces, finfo, maxs);

	t_pattern	patterns[16] = {
			{.pattern = "{{filemode}}", .replacement = finfo->filemode},
			{.pattern = "{{s1}}", .replacement = spaces[0]},
			{.pattern = "{{nlinks}}", .replacement = finfo->nlinks},
			{.pattern = "{{s2}}", .replacement = spaces[1]},
			{.pattern = "{{oname}}", .replacement = finfo->oname},
			{.pattern = "{{s3}}", .replacement = spaces[2]},
			{.pattern = "{{gname}}", .replacement = finfo->gname},
			{.pattern = "{{s4}}", .replacement = spaces[3]},
			{.pattern = "{{nbytes}}", .replacement = finfo->nbytes},
			{.pattern = "{{amonth}}", .replacement = finfo->amonth},
			{.pattern = "{{s5}}", .replacement = spaces[4]},
			{.pattern = "{{day}}", .replacement = finfo->day_lm},
			{.pattern = "{{time}}", .replacement = finfo->time_lm},
			{.pattern = "{{filename}}", .replacement = finfo->filename},
			{.pattern = "{{link}}", .replacement = finfo->link},
			NULL,
	};

	if (finfo->type == S_IFLNK)
		replace_pattern(pattern, PATTERN_WITH_LINK, patterns, 15);
	else
		replace_pattern(pattern, PATTERN_WITHOUT_LINK, patterns, 15);

	write(1, pattern, ft_strlen(pattern));
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
	t_filetypes	filetypes[FILETYPES_SIZE + 1] = {
			{.filetype = S_IFBLK, .replacement = 'b'},
			{.filetype = S_IFCHR, .replacement = 'c'},
			{.filetype = S_IFDIR, .replacement = 'd'},
			{.filetype = S_IFLNK, .replacement = 'l'},
			{.filetype = S_IFSOCK, .replacement = 's'},
			{.filetype = S_IFIFO, .replacement = 'p'},
			{.filetype = S_IFREG, .replacement = '-'},
			{.filetype = S_IFWHT, .replacement = '?'}, // TODO: check the information about unknown file
			0,
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

void	conf_filemode(mode_t mode, int filetype, char *filemode)
{
	cstrmode(mode, &filemode[1]);
	set_filetype(&filemode[0], filetype);
}

void	conf_nlink(nlink_t st_nlink, char *links)
{
	char *number_links = ft_itoa(st_nlink);
//	if (!number_links) // TODO: thinking about static variable and recursive number function
//		return (NULL);
	ft_memcpy(links, number_links, ft_strlen(number_links));
	free(number_links);
	number_links = NULL;
}

void	conf_nbytes(off_t st_size, char *bytes)
{
	char	*nbytes = ft_itoa((int)st_size);
	ft_memcpy(bytes, nbytes, ft_strlen(nbytes));
	free(nbytes);
	nbytes = NULL;
}

void	conf_time(struct timespec st_mtimespec, char *amonth, char *day_lm, char *time_lm)
{
	char	**t;

	t = ft_split(ctime((const time_t*)&st_mtimespec.tv_sec), ' ');
	if (!t)
	{
		perror("malloc");
		exit(1);
	}
	*ft_strrchr(t[3], ':') = '\0';

	ft_memcpy(amonth, t[1], ft_strlen(t[1]));
	ft_memcpy(day_lm, t[2], ft_strlen(t[2]));
	ft_memcpy(time_lm, t[3], ft_strlen(t[3]));
	free_2array((void**)t);
	t = NULL;
}

void conf_link(const char *filepath, char *link)
{
	char	*new_link = creadlink(filepath);
	if (!new_link)
	{
		perror("malloc");
		exit(1);
	}
	ft_memcpy(link, new_link, sizeof(link) - 1);
}

void	max_spaces(size_t *first, size_t second)
{
	if (first == NULL)
		return ;
	if (*first < second)
		*first = second;
}

void	get_fileinfo(t_fileinfo *finfo, long long *total)
{
	struct stat		st;
	char			*filepath;
	size_t			flen;

	filepath = NULL;
	flen = ft_strlen(finfo->path) + 1 + ft_strlen(finfo->filename) + 1;
	filepath = ft_calloc(flen, sizeof(char));
	if (!filepath)
	{
		perror("malloc");
		exit(1);
	}
	ft_strlcat(filepath, finfo->path, flen);
	ft_strlcat(filepath, "/", flen);
	ft_strlcat(filepath, finfo->filename, flen);

	if (lstat(filepath, &st) == -1)
	{
		printf("here filepath [%s]\n", filepath);
		perror("ls");
		exit(1);
	}

	if (total)
		*total += st.st_blocks;

	// filetype
	finfo->type = st.st_mode & S_IFMT;

	conf_filemode(st.st_mode, finfo->type, finfo->filemode); // TODO: might be empty value
	conf_nlink(st.st_nlink, finfo->nlinks);

	ft_memcpy(finfo->oname, get_user(st.st_uid), 255);
	ft_memcpy(finfo->gname, get_group(st.st_gid), 255);

	conf_nbytes(st.st_size, finfo->nbytes);

	conf_time(st.st_mtimespec, finfo->amonth, finfo->day_lm, finfo->time_lm);
	finfo->mtime.tv_sec = st.st_mtimespec.tv_sec;
	finfo->mtime.tv_nsec = st.st_mtimespec.tv_nsec;

	if (finfo->type == S_IFLNK)
		conf_link(filepath, finfo->link);

	free(filepath);
	filepath = NULL;
}

void	counter_of_spaces(t_fileinfo **info, t_spaces *spaces)
{
	if (info == NULL || spaces == NULL)
		return ;
	for (size_t i = 0; info[i]; i++)
	{
		max_spaces(&spaces->s_link, ft_strlen(info[i]->nlinks));
		max_spaces(&spaces->s_oname, ft_strlen(info[i]->oname));
		max_spaces(&spaces->s_gname, ft_strlen(info[i]->gname));
		max_spaces(&spaces->s_bytes, ft_strlen(info[i]->nbytes));
		max_spaces(&spaces->s_day, ft_strlen(info[i]->day_lm));
	}
}

void	print_files_from_dirs(t_fileinfo **files, long long total, t_spaces maxs, int flag_l)
{
	size_t	i;

	i = 0;
	if (flag_l == 1 && len_2array((const void**)files) > 0)
		printf("total %lld\n", total);

	while (files[i])
		print_fileinfo(files[i++], maxs);
}

void	print_files_from_files(t_fileinfo **files, t_spaces maxs, int flag_l)
{
	size_t	i;

	i = 0;
	while (files[i])
		print_fileinfo(files[i++], maxs);
}

void	ispaces(t_spaces *spaces)
{
	spaces->s_link = 0;
	spaces->s_oname = 0;
	spaces->s_gname = 0;
	spaces->s_bytes = 0;
	spaces->s_day = 0;
}

void	openreaddir(t_fileinfo ***files, char *dirpath, int flag_a)
{
	DIR				*dir;
	struct dirent	*ep;

	dir = opendir(dirpath);
	if(!dir)
	{
		char *s = ft_strjoin("ls: ", dirpath);
		perror(s);
		free(s);
		s = NULL;
		exit(1);
	}

	*files = (t_fileinfo**)ft_calloc(1, sizeof(t_fileinfo*));
	if (!*files)
	{
		char *s = ft_strjoin("ls: ", dirpath);
		perror(s);
		free(s);
		s = NULL;
		exit(1);
	}
	while ((ep = readdir(dir)))
	{
		if (flag_a == 0 && ft_strncmp(ep->d_name, ".", 1) == 0)
			continue ;
		t_fileinfo *fi = new_fileinfo(dirpath, ep->d_name, ep->d_type);
		if (fi == NULL)
		{
			perror("malloc");
			exit(1);
		}
		size_t flen = len_2array((const void**)(*files));
		if (realloc_2array((void***)files, flen + 1) != 0)
		{
			perror("malloc");
			exit(1);
		}
		flen = len_2array((const void**)(*files));
		(*files)[flen] = fi;
	}
	if (ep == NULL && errno != 0)
	{
		char *s = ft_strjoin("ls: ", dirpath);
		perror(s);
		free(s);
		s = NULL;
		exit(1);
	}
	if (closedir(dir) == -1)
	{
		char *s = ft_strjoin("ls: ", dirpath);
		perror(s);
		free(s);
		s = NULL;
		exit(1);
	}
}

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

void rec_dirs(char *path, unsigned char flags, int counter, int possible_files)
{
	t_fileinfo 		**files;
	char			newdir[512 + 1];
	long long		total;
	t_spaces		spaces;

	openreaddir(&files, path, is_flag(flags, A_FLAG_SHIFT, A_FLAG_NUM));

	if (counter > 0 || possible_files > 1)
		printf("%s:\n", path);

	total = 0;
	for (int i = 0; files[i]; i++)
		get_fileinfo(files[i], &total);

	// count of spaces
	ispaces(&spaces);
	counter_of_spaces(files, &spaces);

	sort_by_flags(files, flags);

	print_files_from_dirs(files, total, spaces, is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM));

	char	**dirs = copy_dirs(files);

//	printf("\n");

	size_t i;
	if (is_flag(flags, REC_FLAG_SHIFT, REC_FLAG_NUM) == 1)
	{
		i = 0;
		while (dirs[i])
		{
			if (counter >= 0 && dirs[i] != NULL)
				printf("\n");
			if (is_flag(flags, A_FLAG_SHIFT, A_FLAG_NUM) == 0 \
				&& ft_strncmp(dirs[i], ".", 1) == 0)
			{
				i++;
				continue ;
			}
			size_t	ldname = ft_strlen(dirs[i]);
			if (ft_strncmp(dirs[i], ".", ldname > 1 ? ldname : 1) != 0 \
			&& ft_strncmp(dirs[i], "..", ldname > 2 ? ldname : 2) != 0)
			{
				ft_bzero(newdir, sizeof(char) * (512 + 1));
				ft_strlcat(newdir, path, 512);
				ft_strlcat(newdir, "/", 512);
				ft_strlcat(newdir, dirs[i], 512);
				rec_dirs(newdir, flags, counter + 1, possible_files);
			}
			i++;
		}
	}
	free_2array((void**)dirs);
	free_2array((void**)files);
}


void efiles(char **files, unsigned char flags)
{
	t_fileinfo 		**f;
	size_t			i;

	i = 0;
	f = ft_calloc(1, sizeof(t_fileinfo*));
	if (f == NULL)
	{
		perror("malloc");
		exit(1);
	}
	while (files[i])
	{
		t_fileinfo *ff = new_fileinfo(".", files[i], 0);
		if (ff == NULL)
		{
			perror("ls");
			exit(1);
		}
		size_t	filen = len_2array((const void**)f);
		if (add_2array((void***)&f, ff) != 0)
		{
			perror("malloc");
			exit(1);
		}
		i++;
	}

	i = 0;
	while (f[i])
		get_fileinfo(f[i++], 0);

	t_spaces spaces;
	ispaces(&spaces);
	counter_of_spaces(f, &spaces);

	sort_by_flags(f, flags);

	print_files_from_files(f, spaces, is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM));

	free_2array((void**)f);
}

void	initialization(t_ls *ls)
{
	init_ls(ls);
}

int main(int argc, char **argv)
{
	t_ls	ls;

	(void)argc;
	initialization(&ls);
	parsing(&ls, argv + 1);
	execution(&ls);

	return (0);
}
