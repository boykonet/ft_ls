#include "../ls.h"

t_fileinfo	*new_fileinfo(char *path, char *filename, int type)
{
	t_fileinfo *f;

	f = ft_calloc(1, sizeof(t_fileinfo));
	if (!f)
		return (NULL);
	ft_memcpy(f->path, path, ft_strlen(path));
	ft_memcpy(f->filename, filename, ft_strlen(filename));
	f->type = type;
	ft_memcpy(f->filemode, "---------- ", 11);
	return (f);
}