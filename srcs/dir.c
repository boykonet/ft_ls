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

int		dir(t_list **listdirs, const char *dirname, char **emessage)
{
	t_list			*ptr;
	DIR				*pdir;
	struct dirent	*pDirent;
	int 			errcode;

	if (!listdirs || !dirname || !emessage)
		return (-2);

	// open directory
	pdir = opendir(dirname);
	if (pdir == NULL)
	{
		*emessage = strerror(errno);
		return (-4);
	}

	// read directory and write to the t_list struct
	pDirent = readdir(pdir);
	if (pDirent == NULL)
	{
		closedir(pdir);
		*emessage = strerror(errno);
		return (-4);
	}
	*listdirs = ft_lstnew((void*)pDirent);
	if (!*listdirs)
	{
		errcode = closedir(pdir);
		*emessage = strerror(errno);
		return (errcode == -1 ? -4 : -1);
	}
	ptr = *listdirs;
	while ((pDirent = readdir(pdir)) != NULL)
	{
		ptr->next = ft_lstnew((void*)pDirent);
		if (!ptr->next)
		{
			ft_lstclear(listdirs, NULL);
			*listdirs = NULL;
			errcode = closedir(pdir);
			*emessage = strerror(errno);
			return (errcode == -1 ? -4 : -1);
		}
		ptr = ptr->next;
	}
	if (pDirent == NULL && errno)
	{
		ft_lstclear(listdirs, NULL);
		*listdirs = NULL;
		errcode = closedir(pdir);
		*emessage = strerror(errno);
		return (errcode == -1 ? -4 : -1);
	}
	if (closedir(pdir) == -1)
	{
		ft_lstclear(listdirs, NULL);
		*listdirs = NULL;
		*emessage = strerror(errno);
		return (-4);
	}
	return (0);
}
