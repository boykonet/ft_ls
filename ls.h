#ifndef LS_H
# define LS_H

# define CSTDERR						2
# define FILETYPES_SIZE					8
# define MAX_REPL_PATTERNS				19
# define MAX_ERROR_PATTERNS				2
# define COUNT_REGULAR_SPACES			6
# define STRING_SIZE					255

# define ERR_CODE_MALLOC_ERROR			(-1)
# define ERR_CODE_NULL_PARAMETER		(-2)
# define ERR_CODE_STRERROR				(-3)
# define ERR_CODE_FLAG_NOT_SUPPORT		(-4)
# define ERR_CODE_FILE_ERROR			(-5)

# define DECIMAL_BASE_STR				"0123456789"


# define ERR_HEADER						"ls: "

# define MALLOC_ERROR					"malloc: {{error}}"
# define PATTERN_MALLOC_ERROR			"{{error}}"

# define NULL_PARAMETER					"null parameter"

# define STRERROR_MESSAGE				"{{message}}"
# define PATTERN_STRERROR_MESSAGE		"{{message}}"

# define FLAG_NOT_SUPPORT				"illegal option -- {{flag}}\nusage: ls [-GRadfglrtu] [file ...]"
# define PATTERN_FLAG_NOT_SUPPORT		"{{flag}}"

# define FILE_ERROR						"{{filename}}: {{message}}"
# define PATTERN_FILE_ERROR_FILENAME	"{{filename}}"
# define PATTERN_FILE_ERROR_MESSAGE		"{{message}}"

# define WITHOUT_LINK					"{{filemode}} {{s1}}{{nlinks}} {{s2}}{{oname}}{{two_spaces}}{{s3}}{{gname}}  {{s4}}{{nbytes}} {{amonth}} {{s5}}{{day}} {{s6}}{{time_year}} {{color}}{{filename}}{{reset_color}}"
# define WITH_LINK						"{{filemode}} {{s1}}{{nlinks}} {{s2}}{{oname}}{{two_spaces}}{{s3}}{{gname}}  {{s4}}{{nbytes}} {{amonth}} {{s5}}{{day}} {{s6}}{{time_year}} {{color}}{{filename}}{{reset_color}} -> {{link}}"
# define SHORT_FILE_INFO				"{{color}}{{filename}}{{reset_color}}"

/*                  fourth 4 bytes                 third 4 bytes            second 4 bytes        first 4 bytes
** bits    |     0 |     0 |    0 |    0  ||     0 |    0 |   0 |   1  ||   1 |  1 |  1 |  1  ||  1 | 1 | 1 | 1
** flag    |     - |     - |    - |    -  ||     - |    - |   G |   g  ||   R |  a |  l |  r  ||  t | d | f | u
** shift   |    15 |    14 |   13 |   12  ||    11 |   10 |   9 |   8  ||   7 |  6 |  5 |  4  ||  3 | 2 | 1 | 0
** value   | 32768 | 16384 | 8192 | 4096  ||  2048 | 1024 | 512 | 256  || 128 | 64 | 32 | 16  ||  8 | 4 | 2 | 1
*/
# define MAX_FLAGS			10

# define COLOR_FLAG			'G'
# define COLOR_FLAG_SHIFT	9
# define COLOR_FLAG_VALUE	512

# define G_FLAG				'g'
# define G_FLAG_SHIFT		8
# define G_FLAG_VALUE		256

# define REC_FLAG			'R'
# define REC_FLAG_SHIFT		7
# define REC_FLAG_VALUE		128

# define A_FLAG				'a'
# define A_FLAG_SHIFT		6
# define A_FLAG_VALUE		64

# define L_FLAG				'l'
# define L_FLAG_SHIFT		5
# define L_FLAG_VALUE		32

# define R_FLAG				'r'
# define R_FLAG_SHIFT		4
# define R_FLAG_VALUE		16

# define T_FLAG				't'
# define T_FLAG_SHIFT		3
# define T_FLAG_VALUE		8

# define D_FLAG				'd'
# define D_FLAG_SHIFT		2
# define D_FLAG_VALUE		4

# define F_FLAG				'f'
# define F_FLAG_SHIFT		1
# define F_FLAG_VALUE		2

# define U_FLAG				'u'
# define U_FLAG_SHIFT		0
# define U_FLAG_VALUE		1


# define FLAG_INVERTED_NO	0

# define HALF_OF_YEAR_SECONDS	(365.2422 * 0.5 * 24 * 60 * 60)

# define DEFAULT_COLORS		"exfxcxdxbxegedabagacad"

# define EMPTY				""

# define COLOR_PATTERN		"\e[{{type_font}}{{s1}}{{f_code}}{{f_color}}{{s2}}{{b_code}}{{b_color}}m"
# define TYPE_FONT_PATTERN	"{{type_font}}"
# define F_CODE_PATTERN		"{{f_code}}"
# define F_COLOR_PATTERN	"{{f_color}}"
# define B_CODE_PATTERN		"{{b_code}}"
# define B_COLOR_PATTERN	"{{b_color}}"
# define SEMICOLON1_PATTERN	"{{s1}}"
# define SEMICOLON2_PATTERN	"{{s2}}"
# define COUNT_COLOR_PATTERNS	7

# define REGULAR_FONT		"0"
# define BOLT_FONT			"1"
# define SEMICOLON			";"
# define FOREGROUND_CODE	"3"
# define BACKGROUND_CODE	"4"

# define BLACK		"0"
# define RED		"1"
# define GREEN		"2"
# define BROWN		"3"
# define BLUE		"4"
# define PURPLE		"5"
# define CYAN		"6"
# define LIGHT_GREY	"7"

# define RESET_COLOR	"\e[0m"

# define DIR_TYPE										1
# define LINK_TYPE										2
# define SOCKET_TYPE									3
# define PIPE_TYPE										4
# define EX_FILE_TYPE									5
# define BLOCK_TYPE										6
# define CHARACTER_TYPE									7
# define EX_WITH_SETUID_BIT_SET_TYPE					8
# define EX_WITH_SETGID_BIT_SET_TYPE					9
# define DIR_WRITABLE_TO_OTHER_WITH_STICKY_BIT_TYPE		10
# define DIR_WRITABLE_TO_OTHER_WITHOUT_STICKY_BIT_TYPE	11

# define MIN_FILE_TYPES									1
# define MAX_FILE_TYPES									11

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

#include <sys/termios.h>
/*
** tcgetattr
*/

# include "libs/libft/libft.h"

typedef struct s_pattern
{
	char	pattern[STRING_SIZE + 1];
	char	replacement[STRING_SIZE + 1];
} t_pattern;

typedef struct	s_ls
{
	unsigned short	flags;
	char			**files;
	char			**dirs;
	t_pattern 		epatterns[MAX_ERROR_PATTERNS];
	int 			possible_files;
	int 			global_ecode;
} t_ls;

typedef struct s_flags {
	char	flag;
	int		shift;
	int		value;
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
	char			path[3841 + 1];
	char			filename[STRING_SIZE + 1];
	unsigned int	type;
	size_t 			color_type;
	char			filemode[11 + 1];
	char			nlinks[5 + 1];			/* because nlinks_t type is cast for unsigned short, maximum value is 65535 */
	char			oname[STRING_SIZE + 1];	/* owner filename */
	char			gname[STRING_SIZE + 1];	/* group filename */
	char 			nbytes[11 + 1];			/* number of bytes */
	char			amonth[3 + 1];			/* abbreviated month ---> Jan */
	char			day_lm[2 + 1];			/* day last modified ---> 31 */
	char			time_year_lm[5 + 1];	/* time last modified or year if mote than 6 months or the date in the future ---> 12:23 */
	char			link[STRING_SIZE + 1];	/* only if type == S_IFLNK */
	struct timespec	filetime;				/* time of last modified or time of last access if -u flag is setting */
} t_fileinfo;

typedef struct s_filetypes
{
	unsigned int	filetype;
	char			replacement;
} t_filetypes;

typedef struct s_colors {
	char	key;
	char 	*value;
} t_colors;

void	initialization(t_ls *ls);
void	parsing(t_ls *ls, char **data);
void	execution(t_ls *ls);

void 	init_ls(t_ls *ls);
void	clear_ls(t_ls *ls);

int		if_dir_or_file(char *filename);

int		creadlink(const char *link, char *file);
void	cstrmode(mode_t st_mode, char *filemode);
int		cisatty(int fd);

int		len_2array(const void **darr);
void	free_2array(void **arr);
void	free_2array_content(void **arr);
int		realloc_2array(void ***data, size_t size);
int 	add_2array(void ***data, void *value);

void	cleaner(t_ls *ls, int exitcode);

void	**calloca_to_2d(size_t size);
char	**copy(const char **srcs, size_t len);
char	**copy_dirs(t_fileinfo **files);

void 	add_pattern(t_pattern p[1], char *pattern, char *replacement);
void	replace_one_pattern(char *dest, t_pattern pattern[1]);
void	replace_pattern(char *dest, const char *src, t_pattern patterns[MAX_REPL_PATTERNS], size_t count);

int 	handle_error(int ecode, t_pattern p[MAX_ERROR_PATTERNS], int *gcode);

int		is_flag(unsigned short flags, int shift, int value);

int 	set_fileinfo(t_fileinfo *finfo, unsigned short flags, long long *total);

void	print_files_from_files(t_fileinfo **files, unsigned short flags);
void	print_files_from_dirs(t_fileinfo **files, long long total, unsigned short flags);

void	sort_fileinfo(t_fileinfo **array, size_t count_elems, int (*func)(void*, void*, int), int is_inverted);
int		order_cmp_by_filename(void *first, void *second, int is_inverted);
int		order_cmp_by_tlastmod(void *first, void *second, int is_inverted);
void	quick_sort(void ***elems, size_t count, int (*compare_func)(void*, void*, int), int is_inverted);

int		max(int first, int second);
void	max_spaces(size_t *first, size_t second);
int 	is_more_equal(long first, long second);
int 	is_less_equal(long first, long second);

t_fileinfo	*new_fileinfo(char *path, char *filename);

void	sort_by_flags(t_fileinfo **files, unsigned short flags);
int 	openreaddir(char ***files, char *dirpath, int flag_a);

void	ispaces(t_spaces *spaces);
void	set_spaces(char spaces[COUNT_REGULAR_SPACES][254 + 1], t_fileinfo *finfo, t_spaces maxs);
void	counter_of_spaces(t_fileinfo **info, t_spaces *spaces);


void	set_group(char gname[STRING_SIZE + 1], gid_t st_gid);
void	set_type(unsigned int *type, mode_t st_mode);
void	set_owner(char oname[STRING_SIZE + 1], uid_t st_uid);
int 	set_link(const char *filepath, char *link);
void	set_number_of_bytes(off_t st_size, char *bytes);
void	set_number_of_links(nlink_t st_nlinks, char *links);
void	set_filemode(char *filepath, mode_t mode, unsigned int filetype, char *filemode);
int 	set_time(struct timespec st_time, char *amonth, char *day_lm, char *time_year_lm);


void	rec_itoa_ull(char *numstr, unsigned long long number, int base, char *base_chars);
void	putnbr(long long number, int base, char *base_str);

void	handle_ecodes(int ecode, char *filename, t_pattern p[MAX_ERROR_PATTERNS]);

int		set_color_type(mode_t mode);
void	set_color(size_t filetype, char data[11 + 1]);

#endif
