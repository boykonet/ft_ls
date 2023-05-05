/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:23:01 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:23:01 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	cleaner(t_ls *ls, int exitcode)
{
	if (!ls || !exitcode)
		return ;
	clear_ls(ls);
	exit(exitcode);
}

void	handle_ecodes(int ecode, char *filename, t_pattern p[MAX_ERROR_PATTERNS])
{
	if (ecode == ERR_CODE_MALLOC_ERROR)
		add_pattern(p, PATTERN_MALLOC_ERROR, strerror(errno));
	else if (ecode == ERR_CODE_STRERROR)
		add_pattern(p, PATTERN_STRERROR_MESSAGE, strerror(errno));
	else if (ecode == ERR_CODE_FILE_ERROR && filename != NULL)
	{
		add_pattern(&p[0], PATTERN_FILE_ERROR_FILENAME, filename);
		add_pattern(&p[1], PATTERN_FILE_ERROR_MESSAGE, strerror(errno));
	}
	errno = 0;
}

int	handle_error(int ecode, t_pattern p[MAX_ERROR_PATTERNS], int *gcode)
{
	char	emessage[STRING_SIZE + 1];

	ft_bzero(emessage, sizeof(emessage));
	if (ecode == 0)
		return (0);
	else if (ecode == ERR_CODE_MALLOC_ERROR)
		replace_pattern(emessage, MALLOC_ERROR, p, 1);
	else if (ecode == ERR_CODE_NULL_PARAMETER)
		ft_strlcat(emessage, NULL_PARAMETER, STRING_SIZE);
	else if (ecode == ERR_CODE_STRERROR) // strerror
		replace_pattern(emessage, STRERROR_MESSAGE, p, 1);
	else if (ecode == ERR_CODE_FLAG_NOT_SUPPORT)
		replace_pattern(emessage, FLAG_NOT_SUPPORT, p, 1);
	else if(ecode == ERR_CODE_FILE_ERROR)
		replace_pattern(emessage, FILE_ERROR, p, 2);
	if (gcode != NULL)
		*gcode = 1;
	ft_putstr_fd(ERR_HEADER, CSTDERR);
	ft_putstr_fd(emessage, CSTDERR);
	ft_putchar_fd('\n', CSTDERR);
	return (-1);
}
