#include "../ls.h"

# define FLAG_NOT_SUPPORT_1 "ls: illegal option -- "
# define FLAG_NOT_SUPPORT_2 "\nusage: ls [-Ralrt] [file ...]\n"

# define MALLOC_ERROR	"malloc error\n"

static char	*flag_not_support(char flag)
{
	size_t	cbytes;
	char	*ptr;
	size_t	lfns1;
	size_t	lfns2;

	cbytes = 0;
	lfns1 = ft_strlen(FLAG_NOT_SUPPORT_1);
	lfns2 = ft_strlen(FLAG_NOT_SUPPORT_2);
	ptr = ft_calloc(sizeof(char), lfns1 + 1 + lfns2 + 1);
	if (ptr == NULL)
		return ft_strdup(MALLOC_ERROR);
	cbytes += ft_strlcpy(&ptr[cbytes], FLAG_NOT_SUPPORT_1, lfns1);
	cbytes += ft_strlcpy(&ptr[cbytes], &flag, 1);
	cbytes += ft_strlcpy(&ptr[cbytes], FLAG_NOT_SUPPORT_2, lfns2);
	return (ptr);
}

void	err_printer_and_cleaner(t_ls *ls, int errcode, int exitcode)
{
	char *message;

	if (!errcode)
		return ;
	switch (errcode) {
		case -1:
			message = ft_strdup(MALLOC_ERROR);
		default:
			message = flag_not_support(errcode);
	}
	write(CSTDERR, message, ft_strlen(message));
	free(message);
	clear_ls(ls);
	exit(exitcode);
}

