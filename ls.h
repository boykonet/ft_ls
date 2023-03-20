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

typedef struct s_maxsymbols {
	size_t	ms_link;
	size_t	ms_oname;
	size_t	ms_gname;
	size_t	ms_bytes;
	size_t	ms_day;
} t_maxsymbols;

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

int		parse_flags(char ***data, unsigned char *flags, t_list **patterns);
int				parse_filenames(char **data, char ***filenames);
void 			init_ls(t_ls *ls);
void			clear_ls(t_ls *ls);
int				execute(t_ls *ls);
int				handle_recursive_flag(void *p);
int				handle_a_flag(void *p);
int				handle_l_flag(void *p);
int				handle_r_flag(void *p);
int				handle_t_flag(void *p);

int				dir(t_list **listdirs, const char *dirname, char **emessage);
int				if_dir_or_file(char *filename);
int				clstat(t_list **l, char **dfiles, char **emessage);
char			*creadlink(const char *link);
char			*get_user(uid_t uid);
char			*get_group(gid_t gid);

//char			*find_env(char **env, char *filename);

void			lexicography_sort(char ***array);

//void	del_file_struct(void *file);

int				len_2array(const void **darr);
void			free_2array(void **arr);
int				realloc_2array(void ***data, size_t size);
int 			add_2array(void ***data, void *value);
void			cleaner(t_ls *ls, int exitcode);
void			**calloca_to_2d(size_t size);
char			**copy(const char **srcs, size_t len);

//void	init_err(t_err *err);
//void	clear_err(t_err *err);
//int		flag_not_support_error(t_err *err, char flag);

t_pattern	*new_pattern(char *pattern, char *replacement);
void		clear_pattern(t_pattern *pattern);
void		del_pattern(void *node);

t_list	*find_last_elem(t_list **head);
int	add_pattern(t_list **head, char *pattern, char *replacement);
void		replace_pattern(char *dest, const char *src, t_pattern patterns[16], size_t pcount);

//void	print_error_message(t_err *err);
void	handle_error(int errcode, t_list *epatterns);

int	execute_files(char **files, unsigned char flags, t_list **epatterns);
int	execute_dirs(char **dirs,unsigned char flags, t_list **epatterns, int possible_files);

int		is_flag(unsigned char flags, int shift, int num);

void rec_dirs(char *path, unsigned char flags, int counter, int possible_files);

void	get_fileinfo(t_fileinfo *finfo, t_maxsymbols *ms, long long *total);

#endif
