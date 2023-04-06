#include "../ls.h"

t_list	*find_last_elem(t_list **head)
{
	t_list	*curr;

	if (!head)
		return (NULL);
	curr = *head;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	add_pattern(t_pattern p[1], char *pattern, char *replacement)
{
	ft_bzero(p->pattern, 256);
	ft_bzero(p->replacement, 256);
	ft_strlcpy(p->pattern, pattern, 255);
	ft_strlcpy(p->replacement, replacement, 255);
}

//int	flag_not_support_error(t_err *err, char flag)
//{
//	char		ch[2] = {flag, '\0'};
//
//	if (!err)
//		return (-1);
//	ft_memcpy(err->message, FLAG_NOT_SUPPORT, ft_strlen(FLAG_NOT_SUPPORT));
//	err->exitcode = 1;
//	return (add_pattern(&err->patterns, "{{flag}}", ch));
//}

void	cleaner(t_ls *ls, int exitcode)
{
	if (!ls || !exitcode)
		return ;
	clear_ls(ls);
	exit(exitcode);
}

int	handle_error(int ecode, t_pattern p[MAX_ERROR_PATTERNS], int *gcode)
{
	char	emessage[255 + 1] = {0};

	if (ecode == 0)
		return (0);
	else if (ecode == -1)
		replace_pattern(emessage, MALLOC_ERROR, p, 1);
	else if (ecode == -2)
		ft_strlcat(emessage, NULL_PARAMETER, 255);
	else if (ecode == -3) // strerror
		replace_pattern(emessage, STRERROR_MESSAGE, p, 1);
	else if (ecode == -4)
		replace_pattern(emessage, FLAG_NOT_SUPPORT, p, 1);
	else if(ecode == -5)
		replace_pattern(emessage, FILE_ERROR, p, 2);
	if (gcode != NULL)
		*gcode = 1;
	ft_putstr_fd(ERR_HEADER, CSTDERR);
	ft_putstr_fd(emessage, CSTDERR);
	ft_putchar_fd('\n', 1);
	return (-1);
}
