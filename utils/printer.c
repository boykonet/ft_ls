#include "../ls.h"

typedef struct s_colors {
	char	key;
	char 	*value;
} t_colors;

typedef struct s_tfiles {
	unsigned int	filetype;
	size_t 			findex;
	size_t 			bindex;
} t_tfiles;

char	find_color()
{

}

void	set_color(size_t filetype, char data[11 + 1])
{
	t_tfiles	tfiles[11 + 1] = {
			{.filetype = DIR_TYPE, .findex = 0, .bindex = 1},
			{.filetype = LINK_TYPE, .findex = 2, .bindex = 3},
			{.filetype = SOCKET_TYPE, .findex = 4, .bindex = 5},
			{.filetype = PIPE_TYPE, .findex = 6, .bindex = 7},
			{.filetype = EX_FILE_TYPE, .findex = 8, .bindex = 9},
			{.filetype = BLOCK_TYPE, .findex = 10, .bindex = 11},
			{.filetype = CHARACTER_TYPE, .findex = 12, .bindex = 13},
			{.filetype = EX_WITH_SETUID_BIT_SET_TYPE, .findex = 14, .bindex = 15},
			{.filetype = EX_WITH_SETGID_BIT_SET_TYPE, .findex = 16, .bindex = 17},
			{.filetype = DIR_WRITABLE_TO_OTHER_WITH_STICKY_BIT_TYPE, .findex = 18, .bindex = 19},
			{.filetype = DIR_WRITABLE_TO_OTHER_WITHOUT_STICKY_BIT_TYPE, .findex = 20, .bindex = 21}};
	t_colors	colors[17 + 1] = {
			{.key = 'a', .value = BLACK},
			{.key = 'b', .value = RED},
			{.key = 'c', .value = GREEN},
			{.key = 'd', .value = BROWN},
			{.key = 'e', .value = BLUE},
			{.key = 'f', .value = PURPLE},
			{.key = 'g', .value = CYAN},
			{.key = 'h', .value = LIGHT_GREY}};
	const char dcolors[] = DEFAULT_COLORS;
	char color[] = COLOR_PATTERN;
	t_pattern patterns[7 + 1];

	if (!(filetype >= 1 && filetype <= 11))
		return ;

	ft_bzero(patterns, sizeof(patterns));
	size_t findex, bindex;

	findex = tfiles[filetype - 1].findex;
	bindex = tfiles[filetype - 1].bindex;

	if (dcolors[findex] >= 'a' && dcolors[findex] <= 'z')
		add_pattern(&patterns[0], TYPE_FONT_PATTERN, REGULAR_FONT);
	else
		add_pattern(&patterns[0], TYPE_FONT_PATTERN, BOLT_FONT);
	add_pattern(&patterns[1], SEMICOLON1_PATTERN, SEMICOLON);

	add_pattern(&patterns[2], F_CODE_PATTERN, FOREGROUND_CODE);

}

void	print_fileinfo(t_fileinfo *finfo, t_spaces maxs, int g_flag, int color_flag)
{
	t_pattern	patterns[MAX_REPL_PATTERNS];
	char		spaces[COUNT_REGULAR_SPACES][254 + 1];
	char		pattern[1024] = {0};
	char 		color[11 + 1] = {0};
	char		reset_color[5 + 1] = {0};

	ft_bzero(spaces, COUNT_REGULAR_SPACES * (254 + 1) * sizeof(char));
	set_spaces(spaces, finfo, maxs);

	if (color_flag == 1 && finfo->color_type != 0)
	{
		set_color(finfo->color_type, color);
		ft_memcpy(reset_color, RESET_COLOR, ft_strlen(RESET_COLOR));
	}

	add_pattern(&patterns[0], "{{filemode}}", finfo->filemode);
	add_pattern(&patterns[1], "{{s1}}", spaces[0]);
	add_pattern(&patterns[2], "{{nlinks}}", finfo->nlinks);
	if (g_flag == 0)
	{
		add_pattern(&patterns[3], "{{s2}}", spaces[1]);
		add_pattern(&patterns[4], "{{oname}}", finfo->oname);
		add_pattern(&patterns[5], "{{two_spaces}}", "  ");
	}
	else
	{
		add_pattern(&patterns[3], "{{s2}}", "");
		add_pattern(&patterns[4], "{{oname}}", "");
		add_pattern(&patterns[5], "{{two_spaces}}", "");
	}
	add_pattern(&patterns[6], "{{s3}}", spaces[2]);
	add_pattern(&patterns[7], "{{gname}}", finfo->gname);
	add_pattern(&patterns[8], "{{s4}}", spaces[3]);
	add_pattern(&patterns[9], "{{nbytes}}", finfo->nbytes);
	add_pattern(&patterns[10], "{{amonth}}", finfo->amonth);
	add_pattern(&patterns[11], "{{s5}}", spaces[4]);
	add_pattern(&patterns[12], "{{day}}", finfo->day_lm);
	add_pattern(&patterns[13], "{{s6}}", spaces[5]);
	add_pattern(&patterns[14], "{{time_year}}", finfo->time_year_lm);
	add_pattern(&patterns[15], "{{color}}", color);
	add_pattern(&patterns[16], "{{filename}}", finfo->filename);
	add_pattern(&patterns[17], "{{reset_color}}", reset_color);
	add_pattern(&patterns[18], "{{link}}", finfo->link);

	if (finfo->type == S_IFLNK)
		replace_pattern(pattern, PATTERN_WITH_LINK, patterns, MAX_REPL_PATTERNS);
	else
		replace_pattern(pattern, PATTERN_WITHOUT_LINK, patterns, 18);
	ft_putstr_fd(pattern, 1);
}

void	print_without_full_info(t_fileinfo **files)
{
	size_t	i;

	i = 0;
	while (files[i])
		ft_putendl_fd(files[i++]->filename, 1);
}

void	print_total(long long total)
{
	ft_putstr_fd("total ", 1);
	putnbr(total, 10, DECIMAL_BASE_STR);
	ft_putchar_fd('\n', 1);
}

void	print_files_from_dirs(t_fileinfo **files, long long total, unsigned short flags)
{
	t_spaces	maxs;
	size_t		i;

	i = 0;
	if (files == NULL)
		return ;
	ispaces(&maxs);
	counter_of_spaces(files, &maxs);

	if (is_flag(flags, L_FLAG_SHIFT, L_FLAG_VALUE) == 1 && len_2array((const void**)files) > 0)
		print_total(total);

	if (is_flag(flags, L_FLAG_SHIFT, L_FLAG_VALUE) == 0)
		print_without_full_info(files);
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs, is_flag(flags, G_FLAG_SHIFT, G_FLAG_VALUE)/*, is_flag(flags, COLOR_FLAG_SHIFT, COLOR_FLAG_VALUE)*/);
	}
}

void	print_files_from_files(t_fileinfo **files, unsigned short flags)
{
	t_spaces	maxs;
	size_t	i;

	i = 0;
	if (files == NULL)
		return ;
	ispaces(&maxs);
	counter_of_spaces(files, &maxs);
	if (is_flag(flags, L_FLAG_SHIFT, L_FLAG_VALUE) == 0)
		print_without_full_info(files);
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs, is_flag(flags, G_FLAG_SHIFT, G_FLAG_VALUE)/*, is_flag(flags, COLOR_FLAG_SHIFT, COLOR_FLAG_VALUE)*/);
	}
}
