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

void	set_spaces(char spaces[LONG_FORNAT_PARRERN_MAXS][254 + 1], t_fileinfo *finfo, t_spaces maxs)
{
	int		cos[LONG_FORNAT_PARRERN_MAXS] = {0}; // count of spaces
	size_t	i;

	cos[0] = maxs.s_link - ft_strlen(finfo->nlinks);
	cos[1] = maxs.s_oname - ft_strlen(finfo->oname);
	cos[2] = maxs.s_gname - ft_strlen(finfo->gname);
	cos[3] = maxs.s_bytes - ft_strlen(finfo->nbytes);
	cos[4] = maxs.s_day - ft_strlen(finfo->day_lm);
	cos[5] = maxs.s_time_year - ft_strlen(finfo->time_year_lm);

	i = 0;
	while (i < LONG_FORNAT_PARRERN_MAXS)
	{
		ft_memset(spaces[i], ' ', cos[i]);
		i++;
	}
}

void	print_fileinfo(t_fileinfo *finfo, t_spaces maxs)
{
	char	spaces[LONG_FORNAT_PARRERN_MAXS][254 + 1];
	char	pattern[1024] = {0};

	ft_bzero(spaces, LONG_FORNAT_PARRERN_MAXS * (254 + 1) * sizeof(char));
	set_spaces(spaces, finfo, maxs);

	t_pattern	patterns[MAX_REPL_PATTERNS + 1] = {
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
			{.pattern = "{{s6}}", .replacement = spaces[5]},
			{.pattern = "{{time_year}}", .replacement = finfo->time_year_lm},
			{.pattern = "{{filename}}", .replacement = finfo->filename},
			{.pattern = "{{link}}", .replacement = finfo->link}};

	if (finfo->type == S_IFLNK)
		replace_pattern(pattern, PATTERN_WITH_LINK, patterns);
	else
		replace_pattern(pattern, PATTERN_WITHOUT_LINK, patterns);

	write(1, pattern, ft_strlen(pattern));
}

int 	the_largest_filename(t_fileinfo **files)
{
	size_t	max, i, clen;

	max = 0;
	if (files == NULL)
		return (0);
	i = 0;
	while (files[i])
	{
		clen = ft_strlen(files[i]->filename); // current len
		if (max < clen)
			max = clen;
		i++;
	}
	return (i);
}

void	print_without_full_info(t_fileinfo **files)
{
	char	buf[255 + 1];
	int		largest;
	size_t	cos, i; // count of symbols

	largest = the_largest_filename(files);
	if (largest == 0)
		return ;
	cos = largest + (largest % 8) + (8 - (largest % 8));
	i = 0;
	while (files[i])
	{
		size_t	lfilename = ft_strlen(files[i]->filename);
		if (files[i + 1] == NULL)
		{
			write(1, files[i]->filename, lfilename);
		}
		else
		{
			ft_memset(buf, ' ', cos + 1);
			buf[cos] = '\0';
			ft_memcpy(buf, files[i]->filename, ft_strlen(files[i]->filename));
			write(1, buf, ft_strlen(buf));
		}
		i++;
	}
	write(1, "\n", 1);
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
			{.filetype = S_IFWHT, .replacement = '?'}}; // TODO: check the information about unknown file

	for (int i = 0; i < FILETYPES_SIZE; i++)
	{
		if (type == filetypes[i].filetype)
		{
			*filetype = filetypes[i].replacement;
			break ;
		}
	}
}

void		is_extended_attributes(char *path, char *attr)
{
	ssize_t	size = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (size > 0)
		*attr = '@';
}

void	set_file_attribute(char *path, char *attr)
{
	is_extended_attributes(path, attr);
}

void	conf_filemode(char *filepath, mode_t mode, int filetype, char *filemode)
{
	cstrmode(mode, &filemode[1]);
	set_filetype(&filemode[0], filetype);
	set_file_attribute(filepath, &filemode[10]);
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

void	conf_time(struct timespec st_mtimespec, char *amonth, char *day_lm, char *time_year_lm, struct timespec *mtime)
{
	char	**t;
	time_t	sts;
	long	diff;

	mtime->tv_sec = st_mtimespec.tv_sec;
	mtime->tv_nsec = st_mtimespec.tv_nsec;

	t = ft_split(ctime((const time_t*)&st_mtimespec.tv_sec), ' ');
	if (!t)
	{
		perror("malloc");
		exit(1);
	}

	ft_memcpy(amonth, t[1], ft_strlen(t[1]));
	ft_memcpy(day_lm, t[2], ft_strlen(t[2]));

	// get current time
	sts = time(NULL);
	if (sts == -1)
	{
		perror("time");
		exit(1);
	}
	diff = sts - (const time_t)st_mtimespec.tv_sec;
	if (diff >= 0 && diff < HALF_OF_YEAR_SECONDS)
	{
		*ft_strrchr(t[3], ':') = '\0';
		ft_memcpy(time_year_lm, t[3], ft_strlen(t[3]));
	}
	else
	{
		*ft_strrchr(t[4], '\n') = '\0';
		ft_memcpy(time_year_lm, t[4], ft_strlen(t[4]));
	}
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
	ft_memcpy(link, new_link, ft_strlen(new_link));
}

void	conf_owner(char oname[255 + 1], uid_t st_uid)
{
	char	*owner;

	owner = get_user(st_uid);

	ft_memcpy(oname, owner, 255);
	free(owner);
	owner = NULL;
}

void	conf_group(char gname[255 + 1], gid_t st_gid)
{
	char	*group;

	group = get_group(st_gid);
	ft_memcpy(gname, group, 255);
	free(group);
	group = NULL;
}

void	conf_filetype(int *type, mode_t st_mode)
{
	if (type == NULL)
		return ;
	*type = st_mode & S_IFMT;
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
		perror("ls");
		exit(1);
	}

	if (total != NULL)
		*total += st.st_blocks;

	// filetype
	conf_filetype(&finfo->type, st.st_mode);

	conf_filemode(filepath, st.st_mode, finfo->type, finfo->filemode); // TODO: might be empty value
	conf_nlink(st.st_nlink, finfo->nlinks);

	conf_owner(finfo->oname, st.st_uid);
	conf_group(finfo->gname, st.st_gid);

	conf_nbytes(st.st_size, finfo->nbytes);

	conf_time(st.st_mtimespec, finfo->amonth, finfo->day_lm, finfo->time_year_lm, &finfo->mtime); // TODO: if more than 6 months or in the future, print year (check future time)

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
		max_spaces(&spaces->s_time_year, ft_strlen(info[i]->time_year_lm));
	}
}

void	print_total(long long total)
{
	char	*stotal = ft_itoa(total);
	if (stotal == NULL)
	{
		perror("malloc");
		exit(1);
	}
	write(1, "total ", 6);
	write(1, stotal, ft_strlen(stotal));
	free(stotal);
	stotal = NULL;
	write(1, "\n", 1);
}

void	print_files_from_dirs(t_fileinfo **files, long long total, t_spaces maxs, int flag_l)
{
	size_t	i;

	i = 0;
	if (flag_l == 1 && len_2array((const void**)files) > 0)
		print_total(total);

	if (flag_l == 0)
		print_without_full_info(files);
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs);
	}
}

void	print_files_from_files(t_fileinfo **files, t_spaces maxs, int flag_l)
{
	size_t	i;

	i = 0;
	if (flag_l == 0)
		print_without_full_info(files);
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs);
	}
}

void	ispaces(t_spaces *spaces)
{
	spaces->s_link = 0;
	spaces->s_oname = 0;
	spaces->s_gname = 0;
	spaces->s_bytes = 0;
	spaces->s_day = 0;
	spaces->s_time_year = 0;
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

void	initialization(t_ls *ls)
{
	init_ls(ls);
}

# define MAX_COUNT_OF_ULL 20

void	set_number(unsigned long long number, int base, char *value, char *c)
{
	if (number >= base)
		set_number(number / base, base, value + 1, c);
	value[ft_strlen(value)] = c[number % base];
}

int main(int argc, char **argv)
{
	t_ls	ls;
	char	val[MAX_COUNT_OF_ULL + 1] = {0};

	set_number(1234567891234567890, 10, val, "0123456789");
	printf("[%s]\n", val);

	(void)argc;
	initialization(&ls);
	parsing(&ls, argv + 1);
	execution(&ls);

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
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 second		(2)
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 third		(3)
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 fouth		(1)
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
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 fouth		1
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 second		2
//-rw-r--r--  1 gkarina  piscine    0 Mar 23 13:39 third		3
//srwxr-xr-x  1 gkarina  piscine    0 Feb  3 23:52 socket.sock
//prw-r--r--  1 gkarina  piscine    0 Feb  3 23:51 myfifo
//drwxr-xr-x  7 gkarina  piscine  238 Feb  3 22:57 dir1
//drwxr-xr-x  2 gkarina  piscine   68 Feb  3 22:57 dir2
//lrwxr-xr-x  1 gkarina  piscine    4 Jan 31 22:42 link -> file
//-rw-r--r--  1 gkarina  piscine    0 Jan 31 22:42 file

