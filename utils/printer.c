#include "../ls.h"

//typedef struct s_colors {
//	char	key;
//	char 	*value;
//} t_colors;
//
//typedef struct s_tfiles {
//	unsigned int	filetype;
//	size_t 			iforeground;
//	size_t 			ibackground;
//} t_tfiles;
//
//void	set_color(char color[COUNT_OF_COLOR + 1])
//{
//	t_tfiles	tfiles[11 + 1] = {
//			{.filetype = DIR_TYPE, .iforeground = 0, .ibackground = 1},
//			{.filetype = SYMBOLIC_LINK_TYPE, .iforeground = 2, .ibackground = 3},
//			{.filetype = SOCKET_TYPE, .iforeground = 4, .ibackground = 5},
//			{.filetype = PIPE_TYPE, .iforeground = 6, .ibackground = 7},
//			{.filetype = EXECUTABLE_FILE_TYPE, .iforeground = 8, .ibackground = 9},
//			{.filetype = BLOCK_SPECIAL_TYPE, .iforeground = 10, .ibackground = 11},
//			{.filetype = CHARACTER_SPECIAL_TYPE, .iforeground = 12, .ibackground = 13},
//			{.filetype = EX_WITH_SETUID_BIT_SET_TYPE, .iforeground = 14, .ibackground = 15},
//			{.filetype = EX_WITH_SETGID_BIT_SET_TYPE, .iforeground = 16, .ibackground = 17},
//			{.filetype = DIR_WRITABLE_TO_OTHER_WITH_STICKY_BIT_TYPE, .iforeground = 18, .ibackground = 19},
//			{.filetype = DIR_WRITABLE_TO_OTHER_WITHOUT_STICKY_BIT_TYPE, .iforeground = 20, .ibackground = 21}};
//	t_colors	colors[17 + 1] = {
//			{.key = 'a', .value = BLACK_COLOR},
//			{.key = 'b', .value = RED_COLOR},
//			{.key = 'c', .value = GREEN_COLOR},
//			{.key = 'd', .value = BROWN_COLOR},
//			{.key = 'e', .value = BLUE_COLOR},
//			{.key = 'f', .value = PURPLE_COLOR},
//			{.key = 'g', .value = CYAN_COLOR},
//			{.key = 'h', .value = LIGHT_GREY_COLOR},
//			{.key = 'A', .value = BOLD_BLACK_COLOR},
//			{.key = 'B', .value = BOLD_RED_COLOR},
//			{.key = 'C', .value = BOLD_GREEN_COLOR},
//			{.key = 'D', .value = BOLD_BROWN},
//			{.key = 'E', .value = BOLD_BLUE},
//			{.key = 'F', .value = BOLD_PURPLE},
//			{.key = 'G', .value = BOLD_CYAN},
//			{.key = 'H', .value = BOLD_LIGHT_GREY},
//			{.key = 'x', .value = ""}};
//	char set_of_colors[] = "exfxcxdxbxegedabagacad";
//}

void	print_fileinfo(t_fileinfo *finfo, t_spaces maxs, int g_flag/*, int color_flag*/)
{
	t_pattern	patterns[MAX_REPL_PATTERNS];
	char		spaces[COUNT_REGULAR_SPACES][254 + 1];
	char		pattern[1024] = {0};
//	char 		color_foreground[COUNT_OF_COLOR + 1] = {0};
//	char 		color_background[COUNT_OF_COLOR + 1] = {0};

	ft_bzero(spaces, COUNT_REGULAR_SPACES * (254 + 1) * sizeof(char));
	set_spaces(spaces, finfo, maxs);

//	if (color_flag == 1)
//	{
//		set_color(color_foreground);
//		set_color(color_background);
//	}


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
	add_pattern(&patterns[15], "{{color}}", "");
	add_pattern(&patterns[16], "{{filename}}", finfo->filename);
	add_pattern(&patterns[17], "{{reset_color}}", "");
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
