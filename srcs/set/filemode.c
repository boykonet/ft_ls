/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filemode.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:08:55 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:08:55 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ls.h"

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
