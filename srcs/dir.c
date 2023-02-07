#include "../ls.h"

char *dir(t_list **l, char *dirname)
{
	t_list			*ptr;
	DIR				*pdir;
	struct dirent	*pDirent;


	// open directory
	pdir = opendir(dirname);
	if (pdir == NULL)
		return strerror(errno);

	// read directory and write to the t_list struct
	pDirent = readdir(pdir);
	if (pDirent == NULL)
	{
		closedir(pdir);
		return strerror(errno);
	}
	*l = ft_lstnew((void*)pDirent);
	ptr = *l;
	while ((pDirent = readdir(pdir)) != NULL)
	{
		ptr->next = ft_lstnew((void*)pDirent);
		ptr = ptr->next;
	}
	closedir(pdir);
	return strerror(errno);
}
