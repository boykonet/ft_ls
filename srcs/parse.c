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
			{.flag = 't', .shift = T_FLAG_SHIFT, .shnum = T_FLAG_NUM},
			0,
	};

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

static int	parse_flags(char ***data, unsigned char *flags, t_list **patterns)
{
	char	*param;
	int 	errcode;

	if (data == NULL || flags == NULL || patterns == NULL)
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
				if (add_flag(flags, *param) == -1)
				{
					errcode = add_pattern(patterns, PATTERN_FLAG_NOT_SUPPORT, (char[2]){*param, '\0'});
					return (errcode != 0 ? errcode : -3);
				}
				param++;
			}
		} else
			break ;
		(*data)++;
	}
	return (0);
}

static int	parse_filenames(char **data, char ***filenames)
{
	if (!filenames || !data)
		return (-2);
	*filenames = copy_filenames(data);
	if (*filenames == NULL)
		return (-1);
	return (0);
}

static int	separate_filenames(char **filenames, char ***files, char ***dirs, int *count_possible_files_and_dirs)
{
	int		errcode;
	size_t	len, i;

	if (files == NULL || dirs == NULL || filenames == NULL || count_possible_files_and_dirs == NULL)
		return (-2);
	len = len_2array((const void**)filenames);
	i = 0;

	(*files) = ft_calloc(1, sizeof(char*));
	if (*files == NULL)
	{
		perror("malloc");
		exit(1);
	}
	*dirs = ft_calloc(1, sizeof(char*));
	if (*dirs == NULL)
	{
		perror("malloc");
		exit(1);
	}
	while (i < len)
	{
		errcode = if_dir_or_file(filenames[i]);
		if (errcode == 0) // directory
		{
			errcode = add_2array((void***)dirs, ft_strdup(filenames[i]));
			if (errcode != 0)
				return (errcode);
		}
		else if (errcode == 1) // files
		{
			errcode = add_2array((void***)files, ft_strdup(filenames[i]));
			if (errcode != 0)
				return (errcode);
		}
		else if (errcode < 0) // some unexpected error
		{
			char *s = ft_strjoin("ls: ", filenames[i]);
			perror(s);
			free(s);
			s = NULL;
			errno = 0;
		}
		*count_possible_files_and_dirs += 1;
		i++;
	}
	return (0);
}

void	parsing(t_ls *ls, char **data)
{
	char	**filenames;
	int		errcode;

	errcode = parse_flags(&data, &ls->flags, &ls->epatterns);
	handle_error(errcode, ls->epatterns);

	errcode = parse_filenames(data, &filenames);
	handle_error(errcode, ls->epatterns);

	errcode = separate_filenames(filenames, &ls->files, &ls->dirs, &ls->possible_files);
	free_2array((void**)filenames);
	handle_error(errcode, ls->epatterns);
}
