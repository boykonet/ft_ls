#include "../ls.h"

int	creadlink(const char *link, char file[255 + 1])
{
	if (link == NULL)
		return (-2);
	if (readlink(link, file, 255) < 0)
		return (-3);
	return (0);
}
