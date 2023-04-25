#include "../ls.h"

void	print_fileinfo(t_fileinfo *finfo, t_spaces maxs, int g_flag)
{
	t_pattern	patterns[MAX_REPL_PATTERNS];
	char		spaces[LONG_FORNAT_PARRERN_MAXS][254 + 1];
	char		pattern[1024] = {0};

	ft_bzero(spaces, LONG_FORNAT_PARRERN_MAXS * (254 + 1) * sizeof(char));
	set_spaces(spaces, finfo, maxs);

	add_pattern(&patterns[0], "{{filemode}}", finfo->filemode);
	add_pattern(&patterns[1], "{{s1}}", spaces[0]);
	add_pattern(&patterns[2], "{{nlinks}}", finfo->nlinks);
	add_pattern(&patterns[3], "{{s2}}", spaces[1]);
	add_pattern(&patterns[4], "{{oname}}", finfo->oname);
	add_pattern(&patterns[5], "{{s3}}", spaces[2]);
	add_pattern(&patterns[6], "{{gname}}", finfo->gname);
	add_pattern(&patterns[7], "{{s4}}", spaces[3]);
	add_pattern(&patterns[8], "{{nbytes}}", finfo->nbytes);
	add_pattern(&patterns[9], "{{amonth}}", finfo->amonth);
	add_pattern(&patterns[10], "{{s5}}", spaces[4]);
	add_pattern(&patterns[11], "{{day}}", finfo->day_lm);
	add_pattern(&patterns[12], "{{s6}}", spaces[5]);
	add_pattern(&patterns[13], "{{time_year}}", finfo->time_year_lm);
	add_pattern(&patterns[14], "{{filename}}", finfo->filename);
	add_pattern(&patterns[15], "{{link}}", finfo->link);

	if (g_flag == 0)
	{
		if (finfo->type == S_IFLNK)
			replace_pattern(pattern, PATTERN_WITH_LINK, patterns, MAX_REPL_PATTERNS);
		else
			replace_pattern(pattern, PATTERN_WITHOUT_LINK, patterns, 15);
	}
	else
	{
		if (finfo->type == S_IFLNK)
			replace_pattern(pattern, PATTERN_WITH_LINK_GROUP_NAME, patterns, MAX_REPL_PATTERNS);
		else
			replace_pattern(pattern, PATTERN_WITHOUT_LINK_GROUP_NAME, patterns, 15);
	}
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
			print_fileinfo(files[i++], maxs, is_flag(flags, G_FLAG_SHIFT, G_FLAG_VALUE));
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
			print_fileinfo(files[i++], maxs, is_flag(flags, G_FLAG_SHIFT, G_FLAG_VALUE));
	}
}
