#include "../ls.h"

//static char	*join(char *flag)
//{
//	char	*ptr;
//
//	ptr = ft_calloc(ft_strlen(FLAG_NOT_SUPPORT_1) + 1 + ft_strlen(FLAG_NOT_SUPPORT_2) + 1, sizeof(char));
//	if (ptr == NULL)
//		return NULL;
//	ft_memcpy(&ptr[0], FLAG_NOT_SUPPORT_1, ft_strlen(FLAG_NOT_SUPPORT_1));
//	ft_memcpy(&ptr[0 + ft_strlen(FLAG_NOT_SUPPORT_1)], flag, 1);
//	ft_memcpy(&ptr[0 + ft_strlen(FLAG_NOT_SUPPORT_1) + 1], FLAG_NOT_SUPPORT_2, ft_strlen(FLAG_NOT_SUPPORT_2));
//	return (ptr);
//}

//static char	*flag_not_support(char flag)
//{
//	char	*ptr;
//	char	*f;
//
//	f = ft_calloc(2, sizeof(char));
//	if (f == NULL)
//		return (NULL);
//	f[0] = flag;
//	ptr = join(f);
//	if (ptr == NULL)
//	{
//		free(f);
//		return NULL;
//	}
//	return (ptr);
//}

char	*pattern(char *data, char *pattern, char *str)
{
	char	*res, *ptr;
	int		pbefore, pafter;
	char 	*p;

	ptr = ft_strnstr(data, pattern, ft_strlen(data));
	if (*ptr == '\0')
		return (NULL);
	pbefore = (int)(ptr - data);
	p = ptr + ft_strlen(pattern);
	pafter = (int)(ft_strlen(data) - (ptr - data));
	res = ft_calloc(pbefore + ft_strlen(str) + pafter, sizeof(char));
	if (!res)
	{
		eprinter(MALLOC_ERROR);
		return (NULL);
	}
	ft_strlcpy(res, data, pbefore);
	ft_strlcpy(res + pbefore, str, ft_strlen(str));
	ft_strlcpy(res + pbefore + ft_strlen(str), p, pafter);
	return (res);
}

void	cleaner(t_ls *ls, int exitcode)
{
	if (!ls || !exitcode)
		return ;
	clear_ls(ls);
	exit(exitcode);
}

