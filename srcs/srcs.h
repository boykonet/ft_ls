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

# define MAX_FLAGS		5
# define CONST_FLAGS	"Ralrt"

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


typedef int (*f) (void*);

typedef struct	s_ls
{
	char	*flags;
	char	**files;
//	char 	sflags[MAX_FLAGS + 1];
//	f 		func[MAX_FLAGS + 1];
} t_ls;

typedef struct s_iresource
{
	int		filetype;
	char	*name;
//	char	*link;
//	char	*username;
//	char	*groupname;
//	int 	size;
} t_iresource;

typedef struct s_resource
{
	t_iresource		*info;
	struct s_file	*next;
	struct s_file	*child;
} t_resource;

int				parse(t_ls *ls, int argc, char **argv);
int				init_ls(t_ls *ls);
void			clear_ls(t_ls *ls);
int				execute(t_ls *ls);
int				handle_recursive_flag(void *p);
int				handle_a_flag(void *p);
int				handle_l_flag(void *p);
int				handle_r_flag(void *p);
int				handle_t_flag(void *p);

t_list	*dir(char *d);
t_list	*clstat(char **dfiles);
char	*creadlink(char *link);
char *get_user(uid_t uid);
char *get_group(gid_t gid);


#endif
