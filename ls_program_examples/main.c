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

void RecDir(char *path, int flag) {
	DIR *dp;

	dp = opendir(path);
	if(!dp) {
		perror(path);
		exit(1);
	}
	struct dirent *ep;
	char newdir[512];
	printf("%s:\n", path);
	while((ep = readdir(dp)))
	{
		if(strncmp(ep->d_name, ".", 1))
			printf("%s    ", ep->d_name);
	}
	printf("\n\n");
	closedir(dp);
	dp = opendir(path);
	while((ep = readdir(dp)))
	{
		if (strncmp(ep->d_name, ".", 1))
		{
			if (flag && ep->d_type == 4)
			{
				bzero(newdir, sizeof(char) * 512);
				strcat(newdir, path);
				strcat(newdir, "/");
				strcat(newdir, ep->d_name);
				RecDir(newdir, 1);
			}
		}
	}
	closedir(dp);
}

int main(int argc, char **argv)
{
	RecDir("..", 1);
	return (0);
}
