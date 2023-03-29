#include "../ls.h"

void	print_fileinfo(t_fileinfo *finfo, t_spaces maxs)
{
	char	spaces[LONG_FORNAT_PARRERN_MAXS][254 + 1];
	char	pattern[1024] = {0};

	ft_bzero(spaces, LONG_FORNAT_PARRERN_MAXS * (254 + 1) * sizeof(char));
	set_spaces(spaces, finfo, maxs);

	t_pattern	patterns[MAX_REPL_PATTERNS + 1] = {
			{.pattern = "{{filemode}}", .replacement = finfo->filemode},
			{.pattern = "{{s1}}", .replacement = spaces[0]},
			{.pattern = "{{nlinks}}", .replacement = finfo->nlinks},
			{.pattern = "{{s2}}", .replacement = spaces[1]},
			{.pattern = "{{oname}}", .replacement = finfo->oname},
			{.pattern = "{{s3}}", .replacement = spaces[2]},
			{.pattern = "{{gname}}", .replacement = finfo->gname},
			{.pattern = "{{s4}}", .replacement = spaces[3]},
			{.pattern = "{{nbytes}}", .replacement = finfo->nbytes},
			{.pattern = "{{amonth}}", .replacement = finfo->amonth},
			{.pattern = "{{s5}}", .replacement = spaces[4]},
			{.pattern = "{{day}}", .replacement = finfo->day_lm},
			{.pattern = "{{s6}}", .replacement = spaces[5]},
			{.pattern = "{{time_year}}", .replacement = finfo->time_year_lm},
			{.pattern = "{{filename}}", .replacement = finfo->filename},
			{.pattern = "{{link}}", .replacement = finfo->link}};

	if (finfo->type == S_IFLNK)
		replace_pattern(pattern, PATTERN_WITH_LINK, patterns);
	else
		replace_pattern(pattern, PATTERN_WITHOUT_LINK, patterns);

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
	return (i);
}

void	print_without_full_info(t_fileinfo **files)
{
	char	buf[255 + 1];
	int		largest;
	size_t	cos, i; // count of symbols

	largest = the_largest_filename(files);
	if (largest == 0)
		return ;
	cos = largest + (largest % 8) + (8 - (largest % 8));
	i = 0;
	while (files[i])
	{
		if (files[i + 1] == NULL)
			ft_putstr_fd(files[i]->filename, 1);
		else
		{
			ft_memset(buf, ' ', cos + 1);
			buf[cos] = '\0';
			ft_memcpy(buf, files[i]->filename, ft_strlen(files[i]->filename));
			ft_putstr_fd(buf, 1);
		}
		i++;
	}
	ft_putchar_fd('\n', 1);
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
	if (nn >= base)
		putnbr(nn / base, base, base_str);
	ft_putchar_fd(base_str[nn % base], 1);
}

void	print_total(long long total)
{
	ft_putstr_fd("total ", 1);
	putnbr(total, 10, "0123456789");
	ft_putchar_fd('\n', 1);
}

void	print_files_from_dirs(t_fileinfo **files, long long total, t_spaces maxs, int flag_l)
{
	size_t	i;

	i = 0;
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

void	print_files_from_files(t_fileinfo **files, t_spaces maxs, int flag_l)
{
	size_t	i;

	i = 0;
	if (flag_l == 0)
		print_without_full_info(files);
	else
	{
		while (files[i])
			print_fileinfo(files[i++], maxs);
	}
}
