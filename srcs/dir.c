#include "../ls.h"

int		if_dir_or_file(char *filename)
{
	DIR *dir;

	if (!filename)
		return (-2);
	dir = opendir(filename);
	if (dir == NULL)
	{
		if (errno == ENOTDIR)
			return (1);
		return (-1);
	}
	closedir(dir);
	return (0);
}

int		dir(t_list **listdirs, char *dirname, t_list **epatterns)
{
	t_list			*ptr;
	DIR				*pdir;
	struct dirent	*pDirent;
	int				errcode;

	// open directory
	pdir = opendir(dirname);
	if (pdir == NULL)
	{
		errcode = add_pattern(epatterns, PATTERN_STRERROR_MESSAGE, strerror(errno));
		return (errcode != 0 ? errcode : -4);
	}

	// read directory and write to the t_list struct
	pDirent = readdir(pdir);
	if (pDirent == NULL)
	{
		closedir(pdir);
		errcode = add_pattern(epatterns, PATTERN_STRERROR_MESSAGE, strerror(errno));
		return (errcode != 0 ? errcode : -4);
	}
	*listdirs = ft_lstnew((void*)pDirent);
	ptr = *listdirs;
	while ((pDirent = readdir(pdir)) != NULL)
	{
		ptr->next = ft_lstnew((void*)pDirent);
		ptr = ptr->next;
	}
	closedir(pdir);
	if (pDirent == NULL && errno)
	{
		errcode = add_pattern(epatterns, PATTERN_STRERROR_MESSAGE, strerror(errno));
		return (errcode != 0 ? errcode : -4);
	}
	return (0);
}
