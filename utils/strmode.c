#include "../ls.h"

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
