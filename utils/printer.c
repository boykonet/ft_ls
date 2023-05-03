#include "../ls.h"

void	print_fileinfo(t_fileinfo *finfo, t_spaces maxs, int g_flag, int color_flag)
{
	t_pattern	patterns[MAX_REPL_PATTERNS];
	char		spaces[COUNT_REGULAR_SPACES][254 + 1];
	char		pattern[1024];
	char 		color[11 + 1];
	char		reset_color[5 + 1];

	ft_bzero(color, sizeof(color));
	ft_bzero(reset_color, sizeof(reset_color));
	ft_bzero(spaces, COUNT_REGULAR_SPACES * (254 + 1) * sizeof(char));
	ft_bzero(patterns, sizeof(patterns));
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
		add_pattern(&patterns[3], "{{s2}}", EMPTY);
		add_pattern(&patterns[4], "{{oname}}", EMPTY);
		add_pattern(&patterns[5], "{{two_spaces}}", EMPTY);
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
		replace_pattern(pattern, WITH_LINK, patterns, MAX_REPL_PATTERNS);
	else
		replace_pattern(pattern, WITHOUT_LINK, patterns, MAX_REPL_PATTERNS - 1);
	ft_putendl_fd(pattern, 1);
}

void	print_without_full_info(t_fileinfo **files, int color_flag)
{
	size_t		i;
	char 		color[11 + 1];
	char		reset_color[5 + 1];
	char		pattern[255 + 11 + 5 + 1];
	t_pattern	p[3 + 1];

	if (files == NULL)
		return ;
	i = 0;
	while (files[i])
	{
		ft_bzero(p, sizeof(p));
		ft_bzero(pattern, sizeof(pattern));
		ft_bzero(color, sizeof(color));
		ft_bzero(reset_color, sizeof(reset_color));
		if (color_flag == 1 && files[i]->color_type != 0)
		{
			set_color(files[i]->color_type, color);
			ft_memcpy(reset_color, RESET_COLOR, ft_strlen(RESET_COLOR));
		}
		add_pattern(&p[0], "{{color}}", color);
		add_pattern(&p[1], "{{reset_color}}", reset_color);
		add_pattern(&p[2], "{{filename}}", files[i]->filename);
		replace_pattern(pattern, SHORT_FILE_INFO, p, 3);
		ft_putendl_fd(pattern, 1);
		i++;
	}
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
		print_without_full_info(files, is_flag(flags, COLOR_FLAG_SHIFT, COLOR_FLAG_VALUE));
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs, is_flag(flags, G_FLAG_SHIFT, G_FLAG_VALUE), is_flag(flags, COLOR_FLAG_SHIFT, COLOR_FLAG_VALUE));
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
		print_without_full_info(files, is_flag(flags, COLOR_FLAG_SHIFT, COLOR_FLAG_VALUE));
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs, is_flag(flags, G_FLAG_SHIFT, G_FLAG_VALUE), is_flag(flags, COLOR_FLAG_SHIFT, COLOR_FLAG_VALUE));
	}
}
