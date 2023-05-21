/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/21 16:08:37 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/21 16:08:37 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	init_patterns(t_pattern *p, t_fileinfo *finfo, char color[11 + 1], char reset_color[5 + 1], int g_flag, t_spaces maxs)
{
	char	spaces[COUNT_REGULAR_SPACES][254 + 1];

	ft_bzero(spaces, COUNT_REGULAR_SPACES * (254 + 1) * sizeof(char));
	set_spaces(spaces, finfo, maxs);
	add_pattern(&p[0], "{{filemode}}", finfo->filemode);
	add_pattern(&p[1], "{{s1}}", spaces[0]);
	add_pattern(&p[2], "{{nlinks}}", finfo->nlinks);
	if (g_flag == 0)
	{
		add_pattern(&p[3], "{{s2}}", spaces[1]);
		add_pattern(&p[4], "{{oname}}", finfo->oname);
		add_pattern(&p[5], "{{two_spaces}}", "  ");
	}
	else
	{
		add_pattern(&p[3], "{{s2}}", EMPTY);
		add_pattern(&p[4], "{{oname}}", EMPTY);
		add_pattern(&p[5], "{{two_spaces}}", EMPTY);
	}
	add_pattern(&p[6], "{{s3}}", spaces[2]);
	add_pattern(&p[7], "{{gname}}", finfo->gname);
	add_pattern(&p[8], "{{s4}}", spaces[3]);
	add_pattern(&p[9], "{{nbytes}}", finfo->nbytes);
	add_pattern(&p[10], "{{amonth}}", finfo->amonth);
	add_pattern(&p[11], "{{s5}}", spaces[4]);
	add_pattern(&p[12], "{{day}}", finfo->day_lm);
	add_pattern(&p[13], "{{s6}}", spaces[5]);
	add_pattern(&p[14], "{{time_year}}", finfo->time_year_lm);
	add_pattern(&p[15], "{{color}}", color);
	add_pattern(&p[16], "{{filename}}", finfo->filename);
	add_pattern(&p[17], "{{reset_color}}", reset_color);
	add_pattern(&p[18], "{{link}}", finfo->link);
}

void	print_fileinfo(t_fileinfo *finfo, t_spaces maxs, int g_flag, int color_flag, char colors[23])
{
	t_pattern	patterns[MAX_REPL_PATTERNS];
	char		result[1024];
	char 		color[11 + 1];
	char		reset_color[5 + 1];

	ft_bzero(color, sizeof(color));
	ft_bzero(reset_color, sizeof(reset_color));
	ft_bzero(patterns, sizeof(patterns));
	ft_bzero(result, sizeof(result));
	set_color(finfo->color_type, color, colors);
	ft_memcpy(reset_color, RESET_COLOR, ft_strlen(RESET_COLOR));
	init_patterns(patterns, finfo, color, reset_color, g_flag, maxs);
	if (color_flag == 1 && cisatty(STDOUT_FILENO) == 1)
	{
		if (finfo->type == S_IFLNK)
			replace_pattern(result, WITH_LINK_COLOR, patterns, MAX_REPL_PATTERNS);
		else
			replace_pattern(result, WITHOUT_LINK_COLOR, patterns, MAX_REPL_PATTERNS - 1);
	}
	else
	{
		if (finfo->type == S_IFLNK)
			replace_pattern(result, WITH_LINK, patterns, MAX_REPL_PATTERNS);
		else
			replace_pattern(result, WITHOUT_LINK, patterns, MAX_REPL_PATTERNS - 1);
	}
	ft_putendl_fd(result, 1);
}

void	print_without_full_info(t_fileinfo **files, int color_flag, char colors[23])
{
	size_t		i;
	char 		color[11 + 1], reset_color[5 + 1];
	char		result[255 + 11 + 5 + 1];
	t_pattern	p[3 + 1];

	if (files == NULL)
		return ;
	i = 0;
	while (files[i])
	{
		ft_bzero(p, sizeof(p));
		ft_bzero(result, sizeof(result));
		ft_bzero(color, sizeof(color));
		ft_bzero(reset_color, sizeof(reset_color));
		set_color(files[i]->color_type, color, colors);
		ft_memcpy(reset_color, RESET_COLOR, ft_strlen(RESET_COLOR));
		add_pattern(&p[0], "{{color}}", color);
		add_pattern(&p[1], "{{reset_color}}", reset_color);
		add_pattern(&p[2], "{{filename}}", files[i]->filename);
		if (color_flag == 1 && cisatty(STDOUT_FILENO) == 1)
			replace_pattern(result, SHORT_FILE_INFO_COLOR, p, 3);
		else
			replace_pattern(result, SHORT_FILE_INFO, p, 3);
		ft_putendl_fd(result, 1);
		i++;
	}
}

void	print_total(long long total)
{
	ft_putstr_fd("total ", 1);
	putnbr(total, 10, DECIMAL_BASE_STR);
	ft_putchar_fd('\n', 1);
}

void	print_files_from_dirs(t_fileinfo **files, long long total, unsigned short flags, char colors[23])
{
	t_spaces	maxs;
	size_t		i;

	i = 0;
	if (files == NULL)
		return ;
	ispaces(&maxs);
	counter_of_spaces(files, &maxs);

	if (is_flag(flags, L_FLAG) == 1 && len_2array((const void**)files) > 0)
		print_total(total);

	if (is_flag(flags, L_FLAG) == 0)
		print_without_full_info(files, is_flag(flags, COLOR_FLAG), colors);
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs, is_flag(flags, G_FLAG), is_flag(flags, COLOR_FLAG), colors);
	}
}

void	print_files_from_files(t_fileinfo **files, unsigned short flags, char colors[23])
{
	t_spaces	maxs;
	size_t	i;

	i = 0;
	if (files == NULL)
		return ;
	ispaces(&maxs);
	counter_of_spaces(files, &maxs);
	if (is_flag(flags, L_FLAG) == 0)
		print_without_full_info(files, is_flag(flags, COLOR_FLAG), colors);
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs, is_flag(flags, G_FLAG), is_flag(flags, COLOR_FLAG), colors);
	}
}
