#include "../ls.h"

//static int	is_flag_support(const char *cflags, char flag)
//{
//	int i;
//
//	i = 0;
//	while (i < MAX_FLAGS)
//	{
//		if (cflags[i++] == flag)
//			return (1);
//	}
//	return (0);
//}

//static void	add_flag(char flags[MAX_FLAGS + 1], char new_flag)
//{
//	int i;
//
//	i = 0;
//	while (flags[i] != '\0')
//	{
//		if (flags[i] == new_flag)
//			return ;
//		i++;
//	}
//	if (i == MAX_FLAGS)
//		return ;
//	flags[i] = new_flag;
//}

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
	if ((*flags & (1 << shift)) != num)
		*flags |= (1 << shift);
}

int		add_flag(unsigned char *flags, char nf)
{
	size_t	i;
	t_flags f[MAX_FLAGS + 1] = {
			{.flag = 'R', .shift = 7, .shnum = 128},
			{.flag = 'a', .shift = 6, .shnum = 64},
			{.flag = 'l', .shift = 5, .shnum = 32},
			{.flag = 'r', .shift = 4, .shnum = 16},
			{.flag = 't', .shift = 3, .shnum = 8},
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

int		parse_flags(char ***data, unsigned char *flags, t_list **patterns)
{
	char	*param;
	int 	errcode;

	if (data == NULL || flags == NULL || patterns == NULL)
		return (-2);
	if (len_2array((const void**)*data) == 0)
		return (0);
	while (*data)
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

int		parse_filenames(char **data, char ***filenames)
{
	if (!filenames || !data)
		return (-2);
	*filenames = copy_filenames(data);
	if (*filenames == NULL)
		return (-1);
	return (0);
}
