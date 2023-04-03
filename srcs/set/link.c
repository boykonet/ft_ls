#include "../../ls.h"

int set_link(const char *filepath, char *link)
{
	int	ecode;

	if (filepath == NULL)
		return (-2);
	ecode = creadlink(filepath, link);
	if (ecode != 0)
		return (ecode);
	return (0);
}