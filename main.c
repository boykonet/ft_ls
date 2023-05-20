/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:23:51 by gkarina       #+#    #+#                 */
/*   Updated: 2023/05/05 14:23:51 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*
** -a      Include directory entries whose names begin with a dot (.).
** -l      (The lowercase letter ``ell''.)  List in long format.  (See below.)  If the output is to a terminal, a total sum for all the file sizes
**         is output on a line before the long listing.
** -R      Recursively list subdirectories encountered.
** -r      Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest dirs last, if combined with
**         sort by size
** -t      Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.
** ------------------------- B O N U S -------------------------
** -d      Directories are listed as plain files (not searched recursively).
** -f      Output is not sorted.  This option turns on the -a option.
** -g      This option is only available for compatibility with POSIX; it is used to display the group name in the long (-l) format output (the owner name is suppressed).
** -u      Use time of last access, instead of last modification of the file for sorting (-t) or long printing (-l). (NOT IMPLEMENTED)
** -G      Enable colorized output.  This option is equivalent to defining CLICOLOR in the environment.
*/

int main(int argc, char **argv, char **env)
{
	t_ls	ls;
	int 	ecode;

	(void)argc;
	initialization(&ls);
	parsing(&ls, argv + 1, env);
	execution(&ls);
	ecode = ls.global_ecode;
	clear_ls(&ls);
	return (ecode);
}
