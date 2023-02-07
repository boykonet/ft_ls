#include "../ls.h"

void	del_file_struct(void *file)
{
	t_file *f = (t_file*)file;

	if (f->filename)
	{
		free(f->filename);
		f->filename = NULL;
	}

	if (f->path)
	{
		free(f->path);
		f->path = NULL;
	}
}
