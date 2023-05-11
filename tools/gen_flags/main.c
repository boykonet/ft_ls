#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i, j;
	char	**p;

	if (argc == 1)
		return (0);


	argv = argv + 1;
	argc = argc - 1;

	i = 0;
	while (argv[i])
	{
		if (strlen(argv[i]) != 1)
		{
			write(2, "ERROR: INCORRECT INPUT\n", 23);
			exit(1);
		}
		i++;
	}

	p = NULL;

	p = calloc(argc + 1, sizeof(char*));
	if (p == NULL)
	{
		write(2, "MALLOC ERROR\n", 13);
		exit(1);
	}

	int ind = 0;
//	while (ind < argc)
//	{
		bzero(p, sizeof(char*) * (argc + 1));
		i = 0;

		int	number = 2;

		int	k = 0;
		while (k < number)
		{
			*(p + k) = argv[k];
			k++;
		}

		k = 0;
		while (p[number - 1] != NULL)
		{
			i = 0;
			while (i < (number - 1))
			{
				printf("%s", p[i]);
				i++;
			}
			printf("%s", p[i]);
			printf("\n");
			k++;
			p[i] = argv[i + k];
		}

//		ind++;
//	}

	i = 0;
	while (i < argc + 1)
	{
		 p[i] = NULL;
		 i++;
	}
	free(p);
	p = NULL;

	return (0);
}