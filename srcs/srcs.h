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

typedef int (*f) (int);

typedef struct	s_ls
{
	char	*flags;
	char	**folders;
	char 	sflags[MAX_COUNT_FLAGS_PER_COMMAND];// = {'R', 'a', 'l', 'r', 't'};
	f 		func[MAX_COUNT_FLAGS_PER_COMMAND];// = {&handle_recursive_flag, &handle_a_flag, &handle_l_flag, &handle_r_flag, &handle_t_flag};
} t_ls;

int				parse(t_ls *ls, int argc, char **argv);
int				init_ls(t_ls *ls);
void			clear_ls(t_ls *ls);
int				execute(t_ls *ls);
int	handle_recursive_flag(int a);
int	handle_a_flag(int a);
int	handle_l_flag(int a);
int	handle_r_flag(int a);
int	handle_t_flag(int a);


#endif
