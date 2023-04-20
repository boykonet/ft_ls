#include "../ls.h"

t_fileinfo	*new_fileinfo(char *path, char *filename)
{
	t_fileinfo *f;

	f = ft_calloc(1, sizeof(t_fileinfo));
	if (f == NULL)
		return (NULL);
	ft_memcpy(f->path, path, ft_strlen(path));
	ft_memcpy(f->filename, filename, ft_strlen(filename));
	ft_memcpy(f->filemode, "---------- ", 11);
	return (f);
}

int	set_fileinfo(t_fileinfo *finfo, long long *total)
{
	struct stat		st;
	char			*filepath;
	size_t			flen;
	int 			ecode;

	filepath = NULL;
	flen = ft_strlen(finfo->path) + 1 + ft_strlen(finfo->filename) + 1;
	filepath = ft_calloc(flen, sizeof(char));
	if (!filepath)
		return (ERR_CODE_MALLOC_ERROR);
	if (ft_strlen(finfo->path) == 0)
		ft_strlcat(filepath, finfo->filename, flen);
	else
	{
		ft_strlcat(filepath, finfo->path, flen);
		ft_strlcat(filepath, "/", flen);
		ft_strlcat(filepath, finfo->filename, flen);
	}

	if (lstat(filepath, &st) == -1)
	{
		free(filepath);
		filepath = NULL;
		return (ERR_CODE_STRERROR);
	}

	if (total != NULL)
		*total += st.st_blocks;

	// file type
	set_type(&finfo->type, st.st_mode);

	set_filemode(filepath, st.st_mode, finfo->type, finfo->filemode);
	set_number_of_links(st.st_nlink, finfo->nlinks);

	set_owner(finfo->oname, st.st_uid);
	set_group(finfo->gname, st.st_gid);

	set_number_of_bytes(st.st_size, finfo->nbytes);

	ecode = set_time(st.st_mtimespec, finfo->amonth, finfo->day_lm, finfo->time_year_lm, &finfo->mtime);
	if (ecode != 0)
	{
		free(filepath);
		filepath = NULL;
		return (ecode);
	}

	ecode = 0;
	if (finfo->type == S_IFLNK)
		ecode = set_link(filepath, finfo->link);
	free(filepath);
	filepath = NULL;
	if (ecode != 0)
		return (ecode);
	return (0);
}
