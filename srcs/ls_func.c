/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ls_func.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/21 16:10:03 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/21 16:10:03 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	init_ls(t_ls *ls)
{
	ls->flags = 0;
	ls->files = NULL;
	ls->dirs = NULL;
	ft_bzero(ls->epatterns, sizeof(ls->epatterns));
	ls->possible_files = 0;
	ls->global_ecode = 0;
	ft_bzero(ls->color, sizeof(ls->color));
}

void	clear_ls(t_ls *ls)
{
	ls->flags = 0;
	if (ls->files)
	{
		free_2array((void **)ls->files);
		ls->files = NULL;
	}
	if (ls->dirs)
	{
		free_2array((void **)ls->dirs);
		ls->dirs = NULL;
	}
	ft_bzero(ls->epatterns, sizeof(ls->epatterns));
	ls->possible_files = 0;
	ls->global_ecode = 0;
	ft_bzero(ls->color, sizeof(ls->color));
}
