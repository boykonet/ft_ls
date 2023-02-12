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

t_list	*add_pattern(t_list **head, char *pattern, char *replacement)
{
	t_list		*last;
	t_pattern	*p;

	p = new_pattern(pattern, replacement);
	if (!p)
		return (NULL);
	if (!head)
		last = ft_lstnew(p);
	else
	{
		last = find_last_elem(head);
		last->next = ft_lstnew(p);
		last = last->next;
	}
	if (!last)
	{
		free(p);
		p = NULL;
		return (NULL);
	}
	return (last);
}

int	flag_not_support_error(t_err *err, char flag)
{
	char		ch[2];

	if (!err)
		return (-1);
	err->message = ft_strdup(FLAG_NOT_SUPPORT);
	if (!err->message)
		return (-1);
	err->exitcode = 1;

	ch[0] = flag;
	err->patterns = add_pattern(NULL, "{{flag}}", ch);
	if (!err->patterns)
	{
		clear_err(err);
		return (-1);
	}
	return (0);
}

char	*replace_pattern(char *str, t_list *patterns)
{
	t_list	*poh;
	char	*res, *pres;
	char	*pbegin, *pend;
	int		bsize, asize;

	poh = patterns;
	res = ft_strdup(str);
	if (!res)
		return (NULL);
	while (poh)
	{
		pres = res;
		char	*pattern, *replacement;

		pattern = ((t_pattern*)(poh->content))->pattern;
		replacement = ((t_pattern*)(poh->content))->replacement;

		pbegin = ft_strnstr(res, pattern, ft_strlen(res));
		if (!*pbegin)
			continue ;
		pend = pbegin + ft_strlen(pattern);

		bsize = (int)(pbegin - res);
		asize = (int)((res + ft_strlen(res)) - pend);
		res = ft_calloc(bsize + ft_strlen(replacement) + asize + 1, sizeof(char));
		if (!res)
		{
			free(pres);
			pres = NULL;
			return (NULL);
		}
		ft_memcpy(res, str, bsize);
		ft_memcpy(res + bsize, replacement, ft_strlen(replacement));
		ft_memcpy(res + bsize + ft_strlen(replacement), pend, asize);
		free(pres);
		poh = poh->next;
	}
	return (res);
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
	char	*message;

	if (!ls || !ls->err.message)
		return ;
	message = replace_pattern(ls->err.message, ls->err.patterns);
	write(CSTDERR, message, ft_strlen(message));
	free(message);
	message = NULL;
	cleaner(ls, ls->err.exitcode);
}

