#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i, j;
	char	**p;

	i = 0;
	p = NULL;
	argv = argv + 1;
	while (i < argc - 1)
	{
		p = calloc(i + 1, sizeof(p));
		if (!p)
			exit(1);

		int	k;
		k = 0;
		while (k <= i)
		{
			p[k] = argv[0 + k];
			k++;
		}
		k = 0;
		while (k <= i)
		{
			int	m;
			m = k;
			while (p[m] != NULL)
			{
				printf("[%s]", p[m]);
				m++;
			}
			printf(" ");
			k++;
		}
		printf("\n");

//		j = 0;
//		while (*(argv + j) != NULL)
//		{
//			printf("[%s]\n", *(argv + j));
//			j++;
//		}
		free(p);
		i++;
	}

	return (0);
}