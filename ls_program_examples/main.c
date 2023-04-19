#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/errno.h>
#include "../libs/libft/libft.h"


// собираешь в одно место
// сортируешь в соответсвии с теми флагами, которые пришли
// выводишь на экран
// пробегаешься еще раз по всем файлам, находишь директорию, рекурсивно вызываешь свою функцию




//void	list_files(const char *dirname)
//{
//	struct dirent	*pointers[100];
//	size_t			max_len;
//
//	bzero(pointers, sizeof(struct dirent*) * 100);
//	DIR *dir = opendir(dirname);
//	if (dir == NULL)
//	{
//		printf("dir is NULL - dirname [%s]\n", dirname);
//		return ;
//	}
//
//	struct dirent *entity;
//
//	max_len = 0;
//	int i = 0;
//	while ((entity = readdir(dir)) != NULL)
//	{
//		pointers[i++] = entity;
//		size_t	current_len = strlen(entity->d_name);
//		if (max_len < current_len)
//			max_len = current_len;
//	}
//	if (entity == NULL && errno != 0)
//	{
//		printf("entity is NULL, errno [%s]\n", strerror(errno));
//		exit(1);
//	}
//	closedir(dir);
//	i = 0;
//	printf("%s:\n", dirname);
//	printf("    ");
//	while (pointers[i])
//	{
//		printf("%s", pointers[i]->d_name);
//		printf("    ");
//		i++;
//	}
//	printf("\n");
//
//	i = 0;
//	while (pointers[i])
//	{
//		if (pointers[i]->d_type == DT_DIR && strcmp(pointers[i]->d_name, ".") != 0 && strcmp(pointers[i]->d_name, "..") != 0)
//		{
//			char path[200] = {0};
//			bzero(path, sizeof(char) * 200);
//			strcat(path, dirname);
//			strcat(path, "/");
//			strcat(path, pointers[i]->d_name);
//			if (strcmp(path, "../ex/dir4") == 0)
//			{
//				printf("dirname [%s] d_name [%s] path [%s]\n\n", dirname, pointers[i]->d_name, path);
//				int j = 0;
//				while (pointers[j])
//				{
//					printf("pointers[%d] = %s\n", j, pointers[j]->d_name);
//					j++;
//				}
//			}
//			list_files(path);
////			printf("\n");
//		}
//		i++;
//	}
//}

static void	bubble(void **first, void **second)
{
	void *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

typedef struct s_fileinfo {
	char	name[255 + 1];
	int		type;
	// ...
} t_fileinfo;

t_fileinfo	*new_fileinfo(char *name, int type)
{
	t_fileinfo *f;

	f = ft_calloc(1, sizeof(t_fileinfo));
	if (!f)
		return (NULL);
	ft_memcpy(f->name, name, ft_strlen(name));
	f->type = type;
	return (f);
}

void	sort_files(t_list **array)
{
	t_list	*curr, *next;

	if (!array)
		return ;
	curr = (*array);
	while (curr)
	{
		next = curr->next;
		char *cname = ((t_fileinfo*)(curr->content))->name;
		size_t	csize = ft_strlen(cname);
		while (next)
		{
			char *nname = ((t_fileinfo*)(next->content))->name;
			size_t	nsize = ft_strlen(nname);
			if (strncmp(cname, nname, csize > nsize ? csize : nsize) > 0)
				bubble((void**)&curr, (void**)&next);
			next = next->next;
		}
		curr = curr->next;
	}
}

char	**copy_dirs(t_list *files)
{
	t_list	*p;
	char	**dirs;
	size_t	j, count;

	if (!files)
		return (ft_calloc(0, 0));
	count = 0;
	p = files;
	while (p)
	{
		if (((t_fileinfo*)(p->content))->type == 4)
			count++;
		p = p->next;
	}

	dirs = (char**)ft_calloc(count + 1, sizeof(char*));
	if (!dirs)
		return (NULL);
	j = 0;
	p = files;
	while (p)
	{
		t_fileinfo 	*fi = (t_fileinfo*)(p->content);
		if (fi->type == 4)
		{
			dirs[j] = strdup(fi->name);
			if (!dirs[j])
				// TODO: free dirs
				return (NULL);
			j++;
		}
		p = p->next;
	}
	return (dirs);
}

//void	**crealloc(void **data)
//{
//	size_t	size;
//
//	if (!data)
//		return (NULL);
//
//}

void rec_dirs(char *path, int flag_r, int flag_a, int flag_l) {
	DIR				*dir;
	t_list			*files; // TODO: find information about maximum files in one directory
	struct dirent	*ep;
	char			newdir[512];

	dir = opendir(path);
	if(!dir) {
		perror("ls");
		exit(1);
	}
	ep = readdir(dir);
	if (ep == NULL && errno)
	{
		perror("ls");
		exit(1);
	}
	files = ft_lstnew(new_fileinfo(ep->d_name, ep->d_type));
	if (files == NULL || files->content == NULL)
	{
		perror("ls");
		exit(1);
	}
	t_list *p = files;
	int	i = 0;
	while ((ep = readdir(dir)))
	{
		p->next = ft_lstnew(new_fileinfo(ep->d_name, ep->d_type));
		if (p->next == NULL)
		{
			perror("ls");
			exit(1);
		}
		p = p->next;
	}
	size_t	count = i;
	if (ep == NULL && errno)
	{
		// TODO: handle error
		// ls: ../ex/dir4: No such file or directory
		perror("ls");
		exit(1);
	}
	closedir(dir);

	printf("%s:\n", path);
	i = 0;

	sort_files(&files);
//	printf("before\n");
	char	**dirs = copy_dirs(files);
//	printf("after\n");

	p = files;
	while(p != NULL)
	{
		t_fileinfo	*fi = (t_fileinfo*)(p->content);
		if (!flag_a && !strncmp(fi->name, ".", 1))
		{
			p = p->next;
			continue ;
		}
		printf("%s    ", fi->name);
		p = p->next;
	}

	printf("\n\n");
//	dir = opendir(path);
	if (flag_r)
	{
		i = 0;
		while (dirs[i])
		{
			if (strcmp(dirs[i], ".") != 0 && strcmp(dirs[i], "..") != 0)
			{
				bzero(newdir, sizeof(char) * 512);
				strcat(newdir, path);
				strcat(newdir, "/");
				strcat(newdir, dirs[i]);
				rec_dirs(newdir, flag_r, flag_a, flag_l);
			}
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	rec_dirs("..", 1, 0, 0);
	return (0);
}
