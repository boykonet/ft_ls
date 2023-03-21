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

# define FLAG_INVERTED_NO	0
# define FLAG_INVERTED_YES	1

int		order_cmp_by_filename(t_fileinfo *first, t_fileinfo *second, int inverted)
{
	int 	flen, slen;
	int 	res;

	flen = ft_strlen(first->filename);
	slen = ft_strlen(second->filename);
	res = ft_memcmp(first->filename, second->filename, flen > slen ? flen: slen);
	return (inverted == FLAG_INVERTED_NO) ? (res > 0) : (res < 0);
}

int		order_cmp_by_tlastmod(t_fileinfo *first, t_fileinfo *second, int inverted)
{
	return (inverted == FLAG_INVERTED_NO ? (first->mtime.tv_sec < second->mtime.tv_sec) : (first->mtime.tv_sec > second->mtime.tv_sec));
}

void	sort_files(t_fileinfo ***array, int (*func)(t_fileinfo*, t_fileinfo*, int), int inverted)
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
			if (func(p[i], p[j], inverted))
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
			dirs[j] = ft_strdup(files[i]->filename);
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

void	print_fileinfo(t_fileinfo *finfo, t_spaces *s)
{
	char	spaces[5][255] = {0};

	for (int i = 0; i < 5; i++)
		ft_memset(spaces[i], ' ', 254);

	spaces[0][s->s_link - ft_strlen(finfo->nlinks)] = '\0';
	spaces[1][s->s_oname - ft_strlen(finfo->oname)] = '\0';
	spaces[2][s->s_gname - ft_strlen(finfo->gname)] = '\0';
	spaces[3][s->s_bytes - ft_strlen(finfo->nbytes)] = '\0';
	spaces[4][s->s_day - ft_strlen(finfo->day_lm)] = '\0';

	char	pattern[1024] = {0};

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

	if (finfo->type == DT_LNK)
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
			{.filetype = DT_BLK, .replacement = 'b'},
			{.filetype = DT_CHR, .replacement = 'c'},
			{.filetype = DT_DIR, .replacement = 'd'},
			{.filetype = DT_LNK, .replacement = 'l'},
			{.filetype = DT_SOCK, .replacement = 's'},
			{.filetype = DT_FIFO, .replacement = 'p'},
			{.filetype = DT_REG, .replacement = '-'},
			{.filetype = DT_UNKNOWN, .replacement = '?'}, // TODO: check the information about unknown file
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
	if (finfo->type == DT_DIR)
	{
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
	}
	else
		filepath = ft_strdup(finfo->filename);

	if (lstat(filepath, &st) == -1)
	{
		perror("ls");
		exit(1);
	}

	if (total)
		*total += st.st_blocks;

	conf_filemode(st.st_mode, finfo->type, finfo->filemode); // TODO: might be empty value
	conf_nlink(st.st_nlink, finfo->nlinks);

	ft_memcpy(finfo->oname, get_user(st.st_uid), 255);
	ft_memcpy(finfo->gname, get_group(st.st_gid), 255);

	conf_nbytes(st.st_size, finfo->nbytes);

	conf_time(st.st_mtimespec, finfo->amonth, finfo->day_lm, finfo->time_lm);
	finfo->mtime.tv_sec = st.st_mtimespec.tv_sec;
	finfo->mtime.tv_nsec = st.st_mtimespec.tv_nsec;

	if (finfo->type == DT_LNK)
		conf_link(filepath, finfo->link);

//	if (ms)
//	{
//		max_spaces(&ms->ms_link, ft_strlen(finfo->nlinks));
//		max_spaces(&ms->ms_oname, ft_strlen(finfo->oname));
//		max_spaces(&ms->ms_gname, ft_strlen(finfo->gname));
//		max_spaces(&ms->ms_bytes, ft_strlen(finfo->nbytes));
//		max_spaces(&ms->ms_day, ft_strlen(finfo->day_lm));
//	}

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

void	print_files(t_fileinfo	**files, long long total, t_spaces spaces, int flag_l)
{
	if (flag_l == 1 && len_2array((const void**)files) > 0)
		printf("total %lld\n", total);

	for (int i = 0; i < len_2array((const void**)files); i++)
		print_fileinfo(files[i], &spaces);
}

void	ispaces(t_spaces *spaces)
{
	spaces->s_link = 0;
	spaces->s_oname = 0;
	spaces->s_gname = 0;
	spaces->s_bytes = 0;
	spaces->s_day = 0;
}

//#define NO_SUCH_FILE_OR_DIR		"ls: {{dirname}}"

void	openreaddir(t_fileinfo ***files, char *dirpath, int flag_a)
{
	DIR				*dir;
	struct dirent	*ep;

	dir = opendir(dirpath);
	if(!dir)
	{
		perror("ls");
		exit(1);
	}

	*files = (t_fileinfo**)ft_calloc(1, sizeof(t_fileinfo*));
	if (!*files)
	{
		perror("ls");
		exit(1);
	}
	while ((ep = readdir(dir)))
	{
		if (flag_a == 0 && ft_strncmp(ep->d_name, ".", 1) == 0)
			continue ;
		t_fileinfo *fi = new_fileinfo(dirpath, ep->d_name, ep->d_type);
		if (fi == NULL)
		{
			perror("ls");
			exit(1);
		}
		size_t flen = len_2array((const void**)(*files));
		if (realloc_2array((void***)files, flen + 1) != 0)
		{
			perror("ls");
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
		perror("ls");
		exit(1);
	}
}

void rec_dirs(char *path, unsigned char flags, int counter, int possible_files)
{
	t_fileinfo 		**files;
	char			newdir[512 + 1];
	long long		total;

	openreaddir(&files, path, is_flag(flags, A_FLAG_SHIFT, A_FLAG_NUM));

	if (counter > 0 || possible_files > 1)
		printf("%s:\n", path);

	total = 0;
	for (int i = 0; files[i]; i++)
		get_fileinfo(files[i], &total);

	t_spaces spaces;
	ispaces(&spaces);
	counter_of_spaces(files, &spaces);

	if (is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 0)
	{
		sort_files(&files, order_cmp_by_filename, FLAG_INVERTED_NO);
	}
	else if (is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 1)
	{
		sort_files(&files, order_cmp_by_filename, FLAG_INVERTED_YES);
	}

	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 1 \
		&& is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 0)
	{
		sort_files(&files, order_cmp_by_tlastmod, FLAG_INVERTED_NO);
	}
	else if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 1 \
		&& is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 1)
	{
		sort_files(&files, order_cmp_by_tlastmod, FLAG_INVERTED_YES);
	}
	char	**dirs = copy_dirs(files);

	if (is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM) == 1)
		print_files(files, total, spaces, 1);
	else
		print_files(files, total, spaces, 0);

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

	for (size_t i = 0; files[i]; i++)
	{
		f[i] = new_fileinfo("", files[i], 0);
		if (f[i] == NULL)
		{
			perror("ls");
			exit(1);
		}
		get_fileinfo(f[i], NULL);
	}

//	switch (st.st_mode & S_IFMT) {
//		case S_IFREG:
//			puts("|| regular file");
//			break;
//		case S_IFDIR:
//			puts("|| directory");
//			break;
//		case S_IFCHR:
//			puts("|| character device");
//			break;
//		case S_IFBLK:
//			puts("|| block device");
//			break;
//		case S_IFLNK:
//			puts("|| symbolic link");
//			break;
//		case S_IFIFO:
//			puts("|| pipe");
//			break;
//		case S_IFSOCK:
//			puts("|| socket");
//			break;
//		default:
//			puts("|| unknown");
//	}

	t_spaces spaces;
	ispaces(&spaces);
	counter_of_spaces(f, &spaces);

	if (is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 0)
	{
		sort_files(&f, order_cmp_by_filename, FLAG_INVERTED_NO);
	}
	else if (is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 1)
	{
		sort_files(&f, order_cmp_by_filename, FLAG_INVERTED_YES);
	}

	if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 1 \
		&& is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 0)
	{
		sort_files(&f, order_cmp_by_tlastmod, FLAG_INVERTED_NO);
	}
	else if (is_flag(flags, T_FLAG_SHIFT, T_FLAG_NUM) == 1 \
		&& is_flag(flags, R_FLAG_SHIFT, R_FLAG_NUM) == 1)
	{
		sort_files(&f, order_cmp_by_tlastmod, FLAG_INVERTED_YES);
	}
	char	**dirs = copy_dirs(f);

	if (is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM) == 1)
		print_files(f, 0, spaces, 1);
	else
		print_files(f, 0, spaces, 0);

	printf("\n");

	size_t i;
	free_2array((void**)f);
}




void	initialization(t_ls *ls)
{
	init_ls(ls);
}

int	add_2array(void ***data, void *value)
{
	int		e;
	size_t	len;

	if (data == NULL || value == NULL)
		return (-2);
	len = len_2array((const void**)(*data));
	e = realloc_2array(data, len + 1);
	if (e != 0)
		return (e);
	(*data)[len] = value;
	return (0);
}

int		separate_filenames(char **filenames, char ***files, char ***dirs, int *count_possible_files_and_dirs)
{
	int		errcode;
	size_t	len, i;

	if (files == NULL || dirs == NULL || filenames == NULL || count_possible_files_and_dirs == NULL)
		return (-2);
	len = len_2array((const void**)filenames);
	i = 0;
	while (i < len)
	{
		errcode = if_dir_or_file(filenames[i]);
		if (errcode == 0) // directory
		{
			errcode = add_2array((void***)dirs, ft_strdup(filenames[i]));
			if (errcode != 0)
				return (errcode);
		}
		else if (errcode == 1) // files
		{
			errcode = add_2array((void***)files, ft_strdup(filenames[i]));
			if (errcode != 0)
				return (errcode);
		}
		else if (errcode < 0) // some unexpected error
		{
			char *s = ft_strjoin("ls: ", filenames[i]);
			perror(s);
			free(s);
			s = NULL;
			errno = 0;
		}
		*count_possible_files_and_dirs += 1;
		i++;
	}
	return (0);
}

void	parsing(t_ls *ls, char **data)
{
	char	**filenames;
	int		errcode;

	errcode = parse_flags(&data, &ls->flags, &ls->epatterns);
	handle_error(errcode, ls->epatterns);

	errcode = parse_filenames(data, &filenames);
	handle_error(errcode, ls->epatterns);

	errcode = separate_filenames(filenames, &ls->files, &ls->dirs, &ls->possible_files);
	free_2array((void**)filenames);
	handle_error(errcode, ls->epatterns);
}

void	execution(t_ls *ls)
{
	execute_files(ls->files, ls->flags, &ls->epatterns);
	execute_dirs(ls->dirs, ls->flags, &ls->epatterns, ls->possible_files);
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

// ./ft_ls empty_folder -a
// expected - ls: -a: No such file or directory
// have - ls: malloc error
