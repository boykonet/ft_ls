#include "../ls.h"

int		if_dir_or_file(char *filename)
{
	if (opendir(filename) == NULL)
	{
		if (errno == ENOTDIR)
			return (1);
		return (-1);
	}
	return (0);
}


// Returns 0 if not error
// -1 if error and write error message to err variable
// 1 if not directory
int		dir(t_list **l, char *dirname, t_err *err)
{
	t_list			*ptr;
	DIR				*pdir;
	struct dirent	*pDirent;

	// open directory
	pdir = opendir(dirname);
	if (pdir == NULL)
	{
		copy_strerror_message(err);
		err->exitcode = 1;
		return (-1);
	}

	// read directory and write to the t_list struct
	pDirent = readdir(pdir);
	if (pDirent == NULL)
	{
		closedir(pdir);
		copy_strerror_message(err);
		err->exitcode = 1;
		return (-1);
	}
	*l = ft_lstnew((void*)pDirent);
	ptr = *l;
	while ((pDirent = readdir(pdir)) != NULL)
	{
		ptr->next = ft_lstnew((void*)pDirent);
		ptr = ptr->next;
	}
	closedir(pdir);
	if (pDirent == NULL && errno)
	{
		copy_strerror_message(err);
		err->exitcode = 1;
		return (-1);
	}
	return (0);
}
