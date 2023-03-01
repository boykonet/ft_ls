#include <stdio.h>
#include <string.h>
#include <dirent.h>


// собираешь в одно место
// сортируешь в соответсвии с теми флагами, которые пришли
// выводишь на экран
// пробегаешься еще раз по всем файлам, находишь директорию, рекурсивно вызываешь свою функцию




void	list_files(const char *dirname)
{
	struct dirent	*pointers[100] = {0};
	size_t			max_len;

	printf("Reading files in %s\n", dirname);

	DIR *dir = opendir(dirname);
	if (dir == NULL)
	{
		printf("dir is NULL - dirname [%s]\n", dirname);
		return ;
	}

	struct dirent *entity;

	entity = readdir(dir);
	if (entity == NULL)
	{
		printf("first entity is NULL\n");
		return ;
	}
	max_len = strlen(entity->d_name);
	int i = 0;
	while(entity != NULL)
	{
		pointers[i++] = entity;
		entity = readdir(dir);
		if (entity != NULL)
		{
			size_t	current_len = strlen(entity->d_name);
			if (max_len < current_len)
				max_len = current_len;
		}
	}
	closedir(dir);
	i = 0;
	printf("%s:\n", dirname);
	printf("    ");
	while (pointers[i])
	{
		printf("%s", pointers[i]->d_name);
		printf(" ");
		i++;
	}
	printf("\n");

	i = 0;
	while (pointers[i])
	{
		if (pointers[i]->d_type == DT_DIR && strncmp(pointers[i]->d_name, ".", 1) != 0)
		{
			char path[200] = {0};
			strcat(path, dirname);
			strcat(path, "/");
			strcat(path, pointers[i]->d_name);
			if (strcmp(path, "../ex/dir4") == 0)
				printf("dirname [%s] d_name [%s] path [%s]\n", dirname, pointers[i]->d_name, path);
			list_files(path);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	list_files("..");
	return (0);
}
