/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   srcs.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gkarina <gkarina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 22:10:11 by gkarina       #+#    #+#                 */
/*   Updated: 2023/01/03 20:25:01 by gkarina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define MAX_COUNT_FLAGS_PER_COMMAND 5

# include <unistd.h>
/*
** write
** readlink
*/


# include <dirent.h>
/*
** opendir
** readdir
** closedir
*/


# include <sys/stat.h>
/*
** stat
** lstat
*/


# include <sys/types.h>
# include <pwd.h>
/*
** getpwuid
*/


# include <grp.h>
/*
** getgrgid
*/


# include <sys/xattr.h>
/*
** listxattr
** getxattr
*/


# include <time.h>
/*
** time
** ctime
*/

# include <stdlib.h>
/*
** malloc
** free
** exit
*/

# include <stdio.h>
/*
** perror
** strerror
*/

# include "../libs/libft/libft.h"

typedef struct	s_ls
{
	char	*flags;
	char	**folders;
} t_ls;

int				parse(t_ls *ls, int argc, char **argv);
int				init_ls(t_ls *ls);
void			clear_ls(t_ls *ls);
int				execute(t_ls *ls, char **message);


#endif
