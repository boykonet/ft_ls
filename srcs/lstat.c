#include "../ls.h"

int	clstat(t_list **l, char **dfiles)
{
	struct stat	sb;
	t_list		*ptr;
	int			i;

	if (l == NULL || dfiles == NULL || len_2_pointer_array((const void**)dfiles) == 0)
	{
		// TODO: error
		return (-1);
	}

	if (lstat(dfiles[0], &sb) == -1)
//		return (strerror(errno));
		return (-1);
	*l = ft_lstnew((void*)&sb);
	ptr = *l;
	i = 1;
	while (i < len_2_pointer_array((const void**)dfiles))
	{
		if (lstat(dfiles[i], &sb) == -1)
		{
			ft_lstclear(l, NULL);
			return (-1);
//			return (strerror(errno));
		}
		ptr->next = ft_lstnew((void*)&sb);
		ptr = ptr->next;
		i++;
	}
	return (0);
}
