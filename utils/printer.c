#include "../ls.h"

int		eprinter(char *s)
{
	write(CSTDERR, s, ft_strlen(s));
	return (-1);
}
