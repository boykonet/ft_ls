#include "../ls.h"

int	handle_recursive_flag(void *p)
{
	t_resource *res = (t_resource *)p;
	printf("handle_recursive_flag %s\n", res->info->name);
	return (0);
}


int	handle_a_flag(void *p)
{
	t_resource *res = (t_resource *)p;
	printf("handle_a_flag %s\n", res->info->name);
	return (0);
}

int	handle_l_flag(void *p)
{
	t_resource *res = (t_resource *)p;
	printf("handle_l_flag %s\n", res->info->name);
	return (0);
}

int	handle_r_flag(void *p)
{
	t_resource *res = (t_resource *)p;
	printf("handle_r_flag %s\n", res->info->name);
	return (0);
}

int	handle_t_flag(void *p)
{
	t_resource *res = (t_resource *)p;
	printf("handle_t_flag %s\n", res->info->name);
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

//int	if_not_dirs_or_dot(char *dir)
//{
//	if (dir == NULL)
//		return (1);
//	if (ft_strncmp(dir, ".", ft_strlen(dir)) == 0)
//		return (1);
//	return (0);
//}

t_list *recursive(const char *folder)
{
	printf("recursive [%s]\n", folder);
	return (NULL);
}

t_list *regular(const char *folder)
{
	printf("regular [%s]\n", folder);
	return (NULL);
}

/*
** -1 - malloc error
** 0 - OK
** 33...126 - flag not support and number is flag from ascii table (only for decimal)
*/
int	e(char *flags, const char *folder)
{
	t_list		*res;
	char		flag;
	size_t		i, flen;
	f			func[MAX_FLAGS] = {&handle_recursive_flag, &handle_a_flag, &handle_l_flag, &handle_r_flag, &handle_t_flag};

	i = 0;
	if (is_recursive_flag(flags))
		res = recursive(folder);
	else
		res = regular(folder);
	del_recursive_flag(&flags);
	flen = ft_strlen(flags);
	while (i < flen)
	{
		flag = flags[i];
		int j = 0;
		while (j < MAX_FLAGS)
		{
			if (CONST_FLAGS[j] == flag)
				func[j]((void*)res);
			j++;
		}
		i++;
	}
	return (0);
}

int	execute(t_ls *ls)
{
	size_t	i, flen;
//	int	err;

	flen = len_double_char_array((const char**)ls->files);
	if (flen == 0)
	{
		e(ls->flags, ".");
	}
	else
	{
		i = 0;
		while (i < flen)
		{
//			err = e(ls->flags, ls->files[i]);
//			if (!err)
//			{
//				;
//			}
			i++;
		}

	}
	return (0);
}

