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

void	set_fileinfo(t_fileinfo *finfo, long long *total)
{
	struct stat		st;
	char			*filepath;
	size_t			flen;

	filepath = NULL;
	flen = ft_strlen(finfo->path) + 1 + ft_strlen(finfo->filename) + 1;
	filepath = ft_calloc(flen, sizeof(char));
	if (!filepath)
	{
		perror("malloc");
		exit(1);
	}
	ft_strlcat(filepath, finfo->path, flen);
	ft_strlcat(filepath, "/", flen);
	ft_strlcat(filepath, finfo->filename, flen);

	if (lstat(filepath, &st) == -1)
	{
		perror("ls");
		exit(1);
	}

	if (total != NULL)
		*total += st.st_blocks;

	// file type
	set_type(&finfo->type, st.st_mode);

	set_filemode(filepath, st.st_mode, finfo->type, finfo->filemode); // TODO: might be empty value
	set_number_of_links(st.st_nlink, finfo->nlinks);

	set_owner(finfo->oname, st.st_uid);
	set_group(finfo->gname, st.st_gid);

	set_number_of_bytes(st.st_size, finfo->nbytes);

	set_time(st.st_mtimespec, finfo->amonth, finfo->day_lm, finfo->time_year_lm, &finfo->mtime); // TODO: if more than 6 months or in the future, print year (check future time)

	if (finfo->type == S_IFLNK)
		set_link(filepath, finfo->link);

	free(filepath);
	filepath = NULL;
}
