#include "../ls.h"

char	*creadlink(const char *link)
{
	char	file[255 + 1];

	ft_bzero(file, sizeof(file));
	if (readlink(link, file, sizeof(file)) < 0)
	{
		perror("readlink"); // TODO: remove
		return (NULL);
	}
	return (ft_strdup(file));
}
