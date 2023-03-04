#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/errno.h>


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

void	sort(t_fileinfo **array)
{
	int		i, j;

	if (!array)
		return ;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		size_t	isize = strlen(array[i].name);
		while (array[j])
		{
			size_t	jsize = strlen(array[j].name);
			if (strncmp(array[i].name, array[j].name, isize > jsize ? isize : jsize) > 0)
				bubble((void**)&array[i], (void**)&array[j]);
			j++;
		}
		i++;
	}
}

char	**copy_dirs(t_fileinfo files[1024])
{
	char	**dirs;
	size_t	i, j, count;

	count = 0;
	i = 0;
	while (files[i])
	{
		if (files[i].type == 4)
			count++;
		i++;
	}

	dirs = (char**)malloc(sizeof(char*) * (count + 1));
	if (!dirs)
		return (NULL);
	i = 0;
	j = 0;
	while (files[i])
	{
		if (files[i].type == 4)
		{
			dirs[j] = strdup(files[i].name);
			if (!dirs[j])
				// TODO: free dirs
				return (NULL);
			j++;
		}
		i++;
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
	t_fileinfo		fi[1024]; // TODO: find information about maximum files in one directory
	struct dirent	*ep;
	char			newdir[512];

	dir = opendir(path);
	if(!dir) {
		perror("ls");
		exit(1);
	}

	bzero(fi, sizeof(t_fileinfo*) * 1024);
	int	i = 0;
	while ((ep = readdir(dir)))
	{
		printf("[%d] [%s]\n", i, ep->d_name);
		fi[i].name[0] = 'a';
		fi[i].name[1] = '\0';
		printf("sizeof(fi[%d]) = %lu, name = %s\n", i, sizeof(fi[i]), fi[i].name);
		bzero(fi[i].name, sizeof(char) * (255 + 1));
		memcpy(fi[i].name, ep->d_name, strlen(ep->d_name));
		printf("%s\n", fi[i].name);
		fi[i].type = ep->d_type;
		i++;
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

	sort(&fi);
	printf("before\n");
	char	**dirs = copy_dirs(fi);
	printf("after\n");

	while(fi[i] != NULL)
	{
		if (!flag_a && !strncmp(fi[i].name, ".", 1))
		{
			i++;
			continue ;
		}
		printf("%s    ", fi[i].name);
		i++;
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
