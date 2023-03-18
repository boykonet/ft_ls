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
} t_ls;

typedef struct s_flags {
	char	flag;
	int		shift;
	int		shnum;
} t_flags;

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

int	execute_files(char **files, char flags[MAX_FLAGS + 1], t_list **epatterns);
int	execute_dirs(char **dirs, char flags[MAX_FLAGS + 1], t_list **epatterns);

#endif
