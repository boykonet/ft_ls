#ifndef LS_H
# define LS_H

# define CSTDERR		2
# define MAX_FLAGS		5
# define CONST_FLAGS	"Ralrt"
# define FILETYPES_SIZE	8

# define ERR_HEADER					"ls: "
# define MALLOC_ERROR				"malloc error"
# define NULL_PARAMETER				"null parameter"
# define FLAG_NOT_SUPPORT			"illegal option -- {{flag}}\nusage: ls [-Ralrt] [file ...]"
//# define UNSUPPORTED_ASCII			"unsupported symbol: only ascii printable characters"
# define STRERROR_MESSAGE			"{{message}}"
# define UNEXPECTED_ERROR			"unexpected error"

# define PATTERN_FLAG_NOT_SUPPORT	"{{flag}}"
# define PATTERN_STRERROR_MESSAGE	"{{message}}"

# define PATTERN_WITHOUT_LINK	"{{filemode}} {{s1}}{{nlinks}} {{s2}}{{oname}}  {{s3}}{{gname}}  {{s4}}{{nbytes}} {{amonth}} {{s5}}{{day}} {{time}} {{filename}}\n"
# define PATTERN_WITH_LINK		"{{filemode}} {{s1}}{{nlinks}} {{s2}}{{oname}}  {{s3}}{{gname}}  {{s4}}{{nbytes}} {{amonth}} {{s5}}{{day}} {{time}} {{filename}} -> {{link}}\n"


# define REC_FLAG_SHIFT	7
# define REC_FLAG_NUM	128

# define A_FLAG_SHIFT	6
# define A_FLAG_NUM		64

# define L_FLAG_SHIFT	5
# define L_FLAG_NUM		32

# define R_FLAG_SHIFT	4
# define R_FLAG_NUM		16

# define T_FLAG_SHIFT	3
# define T_FLAG_NUM		8


# define FLAG_INVERTED_NO	0
# define FLAG_INVERTED_YES	1

# define IF_DIRS_NO			0
# define IF_DIRS_YES		1

# include <unistd.h>
/*
** write
** readlink
*/


# include <dirent.h>
/*
** opendir
** readdir
** closedir
*/


# include <sys/stat.h>
/*
** stat
** lstat
*/


# include <sys/types.h>
# include <pwd.h>
/*
** getpwuid
*/


# include <grp.h>
/*
** getgrgid
*/


# include <sys/xattr.h>
/*
** listxattr
** getxattr
*/


# include <time.h>
/*
** time
** ctime
*/

# include <stdlib.h>
/*
** malloc
** free
** exit
*/

# include <stdio.h>
/*
** perror
*/

# include <string.h>
/*
** strerror
*/

# include <errno.h>
/*
** errno
*/

# include "libs/libft/libft.h"


typedef int		(*f) (void*);

typedef struct s_pattern
{
	char	*pattern;
	char	*replacement;
} t_pattern;

typedef struct	s_ls
{
	unsigned char	flags;
	char			**files;
	char			**dirs;
	t_list			*epatterns;
	int 			possible_files;
} t_ls;

typedef struct s_flags {
	char	flag;
	int		shift;
	int		shnum;
} t_flags;

typedef struct s_spaces {
	size_t	s_link;
	size_t	s_oname;
	size_t	s_gname;
	size_t	s_bytes;
	size_t	s_day;
} t_spaces;

typedef struct s_fileinfo
{
	char		path[3841 + 1];
	char		filename[255 + 1];
	int			type;
	char		filemode[11 + 1];
	char		nlinks[5 + 1]; // because nlinks_t type is cast for unsigned short, maximum value is 65535
	char		oname[255 + 1]; // owner filename
	char		gname[255 + 1]; // group filename
	char 		nbytes[11 + 1]; // number of bytes
	char		amonth[3 + 1]; // abbreviated month ---> Jan
	char		day_lm[2 + 1]; // day last modified ---> 31
	char		time_lm[5 + 1]; // time last modified ---> 12:23
	char		link[255 + 1]; // only if type == DT_LNK
	struct timespec		mtime; // time last modified
} t_fileinfo;

void			parsing(t_ls *ls, char **data);

void 			init_ls(t_ls *ls);
void			clear_ls(t_ls *ls);

int				dir(t_list **listdirs, const char *dirname, char **emessage);
int				if_dir_or_file(char *filename);
int				clstat(t_list **l, char **dfiles, char **emessage);
char			*creadlink(const char *link);
char			*get_user(uid_t uid);
char			*get_group(gid_t gid);

int				len_2array(const void **darr);
void			free_2array(void **arr);
int				realloc_2array(void ***data, size_t size);
int 			add_2array(void ***data, void *value);
void			cleaner(t_ls *ls, int exitcode);
void			**calloca_to_2d(size_t size);
char			**copy(const char **srcs, size_t len);
char			**copy_dirs(t_fileinfo **files);

t_pattern		*new_pattern(char *pattern, char *replacement);
void			clear_pattern(t_pattern *pattern);
void			del_pattern(void *node);
int				add_pattern(t_list **head, char *pattern, char *replacement);
void			replace_pattern(char *dest, const char *src, t_pattern patterns[16], size_t pcount);

t_list			*find_last_elem(t_list **head);

void			handle_error(int errcode, t_list *epatterns);

void			execution(t_ls *ls);

int				is_flag(unsigned char flags, int shift, int num);

void 			rec_dirs(char *path, unsigned char flags, int counter, int possible_files);

void			get_fileinfo(t_fileinfo *finfo, long long *total);

void			efiles(char **files, unsigned char flags);

void	print_files_from_files(t_fileinfo **files, t_spaces maxs, int flag_l);
void	print_files_from_dirs(t_fileinfo **files, long long total, t_spaces maxs, int flag_l);

void	sort_fileinfo(t_fileinfo ***array, int (*func)(t_fileinfo*, t_fileinfo*, int), int is_inverted);
int		order_cmp_by_filename(t_fileinfo *first, t_fileinfo *second, int is_inverted);
int		order_cmp_by_tlastmod(t_fileinfo *first, t_fileinfo *second, int is_inverted);

#endif
