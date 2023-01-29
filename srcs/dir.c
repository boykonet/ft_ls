#include "../ls.h"

t_list *dir(char *d)
{
	t_list			*l, *ptr;
	DIR				*pdir;
	struct dirent	*pDirent;


	// open directory
	pdir = opendir(d);
	if (pdir == NULL)
	{
		printf("can't open directory %s", d);
		return (NULL);
	}

	// read directory and write to the t_list struct
	pDirent = readdir(pdir);
	l = NULL;
	if (pDirent == NULL)
	{
		closedir(pdir);
		return (NULL);
	}
	l = ft_lstnew((void*)pDirent);
	ptr = l;
	while ((pDirent = readdir(pdir)) != NULL)
	{
		ptr->next = ft_lstnew((void*)pDirent);
		ptr = ptr->next;
	}
	closedir(pdir);
	return (l);
}
