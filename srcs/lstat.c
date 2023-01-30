#include "../ls.h"

t_list	*clstat(char **dfiles)
{
	int i;
	struct stat sb;
	t_list	*l, *ptr;

	if (len_double_char_array(dfiles) == 0)
		return (NULL);

	if (lstat(dfiles[0], &sb) == -1)
	{
		perror("lstat");
		return (NULL);
	}
	l = ft_lstnew((void*)&sb);
	ptr = l;
	i = 1;
	while (i < len_double_char_array(dfiles))
	{
		if (lstat(dfiles[i], &sb) == -1)
		{
			perror("lstat");
			return (NULL);
		}
		ptr->next = ft_lstnew((void*)&sb);
		ptr = ptr->next;
		i++;
	}
	return (l);
}
