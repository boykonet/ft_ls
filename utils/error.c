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

void		replace_pattern(char *dest, const char *src, t_list *patterns)
{
	t_list	*poh; // pointer of head
	char	*pbegin, *pend;
	int		bsize, asize;

	ft_memcpy(dest, src, ft_strlen(src));
	poh = patterns;
	while (poh)
	{
		char	*pattern, *replacement;

		pattern = ((t_pattern*)(poh->content))->pattern;
		replacement = ((t_pattern*)(poh->content))->replacement;

		pbegin = ft_strnstr(dest, pattern, ft_strlen(dest));
		if (!pbegin)
		{
			poh = poh->next;
			continue ;
		}
		pend = pbegin + ft_strlen(pattern);

		bsize = (int)(pbegin - dest);
		asize = (int)((dest + ft_strlen(dest)) - pend);
		ft_memmove(pbegin + ft_strlen(replacement), pbegin + ft_strlen(pattern), asize);
		ft_memcpy(pbegin, replacement, ft_strlen(replacement));
		dest[bsize + ft_strlen(replacement) + asize] = '\0';
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

void	handle_error(int errcode, t_list *params)
{
	char	emessage[200];

	ft_bzero(emessage, 200);
	switch (errcode) {
		case 0:
			return ;
		case -1:
			replace_pattern(emessage, MALLOC_ERROR, NULL);
			break ;
		case -2:
			replace_pattern(emessage, NULL_PARAMETER, NULL);
			break ;
		case -3:
			replace_pattern(emessage, FLAG_NOT_SUPPORT, params);
			break ;
		case -4:
			replace_pattern(emessage, STRERROR_MESSAGE, params);
			break ;
		// place for any another cases
		default:
			replace_pattern(emessage, UNEXPECTED_ERROR, NULL);
	}
	write(CSTDERR, ERR_HEADER, ft_strlen(ERR_HEADER));
	write(CSTDERR, emessage, ft_strlen(emessage));
	write(CSTDERR, "\n", 1);
	exit(1);
}
