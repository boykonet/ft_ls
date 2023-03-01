#include "../ls.h"

int	clstat(t_list **l, char **dfiles, char **emessage)
{
	struct stat	sb;
	t_list		*ptr;
	int			i;

	if (l == NULL || dfiles == NULL || emessage == NULL)
		return (-2);

	if (len_2array((const void**)dfiles) == 0)
		return (0);

	if (lstat(dfiles[0], &sb) == -1)
	{
		*emessage = strerror(errno);
		return (-4);
	}
	*l = ft_lstnew((void*)&sb);
	if (!*l)
		return (-1);
	ptr = *l;
	i = 1;
	while (dfiles[i])
	{
		if (lstat(dfiles[i], &sb) == -1)
		{
			ft_lstclear(l, NULL);
			*emessage = strerror(errno);
			return (-4);
		}
		ptr->next = ft_lstnew((void*)&sb);
		if (!ptr->next)
		{
			ft_lstclear(l, NULL);
			*emessage = strerror(errno);
			return (-4);
		}
		ptr = ptr->next;
		i++;
	}
	return (0);
}
