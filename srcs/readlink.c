#include "../ls.h"

char	*creadlink(char *link)
{
	char	*file;

	file = ft_calloc(100, sizeof(char));
	if (file == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	if (readlink(link, file, sizeof(file)) < 0)
	{
		perror("readlink");
		return (NULL);
	}
	return (file);
}
