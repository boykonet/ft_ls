#ifndef LS_H
# define LS_H

# define CSTDERR		2
# define MAX_FLAGS		5
# define CONST_FLAGS	"Ralrt"

# define FLAG_NOT_SUPPORT	"ls: illegal option -- {{flag}}\nusage: ls [-Ralrt] [file ...]\n"
# define UNSUPPORTED_ASCII	"ls: unsupported symbol: only ascii printable characters\n"
# define MALLOC_ERROR		"ls: malloc error\n"

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

typedef struct	s_err
{
	t_list	*patterns;
	char	*message;
	int		exitcode;

} t_err;

typedef struct	s_ls
{
	char	*flags;
	char	**filenames;
	char	**files;
	char	**dirs;
	t_err	err;
} t_ls;

typedef struct s_iresource
{
	int		filetype;
	char	*name;
//	char	*link;
//	char	*username;
//	char	*groupname;
//	int 	size;
} t_iresource;

typedef struct s_resource
{
	t_iresource		*info;
	struct s_file	*next;
	struct s_file	*child;
} t_resource;

char			*parse_flags(char ***data, t_err *err);
char 			**parse_filenames(char ***data, t_err *err);
void 			init_ls(t_ls *ls);
void			clear_ls(t_ls *ls);
int				execute(t_ls *ls);
int				handle_recursive_flag(void *p);
int				handle_a_flag(void *p);
int				handle_l_flag(void *p);
int				handle_r_flag(void *p);
int				handle_t_flag(void *p);

int				dir(t_list **l, char *dirname, t_err *err);
int				if_dir_or_file(char *filename);
int				clstat(t_list **l, char **dfiles);
char			*creadlink(char *link);
char			*get_user(uid_t uid);
char			*get_group(gid_t gid);

//char			*find_env(char **env, char *name);

void			lexicography_sort(char ***array);

//void	del_file_struct(void *file);

int				len_double_char_array(const char **darr);
void			free_double_char_array(char **arr);
void			cleaner(t_ls *ls, int exitcode);
void			**calloca_to_2d(size_t size);
int				eprinter(char *s);

void	init_err(t_err *err);
void	clear_err(t_err *err);
int		flag_not_support_error(t_err *err, char flag);
int		malloc_error(t_err *err);

t_pattern	*new_pattern(char *pattern, char *replacement);
void		clear_pattern(t_pattern *pattern);
void		del_pattern(void *node);

t_list	*find_last_elem(t_list **head);
t_list	*add_pattern(t_list **head, char *pattern, char *replacement);
char	*replace_pattern(char *str, t_list *patterns);

void	print_error_message_and_exit(t_ls *ls);


#endif
