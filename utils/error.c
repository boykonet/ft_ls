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

	if (!head || !pattern || !replacement)
		return (-1);
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
		return (-1);
	ft_memcpy(err->message, FLAG_NOT_SUPPORT, ft_strlen(FLAG_NOT_SUPPORT));
	err->exitcode = 1;
	return (add_pattern(&err->patterns, "{{flag}}", ch));
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

void	print_error_message(t_err *err)
{
	if (!err || !err->exitcode)
		return ;
	replace_pattern(err->message, err->message, err->patterns);
	write(CSTDERR, err->message, ft_strlen(err->message));
}

void	copy_strerror_message(t_err *err)
{
	char	*errmessage;

	errmessage = strerror(errno);
	ft_memcpy(&err->message[0], ERR_HEADER, ft_strlen(ERR_HEADER));
	ft_memcpy(&err->message[ft_strlen(ERR_HEADER)], errmessage, ft_strlen(errmessage));
}

// sww - something went wrong
// amessage - additional message
int		sww(t_err *err, char *amessage)
{
	ft_memcpy(err->message, SWW, ft_strlen(SWW));
	err->exitcode = 1;
	int errcode = add_pattern(&err->patterns, "{{message}}", amessage);
	if (errcode != 0)
	{
		clear_err(err);
		return (-1);
	}
	return (0);
}
