#include "../ls.h"

int	handle_recursive_flag(void *p)
{
	(void)p;
//	t_resource *res = (t_resource *)p;
//	printf("handle_recursive_flag %s\n", res->info->filename);
	return (0);
}


int	handle_a_flag(void *p)
{
	(void)p;
//	t_resource *res = (t_resource *)p;
//	printf("handle_a_flag %s\n", res->info->filename);
	return (0);
}

int	handle_l_flag(void *p)
{
	(void)p;
//	t_resource *res = (t_resource *)p;
//	printf("handle_l_flag %s\n", res->info->filename);
	return (0);
}

int	handle_r_flag(void *p)
{
	(void)p;
//	t_resource *res = (t_resource *)p;
//	printf("handle_r_flag %s\n", res->info->filename);
	return (0);
}

int	handle_t_flag(void *p)
{
	(void)p;
//	t_resource *res = (t_resource *)p;
//	printf("handle_t_flag %s\n", res->info->filename);
	return (0);
}

int is_recursive_flag(const char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'R')
			return (1);
		i++;
	}
	return (0);
}

void	del_recursive_flag(char **flags)
{
	int 	i;
	size_t	len;

	i = 0;
	if (flags == NULL)
		return ;
	len = ft_strlen(*flags);
	while (i < MAX_FLAGS)
	{
		if (*flags[i] == 'R')
		{
			*flags[i] = *flags[len - 1];
			*flags[len - 1] = '\0';
			return ;
		}
		i++;
	}
}

int	regular(const char **folders, t_list **epatterns)
{
	t_list	*listdirs;
	char	*emessage;
	int 	i, errcode;

	listdirs = NULL;
	emessage = NULL;
	i = 0;
	while (folders[i])
	{
		errcode = dir(&listdirs, folders[i++], &emessage);
		switch (errcode) {
			case 0:
				break ;
			case -4:
				errcode = add_pattern(epatterns, PATTERN_STRERROR_MESSAGE, emessage);
				if (errcode != 0)
					return (errcode);
				return (-4);
			default:
				return (errcode);
		}
	}
	return (0);
}

t_list *recursive(const char *folder)
{
	printf("recursive [%s]\n", folder);
	return (NULL);
}

/*
** -1 - malloc error
** 0 - OK
** 33...126 - flag not support and number is flag from ascii table (only for decimal)
*/
//int	e(char *flags, const char *folder)
//{
//	t_list		*res;
//	char		flag;
//	size_t		i, flen;
//	f			func[MAX_FLAGS] = {&handle_recursive_flag, &handle_a_flag, &handle_l_flag, &handle_r_flag, &handle_t_flag};
//
//	i = 0;
//	if (!is_recursive_flag(flags))
//		res = regular(folder, );
////	else
////		res = regular(folder);
//	del_recursive_flag(&flags);
//	flen = ft_strlen(flags);
//	while (i < flen)
//	{
//		flag = flags[i];
//		int j = 0;
//		while (j < MAX_FLAGS)
//		{
//			if (CONST_FLAGS[j] == flag)
//				func[j]((void*)res);
//			j++;
//		}
//		i++;
//	}
//	return (0);
//}

int	execute_files(char **files, unsigned char flags, t_list **epatterns)
{
	for (size_t i = 0; i < len_2array((const void**)files); i++)
		;
	return (0);
}

int	execute_dirs(char **dirs, unsigned char flags, t_list **epatterns, int possible_files)
{
	for (size_t i = 0; i < len_2array((const void**)dirs); i++)
		rec_dirs(dirs[i], flags, 0, possible_files);
	return (0);
}

int	execute(t_ls *ls)
{
	size_t	i, dlen, flen;

	flen = len_2array((const void **) ls->files);
	dlen = len_2array((const void **) ls->dirs);
	i = 0;
	while (i < flen)
	{
//		err = e(ls->flags, ls->dirs[i]);
//		if (!err)
//		{
//			;
//		}
		i++;
	}
	i = 0;
	while (i < dlen)
	{
		i++;
	}
	return (0);
}

