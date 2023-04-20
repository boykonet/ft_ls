#include "../../ls.h"

void	cstrmode(mode_t st_mode, char *filemode)
{
	const char	permissions[4] = "rwx";
	size_t		i;

	i = 0;
	while (i < 9)
	{
		filemode[i] = (st_mode & (1 << (8 - i))) ? permissions[i % 3] : '-';
		i++;
	}
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
	cstrmode(mode, &filemode[1]);
	set_filetype(&filemode[0], filetype);
	set_file_attribute(filepath, &filemode[10]);
}
