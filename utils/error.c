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

int	add_pattern(t_list **head, char *pattern, char *replacement)
{
	t_list		*last;
	t_pattern	*p;

	if (!head)
		return (-2);
	p = new_pattern(pattern, replacement);
	if (!p)
		return (-1);
	if (!(*head))
	{
		last = ft_lstnew(p);
		*head = last;
	}
	else
	{
		last = find_last_elem(head);
		last->next = ft_lstnew(p);
		last = last->next;
	}
	if (!last)
	{
		del_pattern(p);
		return (-1);
	}
	return (0);
}

int	flag_not_support_error(t_err *err, char flag)
{
	char		ch[2] = {flag, '\0'};

	if (!err)
		return (-2);
	ft_memcpy(err->message, FLAG_NOT_SUPPORT, ft_strlen(FLAG_NOT_SUPPORT));
	err->exitcode = 1;

	int errcode = add_pattern(&err->patterns, "{{flag}}", ch);
	if (errcode != 0)
	{
		clear_err(err);
		return (errcode);
	}
	return (0);
}

void	print_error_and_exit(int errcode)
{
	write(CSTDERR, MALLOC_ERROR, ft_strlen(MALLOC_ERROR));
	exit(errcode);
}

void		replace_pattern(char *dest, const char *src, t_list *patterns)
{
	t_list	*poh; // pointer of head
	char	*pbegin, *pend;
	int		asize;

	ft_memcpy(dest, src, ft_strlen(src));
	poh = patterns;
	while (poh)
	{
		char	*pattern, *replacement;

		pattern = ((t_pattern*)(poh->content))->pattern;
		replacement = ((t_pattern*)(poh->content))->replacement;

		pbegin = ft_strnstr(dest, pattern, ft_strlen(dest));
		if (!*pbegin)
			continue ;
		pend = pbegin + ft_strlen(pattern);

		// bsize = (int)(pbegin - dest);
		asize = (int)((dest + ft_strlen(dest)) - pend);
		ft_memmove(pbegin + ft_strlen(replacement), pbegin + ft_strlen(pattern), asize);
		ft_memcpy(pbegin, replacement, ft_strlen(replacement));
		poh = poh->next;
	}
}

void	cleaner(t_ls *ls, int exitcode)
{
	if (!ls || !exitcode)
		return ;
	clear_ls(ls);
	exit(exitcode);
}

void	print_error_message_and_exit(t_ls *ls)
{
	char	message[200];

	if (!ls || !ls->err.message)
		return ;
	replace_pattern(message, ls->err.message, ls->err.patterns);
	write(CSTDERR, ls->err.message, ft_strlen(ls->err.message));
	free(message);
	message = NULL;
	cleaner(ls, ls->err.exitcode);
}

void	copy_strerror_message(t_err *err)
{
	char	*errmessage;

	errmessage = strerror(errno);
	ft_memcpy(&err->message[0], ERR_HEADER, ft_strlen(ERR_HEADER));
	ft_memcpy(&err->message[ft_strlen(ERR_HEADER)], errmessage, ft_strlen(errmessage));
}
