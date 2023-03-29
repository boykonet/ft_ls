#ifndef LS_H
# define LS_H

# define CSTDERR					2
# define MAX_FLAGS					5
# define FILETYPES_SIZE				8
# define MAX_REPL_PATTERNS			16
# define LONG_FORNAT_PARRERN_MAXS	6
# define MAX_COUNT_OF_ULL			20


# define ERR_HEADER					"ls: "
# define MALLOC_ERROR				"malloc error"
# define NULL_PARAMETER				"null parameter"
# define FLAG_NOT_SUPPORT			"illegal option -- {{flag}}\nusage: ls [-Ralrt] [file ...]"
//# define UNSUPPORTED_ASCII			"unsupported symbol: only ascii printable characters"
# define STRERROR_MESSAGE			"{{message}}"
# define UNEXPECTED_ERROR			"unexpected error"

# define PATTERN_FLAG_NOT_SUPPORT	"{{flag}}"
# define PATTERN_STRERROR_MESSAGE	"{{message}}"

# define PATTERN_WITHOUT_LINK	"{{filemode}} {{s1}}{{nlinks}} {{s2}}{{oname}}  {{s3}}{{gname}}  {{s4}}{{nbytes}} {{amonth}} {{s5}}{{day}} {{s6}}{{time_year}} {{filename}}\n"
# define PATTERN_WITH_LINK		"{{filemode}} {{s1}}{{nlinks}} {{s2}}{{oname}}  {{s3}}{{gname}}  {{s4}}{{nbytes}} {{amonth}} {{s5}}{{day}} {{s6}}{{time_year}} {{filename}} -> {{link}}\n"

# define REC_FLAG		'R'
# define REC_FLAG_SHIFT	7
# define REC_FLAG_NUM	128

# define A_FLAG			'a'
# define A_FLAG_SHIFT	6
# define A_FLAG_NUM		64

# define L_FLAG			'l'
# define L_FLAG_SHIFT	5
# define L_FLAG_NUM		32

# define R_FLAG			'r'
# define R_FLAG_SHIFT	4
# define R_FLAG_NUM		16

# define T_FLAG			't'
# define T_FLAG_SHIFT	3
# define T_FLAG_NUM		8


# define FLAG_INVERTED_NO	0
# define FLAG_INVERTED_YES	1

# define IF_DIRS_NO			0
# define IF_DIRS_YES		1

# define HALF_OF_YEAR_SECONDS	(365.2422 * 0.5 * 24 * 60 * 60)

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
	char	pattern[255 + 1];
	char	replacement[255 + 1];
} t_pattern;

typedef struct	s_ls
{
	unsigned char	flags;
	char			**files;
	char			**dirs;
	t_pattern 		epatterns[1];
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
	size_t	s_time_year;
} t_spaces;

typedef struct s_fileinfo
{
	char				path[3841 + 1];
	char				filename[255 + 1];
	int					type;
	char				filemode[11 + 1];
	char				nlinks[5 + 1];			// because nlinks_t type is cast for unsigned short, maximum value is 65535
	char				oname[255 + 1];			// owner filename
	char				gname[255 + 1];			// group filename
	char 				nbytes[11 + 1];			// number of bytes
	char				amonth[3 + 1];			// abbreviated month ---> Jan
	char				day_lm[2 + 1];			// day last modified ---> 31
	char				time_year_lm[5 + 1];	// time last modified or year if mote than 6 months or the date in the future ---> 12:23
	char				link[255 + 1];			// only if type == S_IFLNK
	struct timespec		mtime;					// time last modified
} t_fileinfo;

typedef struct s_filetypes
{
	int		filetype;
	char	replacement;
} t_filetypes;

void			initialization(t_ls *ls);
void			parsing(t_ls *ls, char **data);
void			execution(t_ls *ls);

void 			init_ls(t_ls *ls);
void			clear_ls(t_ls *ls);

int				dir(t_list **listdirs, const char *dirname, char **emessage);
int				if_dir_or_file(char *filename);
int				clstat(t_list **l, char **dfiles, char **emessage);
char			*creadlink(const char *link);
void			get_owner(uid_t uid, char owner[255 + 1]);
void			get_group(gid_t gid, char group[255 + 1]);

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
void			replace_pattern(char *dest, const char *src, t_pattern patterns[MAX_REPL_PATTERNS + 1]);

t_list			*find_last_elem(t_list **head);

void	handle_error(char emessage[255 + 1]);

int				is_flag(unsigned char flags, int shift, int num);

void 			handle_dirs(char *path, unsigned char flags, int counter, int possible_files);
void			handle_files(char **files, unsigned char flags);

void			set_fileinfo(t_fileinfo *finfo, long long *total);

void	print_files_from_files(t_fileinfo **files, t_spaces maxs, int flag_l);
void	print_files_from_dirs(t_fileinfo **files, long long total, t_spaces maxs, int flag_l);

void	sort_fileinfo(t_fileinfo ***array, int (*func)(t_fileinfo*, t_fileinfo*, int), int is_inverted);
int		order_cmp_by_filename(t_fileinfo *first, t_fileinfo *second, int is_inverted);
int		order_cmp_by_tlastmod(t_fileinfo *first, t_fileinfo *second, int is_inverted);

int		max(int first, int second);
void	max_spaces(size_t *first, size_t second);
int 	is_more(long first, long second);
int 	is_less(long first, long second);

t_fileinfo	*new_fileinfo(char *path, char *filename, int type);

void	sort_by_flags(t_fileinfo **files, unsigned char flags);
void	openreaddir(t_fileinfo ***files, char *dirpath, int flag_a);
void	print_files_from_files(t_fileinfo **files, t_spaces maxs, int flag_l);
void	print_files_from_dirs(t_fileinfo **files, long long total, t_spaces maxs, int flag_l);

void	ispaces(t_spaces *spaces);
void	set_spaces(char spaces[LONG_FORNAT_PARRERN_MAXS][254 + 1], t_fileinfo *finfo, t_spaces maxs);
void	counter_of_spaces(t_fileinfo **info, t_spaces *spaces);


void	set_group(char gname[255 + 1], gid_t st_gid);
void	set_type(int *type, mode_t st_mode);
void	set_owner(char oname[255 + 1], uid_t st_uid);
void 	set_link(const char *filepath, char *link);
void	set_number_of_bytes(off_t st_size, char *bytes);
void	set_number_of_links(nlink_t st_nlinks, char *links);
void	set_filemode(char *filepath, mode_t mode, int filetype, char *filemode);
void	set_time(struct timespec st_mtimespec, char *amonth, char *day_lm, char *time_year_lm, struct timespec *mtime);


void	rec_itoa_ull(char *numstr, unsigned long long number, int base, char *base_chars);

#endif
