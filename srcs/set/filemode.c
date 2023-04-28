#include "../../ls.h"

static void	user_file_mode(mode_t mode, char *p)
{
	if (mode & S_IRUSR)
		*p++ = 'r';
	else
		*p++ = '-';
	if (mode & S_IWUSR)
		*p++ = 'w';
	else
		*p++ = '-';
	switch (mode & (S_IXUSR | S_ISUID)) {
		case 0:
			*p++ = '-';
			break ;
		case S_IXUSR:
			*p++ = 'x';
			break ;
		case S_ISUID:
			*p++ = 'S';
			break ;
		case (S_IXUSR | S_ISUID):
			*p++ = 's';
			break ;
	}
}

static void	group_file_mode(mode_t mode, char *p)
{
	if (mode & S_IRGRP)
		*p++ = 'r';
	else
		*p++ = '-';
	if (mode & S_IWGRP)
		*p++ = 'w';
	else
		*p++ = '-';
	switch (mode & (S_IXGRP | S_ISGID)) {
		case 0:
			*p++ = '-';
			break ;
		case S_IXGRP:
			*p++ = 'x';
			break ;
		case S_ISGID:
			*p++ = 'S';
			break ;
		case (S_IXGRP | S_ISGID):
			*p++ = 's';
			break ;
	}
}

static void	other_file_mode(mode_t mode, char *p)
{
	if (mode & S_IROTH)
		*p++ = 'r';
	else
		*p++ = '-';
	if (mode & S_IWOTH)
		*p++ = 'w';
	else
		*p++ = '-';
	switch (mode & (S_IXOTH | S_ISVTX)) {
		case 0:
			*p++ = '-';
			break ;
		case S_IXOTH:
			*p++ = 'x';
			break ;
		case S_ISVTX:
			*p++ = 'T';
			break ;
		case (S_IXOTH | S_ISVTX):
			*p++ = 't';
			break ;
	}
}

void	cstrmode(mode_t st_mode, char *filemode)
{
	char	*p;

	if (filemode == NULL)
		return ;
	p = filemode;
	/* user */
	user_file_mode(st_mode, p);
	/* group */
	group_file_mode(st_mode, p + 3);
	/* other */
	other_file_mode(st_mode, p + 6);
}

void	set_filetype(char *filetype, unsigned int type)
{
	if (filetype == NULL)
		return ;
	t_filetypes	filetypes[FILETYPES_SIZE + 1] = {
			{.filetype = S_IFBLK, .replacement = 'b'},
			{.filetype = S_IFCHR, .replacement = 'c'},
			{.filetype = S_IFDIR, .replacement = 'd'},
			{.filetype = S_IFLNK, .replacement = 'l'},
			{.filetype = S_IFSOCK, .replacement = 's'},
			{.filetype = S_IFIFO, .replacement = 'p'},
			{.filetype = S_IFREG, .replacement = '-'},
			{.filetype = S_IFWHT, .replacement = '?'}};

	for (int i = 0; i < FILETYPES_SIZE; i++)
	{
		if (type == filetypes[i].filetype)
		{
			*filetype = filetypes[i].replacement;
			break ;
		}
	}
}

void		is_extended_attributes(char *path, char *attr)
{
	if (path == NULL || attr == NULL)
		return ;
	ssize_t	size = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (size > 0)
		*attr = '@';
}

void	set_file_attribute(char *path, char *attr)
{
	if (path == NULL || attr == NULL)
		return ;
	is_extended_attributes(path, attr);
}

void	set_filemode(char *filepath, mode_t mode, unsigned int filetype, char *filemode)
{
	if (filepath == NULL || filemode == NULL)
		return ;
	set_filetype(&filemode[0], filetype);
	cstrmode(mode, &filemode[1]);
	set_file_attribute(filepath, &filemode[10]);
}
