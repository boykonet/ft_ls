#include "../ls.h"

char	*find_color(char color)
{
	int			i;
	t_colors	colors[8 + 1] = {
			{.key = 'a', .value = BLACK},
			{.key = 'b', .value = RED},
			{.key = 'c', .value = GREEN},
			{.key = 'd', .value = BROWN},
			{.key = 'e', .value = BLUE},
			{.key = 'f', .value = PURPLE},
			{.key = 'g', .value = CYAN},
			{.key = 'h', .value = LIGHT_GREY}};

	i = 0;
	while (i < 8)
	{
		if (colors[i].key == color)
			return (colors[i].value);
		i++;
	}
	return (colors[0].value);
}

void	set_color(size_t filetype, char data[11 + 1])
{
	const char	dcolors[] = DEFAULT_COLORS;
	char		color_pattern[] = COLOR_PATTERN;
	t_pattern	p[COUNT_COLOR_PATTERNS + 1];
	size_t	i, findex, bindex;

	i = 0;
	if (!(filetype >= MIN_FILE_TYPES && filetype <= MAX_FILE_TYPES))
		return ;
	ft_bzero(p, sizeof(p));
	findex = 2 * (filetype - 1);
	bindex = 2 * (filetype - 1) + 1;
	if (dcolors[findex] >= 'a' && dcolors[findex] <= 'z')
		add_pattern(&p[i++], TYPE_FONT_PATTERN, REGULAR_FONT);
	else
		add_pattern(&p[i++], TYPE_FONT_PATTERN, BOLT_FONT);
	add_pattern(&p[i++], SEMICOLON1_PATTERN, SEMICOLON);

	add_pattern(&p[i++], F_CODE_PATTERN, FOREGROUND_CODE);
	add_pattern(&p[i++], F_COLOR_PATTERN, find_color(dcolors[findex]));
	if (dcolors[bindex] != 'x')
	{
		add_pattern(&p[i++], SEMICOLON2_PATTERN, SEMICOLON);
		add_pattern(&p[i++], B_CODE_PATTERN, BACKGROUND_CODE);
		add_pattern(&p[i], B_COLOR_PATTERN, find_color(dcolors[bindex]));
	}
	else
	{
		add_pattern(&p[i++], SEMICOLON2_PATTERN, EMPTY);
		add_pattern(&p[i++], B_CODE_PATTERN, EMPTY);
		add_pattern(&p[i], B_COLOR_PATTERN, EMPTY);
	}
	replace_pattern(color_pattern, COLOR_PATTERN, p, COUNT_COLOR_PATTERNS);
	ft_memcpy(data, color_pattern, ft_strlen(color_pattern));
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
			return (0);
		case S_IFDIR:
			if (mode & S_IWOTH)
			{
				if (mode & (S_IXOTH | S_ISVTX))
					return (DIR_WRITABLE_TO_OTHER_WITH_STICKY_BIT_TYPE);
				return (DIR_WRITABLE_TO_OTHER_WITHOUT_STICKY_BIT_TYPE);
			}
			return (DIR_TYPE);
		default:
			return (0);
	}
}
