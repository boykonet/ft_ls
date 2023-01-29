#include "../ls.h"

# define FLAG_NOT_SUPPORT_1 "ls: illegal option -- "
# define FLAG_NOT_SUPPORT_2 "\nusage: ls [-Ralrt] [file ...]\n"
# define UNSUPPORTED_ASCII	"ls: unsupported symbol: only ascii printable characters\n"

# define MALLOC_ERROR	"malloc error\n"

static char	*join(char *flag)
{
	char	*ptr;

	ptr = ft_calloc(ft_strlen(FLAG_NOT_SUPPORT_1) + 1 + ft_strlen(FLAG_NOT_SUPPORT_2) + 1, sizeof(char));
	if (ptr == NULL)
		return NULL;
	ft_memcpy(&ptr[0], FLAG_NOT_SUPPORT_1, ft_strlen(FLAG_NOT_SUPPORT_1));
	ft_memcpy(&ptr[0 + ft_strlen(FLAG_NOT_SUPPORT_1)], flag, 1);
	ft_memcpy(&ptr[0 + ft_strlen(FLAG_NOT_SUPPORT_1) + 1], FLAG_NOT_SUPPORT_2, ft_strlen(FLAG_NOT_SUPPORT_2));
	return (ptr);
}

static char	*flag_not_support(char flag)
{
	char	*ptr;
	char	*f;

	f = ft_calloc(2, sizeof(char));
	if (f == NULL)
		return (NULL);
	f[0] = flag;
	ptr = join(f);
	if (ptr == NULL)
	{
		free(f);
		return NULL;
	}
	return (ptr);
}

char *unsupported_symbol()
{
	return ft_strdup(UNSUPPORTED_ASCII);
}

void	err_printer_and_cleaner(t_ls *ls, int errcode, int exitcode)
{
	char *message;

	if (!errcode)
		return ;
	if (errcode == -1)
		message = ft_strdup(MALLOC_ERROR);
	else if (ft_isprint((char)errcode))
		message = flag_not_support((char)errcode);
	else
		message = unsupported_symbol();
	if (message == NULL)
	{
		write(CSTDERR, MALLOC_ERROR, ft_strlen(MALLOC_ERROR));
		clear_ls(ls);
		exit(1);
	}
	write(CSTDERR, message, ft_strlen(message));
	free(message);
	clear_ls(ls);
	exit(exitcode);
}

