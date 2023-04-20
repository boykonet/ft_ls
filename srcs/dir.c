#include "../ls.h"

int		if_dir_or_file(char *filename)
{
	DIR *dir;

	if (!filename)
		return (ERR_CODE_NULL_PARAMETER);
	dir = opendir(filename);
	if (dir == NULL)
	{
		if (errno == ENOTDIR)
		{
			errno = 0;
			return (1);
		}
		return (-1);
	}
	return (closedir(dir));
}

int	creaddir(char ***files, DIR *dir, int flag_a)
{
	struct dirent	*sd;

	while ((sd = readdir(dir)))
	{
		if (flag_a == 0 && ft_strncmp(sd->d_name, ".", 1) == 0)
			continue ;
		char *fi = ft_strdup(sd->d_name);
		if (fi == NULL)
		{
			free_2array_content((void**)*files);
			return (ERR_CODE_MALLOC_ERROR);
		}
		size_t flen = len_2array((const void**)(*files));
		if (realloc_2array((void***)files, flen + 1) != 0)
		{
			free(fi);
			fi = NULL;
			free_2array_content((void**)*files);
			return (ERR_CODE_MALLOC_ERROR);
		}
		flen = len_2array((const void**)(*files));
		(*files)[flen] = fi;
	}
	if (sd == NULL && errno != 0)
	{
		free_2array_content((void**)*files);
		return (ERR_CODE_STRERROR);
	}
	return (0);
}

int	openreaddir(char ***nfiles, char *dirpath, int flag_a)
{
	DIR		*dir;
	int		ecode;

	dir = opendir(dirpath);
	if(!dir)
		return (ERR_CODE_STRERROR);

	*nfiles = ft_calloc(1, sizeof(char*));
	if (*nfiles == NULL)
	{
		if (closedir(dir) == -1)
			return (ERR_CODE_STRERROR);
		return (ERR_CODE_MALLOC_ERROR);
	}
	ecode = creaddir(nfiles, dir, flag_a);
	if (ecode != 0)
	{
		free(*nfiles);
		*nfiles = NULL;
		if (closedir(dir) == -1)
			return (ERR_CODE_STRERROR);
		return (ecode);
	}
	if (closedir(dir) == -1)
	{
		free_2array((void**)*nfiles);
		return (ERR_CODE_STRERROR);
	}
	return (0);
}
