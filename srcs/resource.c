#include "../ls.h"

t_iresource	*ir_new(char *name, int filetype)
{
	t_iresource *new;

	new = ft_calloc(1, sizeof(t_iresource));
	if (new == NULL)
		return (NULL);
	new->name = name;
	new->filetype = filetype;
	return (new);
}

static void	ir_clear(t_iresource *ir)
{
	if (ir->name)
	{
		free(ir->name);
		ir->name = NULL;
	}
	if (ir->filetype)
		ir->filetype = 0;
}

void	ir_del(t_iresource *ir)
{
	if (ir == NULL)
		return ;
	ir_clear(ir);
	free(ir);
	ir = NULL;
}

static void	res_clear(t_resource *res)
{
	if (res->info)
		ir_del(res->info);
	if (res->child)
		res->child = NULL;
	if (res->next)
		res->next = NULL;
}

void	res_delone(t_resource *res)
{
	if (res == NULL)
		return ;
	res_clear(res);
	free(res);
	res = NULL;
}

t_resource	*res_new(t_iresource *ir)
{
	t_resource *new;

	new = ft_calloc(1, sizeof(t_resource));
	if (new == NULL)
		return (NULL);
	new->info = ir;
	new->next = NULL;
	new->child = NULL;
	return (new);
}
