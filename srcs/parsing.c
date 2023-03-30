#include "../ls.h"

static char	**copy_filenames(char **data)
{
	char	**filenames;
	char	*base_dirs[2] = {".", NULL};

	// If no filenames, returns NULL in each case
	if (len_2array((const void**)data) > 0)
		filenames = copy((const char**)data, len_2array((const void **) data));
	else
		filenames = copy((const char**)base_dirs, len_2array((const void **) base_dirs));
	return (filenames);
}

/*   second 4 bytes        first 4 bytes
**   0 |  0 |  0 |  0  ||  0 | 0 | 0 | 0
**   R |  a |  l |  r  ||  t | - | - | -
**   7 |  6 |  5 |  4  ||  3 | 2 | 1 | 0
** 128 | 64 | 32 | 16  ||  8 | 4 | 2 | 1
*/
void	set_flag(unsigned char *flags, int shift, int num)
{
	if (((*flags) & (1 << shift)) != num)
		(*flags) |= (1 << shift);
}

int		is_flag(unsigned char flags, int shift, int num)
{
	if ((flags & (1 << shift)) == num)
		return (1);
	return (0);
}

int		add_flag(unsigned char *flags, char nf)
{
	size_t	i;
	t_flags f[MAX_FLAGS + 1] = {
			{.flag = 'R', .shift = REC_FLAG_SHIFT, .shnum = REC_FLAG_NUM},
			{.flag = 'a', .shift = A_FLAG_SHIFT, .shnum = A_FLAG_NUM},
			{.flag = 'l', .shift = L_FLAG_SHIFT, .shnum = L_FLAG_NUM},
			{.flag = 'r', .shift = R_FLAG_SHIFT, .shnum = R_FLAG_NUM},
			{.flag = 't', .shift = T_FLAG_SHIFT, .shnum = T_FLAG_NUM}};

	i = 0;
	while (i < MAX_FLAGS)
	{
		if (f[i].flag == nf)
		{
			set_flag(flags, f[i].shift, f[i].shnum);
			return (0);
		}
		i++;
	}
	return (-1);
}

static int	parse_flags(char ***data, unsigned char *flags, t_pattern p[1])
{
	char	*param;
	int 	ecode;

	if (data == NULL || flags == NULL)
		return (-2);
	if (len_2array((const void**)(*data)) == 0)
		return (0);
	while (*data != NULL && **data != NULL)
	{
		param = **data;
		if (*param == '-')
		{
			param++;
			while (*param != '\0')
			{
				ecode = add_flag(flags, *param);
				if (ecode == -1)
				{
					add_pattern(p, "{{flag}}", (char[2]){*param, '\0'});
					return (-4);
				}
				param++;
			}
		} else
			break ;
		(*data)++;
	}
	return (0);
}

static int	parse_filenames(char **data, char ***filenames, t_pattern p[1])
{
	if (!filenames || !data)
		return (-2);
	*filenames = copy_filenames(data);
	if (*filenames == NULL)
	{
		add_pattern(p, PATTERN_MALLOC_ERROR, strerror(errno));
		return (-1);
	}
	return (0);
}

static int	separate_filenames(char **filenames, char ***files, char ***dirs, int *count_possible_files_and_dirs, t_pattern p[1])
{
	int		errcode, a2ecode;
	size_t	len, i;

	if (files == NULL || dirs == NULL || filenames == NULL || count_possible_files_and_dirs == NULL)
		return (-2);
	len = len_2array((const void **)filenames);
	i = 0;
	while (i < len)
	{
		errcode = if_dir_or_file(filenames[i]);
		if (errcode == 0) // directory
			a2ecode = add_2array((void***)dirs, filenames[i]);
		else if (errcode == 1) // files
			a2ecode = add_2array((void***)files, filenames[i]);
		else if (errcode < 0) // some unexpected error
		{
			add_pattern(p, PATTERN_STRERROR_MESSAGE, strerror(errno));
			return (-3);
		}
		if (a2ecode != 0)
		{
			if (a2ecode == -1)
				add_pattern(p, PATTERN_MALLOC_ERROR, strerror(errno));
			return (a2ecode);
		}
		*count_possible_files_and_dirs += 1;
		i++;
	}
	return (0);
}

void	parsing(t_ls *ls, char **data)
{
	char	**filenames;
	int 	ecode;

	ecode = parse_flags(&data, &ls->flags, ls->epatterns);
	if (handle_error(ecode, ls->epatterns) == -1)
		cleaner(ls, 1);

	ecode = parse_filenames(data, &filenames, ls->epatterns);
	if (handle_error(ecode, ls->epatterns) == -1)
		cleaner(ls, 1);

	ecode = separate_filenames(filenames, &ls->files, &ls->dirs, &ls->possible_files, ls->epatterns);
	free_2array((void**)filenames);
	if (handle_error(ecode, ls->epatterns) == -1)
		cleaner(ls, 1);
}
