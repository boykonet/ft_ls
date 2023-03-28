#include "../ls.h"

int		eprinter(char *s)
{
	write(CSTDERR, s, ft_strlen(s));
	return (-1);
}

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

	write(1, pattern, ft_strlen(pattern));
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
		size_t	lfilename = ft_strlen(files[i]->filename);
		if (files[i + 1] == NULL)
		{
			write(1, files[i]->filename, lfilename);
		}
		else
		{
			ft_memset(buf, ' ', cos + 1);
			buf[cos] = '\0';
			ft_memcpy(buf, files[i]->filename, ft_strlen(files[i]->filename));
			write(1, buf, ft_strlen(buf));
		}
		i++;
	}
	write(1, "\n", 1);
}

void	print_total(long long total)
{
	char	*stotal = ft_itoa(total);
	if (stotal == NULL)
	{
		perror("malloc");
		exit(1);
	}
	write(1, "total ", 6);
	write(1, stotal, ft_strlen(stotal));
	free(stotal);
	stotal = NULL;
	write(1, "\n", 1);
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
