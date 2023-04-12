#include "../ls.h"

void	print_fileinfo(t_fileinfo *finfo, t_spaces maxs)
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


	if (finfo->type == S_IFLNK)
		replace_pattern(pattern, PATTERN_WITH_LINK, patterns, MAX_REPL_PATTERNS);
	else
		replace_pattern(pattern, PATTERN_WITHOUT_LINK, patterns, 15);

	ft_putstr_fd(pattern, 1);
}

int 	the_largest_filename(t_fileinfo **files)
{
	size_t	max, i, clen;

	max = 0;
	if (files == NULL)
		return (0);
	i = 0;
	while (files[i])
	{
		clen = ft_strlen(files[i]->filename); // current len
		if (max < clen)
			max = clen;
		i++;
	}
	return (max);
}

//void	print_without_full_info(t_fileinfo **files)
//{
//	char	buf[255 + 1];
//	int		largest;
//	size_t	cos, i; // count of symbols
//
//	largest = the_largest_filename(files);
//	if (largest == 0)
//		return ;
//	cos = ((largest / 8) + 1) * 8;
//	i = 0;
//	while (files[i])
//	{
//		if (files[i + 1] == NULL)
//			ft_putstr_fd(files[i]->filename, 1);
//		else
//		{
//			ft_memset(buf, ' ', cos + 1);
//			buf[cos] = '\0';
//			ft_memcpy(buf, files[i]->filename, ft_strlen(files[i]->filename));
//			ft_putstr_fd(buf, 1);
//		}
//		i++;
//	}
//	ft_putchar_fd('\n', 1);
//}

void	print_without_full_info(t_fileinfo **files)
{
	size_t	i;

	i = 0;
	while (files[i])
		ft_putendl_fd(files[i++]->filename, 1);
}

void	putnbr(long long number, int base, char *base_str)
{
	unsigned long long nn;

	nn = number;
	if (number < 0)
	{
		ft_putchar_fd('-', 1);
		nn = number * (-1);
	}
	if (nn >= (unsigned long long)base)
		putnbr(nn / base, base, base_str);
	ft_putchar_fd(base_str[nn % base], 1);
}

void	print_total(long long total)
{
	ft_putstr_fd("total ", 1);
	putnbr(total, 10, DECIMAL_BASE_STR);
	ft_putchar_fd('\n', 1);
}

void	print_files_from_dirs(t_fileinfo **files, long long total, int flag_l)
{
	t_spaces	maxs;
	size_t		i;

	i = 0;
	if (files == NULL)
		return ;
	ispaces(&maxs);
	counter_of_spaces(files, &maxs);

	if (flag_l == 1 && len_2array((const void**)files) > 0)
		print_total(total);

	if (flag_l == 0)
		print_without_full_info(files);
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs);
	}
}

void	print_files_from_files(t_fileinfo **files, int flag_l)
{
	t_spaces	maxs;
	size_t	i;

	i = 0;
	if (files == NULL)
		return ;
	ispaces(&maxs);
	counter_of_spaces(files, &maxs);
	if (flag_l == 0)
		print_without_full_info(files);
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs);
	}
}
