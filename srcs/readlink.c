#include "../ls.h"

int	creadlink(const char *link, char file[STRING_SIZE + 1])
{
	if (link == NULL)
		return (ERR_CODE_NULL_PARAMETER);
	if (readlink(link, file, STRING_SIZE) < 0)
		return (ERR_CODE_STRERROR);
	return (0);
}
