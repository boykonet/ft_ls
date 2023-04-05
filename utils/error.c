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

int	handle_error(int errcode, t_pattern p[1])
{
	char	emessage[255 + 1] = {0};

	if (errcode == 0)
		return (0);
	else if (errcode == -1)
		replace_pattern(emessage, MALLOC_ERROR, p, 1);
	else if (errcode == -2)
		ft_strlcat(emessage, NULL_PARAMETER, 255);
	else if (errcode == -3) // strerror
		replace_pattern(emessage, STRERROR_MESSAGE, p, 1);
	else if (errcode == -4)
		replace_pattern(emessage, FLAG_NOT_SUPPORT, p, 1);
	ft_putstr_fd(ERR_HEADER, CSTDERR);
	ft_putstr_fd(emessage, CSTDERR);
	ft_putchar_fd('\n', 1);
	return (-1);
}
