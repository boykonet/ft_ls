#include "../ls.h"

static char	**copy_filenames(char **data)
{
	char	**filenames;
	char	*base_dirs[2] = {".", NULL};

	/* If no filenames, returns NULL in each case */
	if (len_2array((const void**)data) > 0)
		filenames = copy((const char**)data, len_2array((const void **) data));
	else
		filenames = copy((const char**)base_dirs, len_2array((const void **) base_dirs));
	return (filenames);
}

/*            second 4 bytes        first 4 bytes
** bits   |   1 |  1 |  1 |  1  ||  1 | 1 | 0 | 0
** flag   |   R |  a |  l |  r  ||  t | d | - | -
** shift  |   7 |  6 |  5 |  4  ||  3 | 2 | 1 | 0
** number | 128 | 64 | 32 | 16  ||  8 | 4 | 2 | 1
*/
static void	set_flag(unsigned char *flags, int shift, int num)
{
	if (((*flags) & (1 << shift)) != num)
		(*flags) |= (1 << shift);
}

int		is_flag(unsigned char flags, int shift, int num)
{
//	t_flags f[MAX_FLAGS + 1] = {
//			{.flag = REC_FLAG, .shift = REC_FLAG_SHIFT, .shnum = REC_FLAG_NUM},
//			{.flag = A_FLAG, .shift = A_FLAG_SHIFT, .shnum = A_FLAG_NUM},
//			{.flag = L_FLAG, .shift = L_FLAG_SHIFT, .shnum = L_FLAG_NUM},
//			{.flag = R_FLAG, .shift = R_FLAG_SHIFT, .shnum = R_FLAG_NUM},
//			{.flag = T_FLAG, .shift = T_FLAG_SHIFT, .shnum = T_FLAG_NUM},
//			{.flag = D_FLAG, .shift = D_FLAG_SHIFT, .shnum = D_FLAG_NUM}};


	if ((flags & (1 << shift)) == num)
		return (1);
	return (0);
}

int		add_flag(unsigned char *flags, char nf)
{
	size_t	i;
	t_flags f[MAX_FLAGS + 1] = {
			{.flag = REC_FLAG, .shift = REC_FLAG_SHIFT, .shnum = REC_FLAG_NUM},
			{.flag = A_FLAG, .shift = A_FLAG_SHIFT, .shnum = A_FLAG_NUM},
			{.flag = L_FLAG, .shift = L_FLAG_SHIFT, .shnum = L_FLAG_NUM},
			{.flag = R_FLAG, .shift = R_FLAG_SHIFT, .shnum = R_FLAG_NUM},
			{.flag = T_FLAG, .shift = T_FLAG_SHIFT, .shnum = T_FLAG_NUM},
			{.flag = D_FLAG, .shift = D_FLAG_SHIFT, .shnum = D_FLAG_NUM}};

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

static int	parse_flags(char ***data, unsigned char *flags, t_pattern p[MAX_ERROR_PATTERNS])
{
	char	*param;
	int 	ecode;

	if (data == NULL || flags == NULL)
		return (ERR_CODE_NULL_PARAMETER);
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
					add_pattern(p, PATTERN_FLAG_NOT_SUPPORT, (char[2]){*param, '\0'});
					return (ERR_CODE_FLAG_NOT_SUPPORT);
				}
				param++;
			}
		} else
			break ;
		(*data)++;
	}
	return (0);
}

static int	parse_filenames(char **data, char ***filenames, t_pattern p[MAX_ERROR_PATTERNS])
{
	if (!filenames || !data)
		return (ERR_CODE_NULL_PARAMETER);
	*filenames = copy_filenames(data);
	if (*filenames == NULL)
	{
		add_pattern(p, PATTERN_MALLOC_ERROR, strerror(errno));
		return (ERR_CODE_MALLOC_ERROR);
	}
	return (0);
}

int	sort_by_dir_or_file(char ***dirs, char ***files, char *filename, int d_flag)
{
	int 	ecode, a2ecode;
	char	*cfilename;

	a2ecode = 0;
	cfilename = ft_strdup(filename);
	if (cfilename == NULL)
		return (ERR_CODE_MALLOC_ERROR);
	ecode = if_dir_or_file(filename);
	if (ecode == 0 && d_flag == 1)
		ecode = 1;
	if (ecode == 0) /* directory */
		a2ecode = add_2array((void ***)dirs, cfilename);
	else if (ecode == 1) /* files */
		a2ecode = add_2array((void ***)files, cfilename);
	else if (ecode < 0) /* some unexpected error */
	{
		free(cfilename);
		cfilename = NULL;
		return (ERR_CODE_FILE_ERROR);
	}
	if (a2ecode != 0)
	{
		free(cfilename);
		cfilename = NULL;
	}
	return (a2ecode);
}

static int	separate_filenames(char ***filenames, char ***files, char ***dirs, int *count_possible_files_and_dirs, unsigned char flags, t_pattern p[MAX_ERROR_PATTERNS])
{
	int		a2ecode;

	if (files == NULL || dirs == NULL || filenames == NULL || count_possible_files_and_dirs == NULL)
		return (ERR_CODE_NULL_PARAMETER);
	while (*filenames && **filenames)
	{
		*count_possible_files_and_dirs += 1;
		a2ecode = sort_by_dir_or_file(dirs, files, *(*filenames), is_flag(flags, D_FLAG_SHIFT, D_FLAG_NUM));
		if (a2ecode != 0)
		{
			handle_ecodes(a2ecode, **filenames, p);
			return (a2ecode);
		}
		(*filenames)++;
	}
	return (0);
}

void	ehandler_filenames(char **filenames, t_ls *ls, int (*func)(char***, char***, char***, int*, unsigned char, t_pattern[MAX_ERROR_PATTERNS]))
{
	char **f;
	int 	ecode;

	f = filenames;
	while (f && *f)
	{
		ecode = func(&f, &ls->files, &ls->dirs, &ls->possible_files, ls->flags, ls->epatterns);
		if (ecode != 0)
		{
			handle_error(ecode, ls->epatterns, &ls->global_ecode);
			f++;
		}
	}
}

void	parsing(t_ls *ls, char **data)
{
	char	**filenames;
	int 	ecode;

	ecode = parse_flags(&data, &ls->flags, ls->epatterns);
	if (handle_error(ecode, ls->epatterns, NULL) == -1)
		cleaner(ls, 1);

	ecode = parse_filenames(data, &filenames, ls->epatterns);
	if (handle_error(ecode, ls->epatterns, NULL) == -1)
		cleaner(ls, 1);

	ehandler_filenames(filenames, ls, separate_filenames);
	free_2array((void**)filenames);
	filenames = NULL;
}
