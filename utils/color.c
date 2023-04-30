#include "../ls.h"

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
		case S_IFIFO:
			return (PIPE_TYPE);
		case S_IFSOCK:
			return (SOCKET_TYPE);
		case S_IFLNK:
			return (LINK_TYPE);
		case S_IFCHR:
			return (CHARACTER_TYPE);
		case S_IFBLK:
			return (BLOCK_TYPE);
		case S_IFREG:
			if (mode & S_IXUSR)
				return (EX_FILE_TYPE);
			if (mode & (S_IXUSR | S_ISUID))
				return (EX_WITH_SETUID_BIT_SET_TYPE);
			if (mode & (S_IXGRP | S_ISGID))
				return (EX_WITH_SETGID_BIT_SET_TYPE);
			break ;
		case S_IFDIR:
			if (mode & S_IWOTH)
			{
				if (mode & (S_IXOTH | S_ISVTX))
					return (DIR_WRITABLE_TO_OTHER_WITH_STICKY_BIT_TYPE);
				return (DIR_WRITABLE_TO_OTHER_WITHOUT_STICKY_BIT_TYPE);
			}
			return (DIR_TYPE);
	}
	return (0);
}
