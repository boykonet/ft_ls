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

/*
** 1.   directory
** 2.   symbolic link
** 3.   socket
** 4.   pipe
** 5.   executable
** 6.   block special
** 7.   character special
** 8.   executable with setuid bit set
** 9.   executable with setgid bit set
** 10.  directory writable to others, with sticky bit
** 11.  directory writable to others, without sticky bit
*/

int	set_color_type(mode_t mode)
{
	switch (mode & S_IFMT) {
		case S_IFREG:
			if (mode & S_IXUSR)
				return (EXECUTABLE_FILE_TYPE);
		case S_IFIFO:
			return (PIPE_TYPE);
		case S_IFSOCK:
			return (SOCKET_TYPE);
		case S_IFLNK:
			return (SYMBOLIC_LINK_TYPE);
		case S_IFCHR:
			return (CHARACTER_SPECIAL_TYPE);
		case S_IFBLK:
			return (BLOCK_SPECIAL_TYPE);
	}
	return (0);
}

int	set_fileinfo(t_fileinfo *finfo, unsigned short flags, long long *total)
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

	finfo->color_type = set_color_type(st.st_mode);

	set_filemode(filepath, st.st_mode, finfo->type, finfo->filemode);
	set_number_of_links(st.st_nlink, finfo->nlinks);

	set_owner(finfo->oname, st.st_uid);
	set_group(finfo->gname, st.st_gid);

	set_number_of_bytes(st.st_size, finfo->nbytes);

	if (is_flag(flags, U_FLAG_SHIFT, U_FLAG_VALUE) == 0)
	{ // time of last modified
		finfo->filetime.tv_sec = st.st_mtimespec.tv_sec;
		finfo->filetime.tv_nsec = st.st_mtimespec.tv_nsec;
	}
	else
	{ // time of last access
		finfo->filetime.tv_sec = st.st_atimespec.tv_sec;
		finfo->filetime.tv_nsec = st.st_atimespec.tv_nsec;
	}

	ecode = set_time(finfo->filetime, finfo->amonth, finfo->day_lm, finfo->time_year_lm);
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
