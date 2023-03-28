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

//int		dir(t_list **listdirs, const char *dirname, char **emessage)
//{
//	t_list			*ptr;
//	DIR				*pdir;
//	struct dirent	*pDirent;
//	int 			errcode;
//
//	if (!listdirs || !dirname || !emessage)
//		return (-2);
//
//	// open directory
//	pdir = opendir(dirname);
//	if (pdir == NULL)
//	{
//		*emessage = strerror(errno);
//		return (-4);
//	}
//
//	// read directory and write to the t_list struct
//	pDirent = readdir(pdir);
//	if (pDirent == NULL)
//	{
//		closedir(pdir);
//		*emessage = strerror(errno);
//		return (-4);
//	}
//	*listdirs = ft_lstnew((void*)pDirent);
//	if (!*listdirs)
//	{
//		errcode = closedir(pdir);
//		*emessage = strerror(errno);
//		return (errcode == -1 ? -4 : -1);
//	}
//	ptr = *listdirs;
//	while ((pDirent = readdir(pdir)) != NULL)
//	{
//		ptr->next = ft_lstnew((void*)pDirent);
//		if (!ptr->next)
//		{
//			ft_lstclear(listdirs, NULL);
//			*listdirs = NULL;
//			errcode = closedir(pdir);
//			*emessage = strerror(errno);
//			return (errcode == -1 ? -4 : -1);
//		}
//		ptr = ptr->next;
//	}
//	if (pDirent == NULL && errno)
//	{
//		ft_lstclear(listdirs, NULL);
//		*listdirs = NULL;
//		errcode = closedir(pdir);
//		*emessage = strerror(errno);
//		return (errcode == -1 ? -4 : -1);
//	}
//	if (closedir(pdir) == -1)
//	{
//		ft_lstclear(listdirs, NULL);
//		*listdirs = NULL;
//		*emessage = strerror(errno);
//		return (-4);
//	}
//	return (0);
//}


void	openreaddir(t_fileinfo ***files, char *dirpath, int flag_a)
{
	DIR				*dir;
	struct dirent	*sd;

	dir = opendir(dirpath);
	if(!dir)
	{
		char *s = ft_strjoin("ls: ", dirpath);
		perror(s);
		free(s);
		s = NULL;
		exit(1);
	}

	*files = (t_fileinfo**)ft_calloc(1, sizeof(t_fileinfo*));
	if (!*files)
	{
		char *s = ft_strjoin("ls: ", dirpath);
		perror(s);
		free(s);
		s = NULL;
		exit(1);
	}
	while ((sd = readdir(dir)))
	{
		if (flag_a == 0 && ft_strncmp(sd->d_name, ".", 1) == 0)
			continue ;
		t_fileinfo *fi = new_fileinfo(dirpath, sd->d_name, sd->d_type);
		if (fi == NULL)
		{
			perror("malloc");
			exit(1);
		}
		size_t flen = len_2array((const void**)(*files));
		if (realloc_2array((void***)files, flen + 1) != 0)
		{
			perror("malloc");
			exit(1);
		}
		flen = len_2array((const void**)(*files));
		(*files)[flen] = fi;
	}
	if (sd == NULL && errno != 0)
	{
		char *s = ft_strjoin("ls: ", dirpath);
		perror(s);
		free(s);
		s = NULL;
		exit(1);
	}
	if (closedir(dir) == -1)
	{
		char *s = ft_strjoin("ls: ", dirpath);
		perror(s);
		free(s);
		s = NULL;
		exit(1);
	}
}