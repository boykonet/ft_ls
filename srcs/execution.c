#include "../ls.h"


void handle_dirs(char *path, unsigned char flags, int counter, int possible_files)
{
	t_fileinfo 		**files;
	char			newdir[512 + 1];
	long long		total;
	t_spaces		spaces;

	openreaddir(&files, path, is_flag(flags, A_FLAG_SHIFT, A_FLAG_NUM));

	if (counter > 0 || possible_files > 1)
	{
		ft_putstr_fd(path, 1);
		ft_putendl_fd(":", 1);
	}

	total = 0;
	for (int i = 0; files[i]; i++)
		set_fileinfo(files[i], &total);

	// count of spaces
	ispaces(&spaces);
	counter_of_spaces(files, &spaces);

	sort_by_flags(files, flags);

	print_files_from_dirs(files, total, spaces, is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM));

	char	**dirs = copy_dirs(files);

	size_t i;
	if (is_flag(flags, REC_FLAG_SHIFT, REC_FLAG_NUM) == 1)
	{
		i = 0;
		while (dirs[i])
		{
			if (counter >= 0 && dirs[i] != NULL)
				ft_putchar_fd('\n', 1);
			if (is_flag(flags, A_FLAG_SHIFT, A_FLAG_NUM) == 0 \
				&& ft_strncmp(dirs[i], ".", 1) == 0)
			{
				i++;
				continue ;
			}
			size_t	ldname = ft_strlen(dirs[i]);
			if (ft_strncmp(dirs[i], ".", ldname > 1 ? ldname : 1) != 0 \
			&& ft_strncmp(dirs[i], "..", ldname > 2 ? ldname : 2) != 0)
			{
				ft_bzero(newdir, sizeof(char) * (512 + 1));
				ft_strlcat(newdir, path, 512);
				ft_strlcat(newdir, "/", 512);
				ft_strlcat(newdir, dirs[i], 512);
				handle_dirs(newdir, flags, counter + 1, possible_files);
			}
			i++;
		}
	}
	free_2array((void**)dirs);
	free_2array((void**)files);
}


void handle_files(char **files, unsigned char flags)
{
	t_fileinfo 		**f;
	size_t			i;

	i = 0;
	f = ft_calloc(1, sizeof(t_fileinfo*));
	if (f == NULL)
	{
		perror("malloc");
		exit(1);
	}
	while (files[i])
	{
		t_fileinfo *ff = new_fileinfo(".", files[i], 0);
		if (ff == NULL)
		{
			perror("malloc");
			exit(1);
		}
		if (add_2array((void***)&f, ff) != 0)
		{
			perror("malloc");
			exit(1);
		}
		i++;
	}

	i = 0;
	while (f[i])
		set_fileinfo(f[i++], NULL);

	t_spaces spaces;
	ispaces(&spaces);
	counter_of_spaces(f, &spaces);

	sort_by_flags(f, flags);

	print_files_from_files(f, spaces, is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM));

	free_2array((void**)f);
	f = NULL;
}

static int	execute_files(char **files, unsigned char flags)
{
	if (files == NULL)
		return (-2);
	handle_files(files, flags);
	return (0);
}

static int	execute_dirs(char **dirs, unsigned char flags, int possible_files)
{
	size_t	i;

	i = 0;
	if (dirs == NULL)
		return (-2);
	while (dirs[i])
	{
		handle_dirs(dirs[i], flags, 0, possible_files);
		if (dirs[i + 1] != NULL)
			ft_putchar_fd('\n', 1);
		i++;
	}
	return (0);
}

void	execution(t_ls *ls)
{
	size_t	flen, dlen;

	flen = len_2array((const void**)ls->files);
	dlen = len_2array((const void**)ls->dirs);
	if (flen > 0)
		execute_files(ls->files, ls->flags);
	if (dlen > 0 && flen > 0)
		ft_putchar_fd('\n', 1);
	if (dlen > 0)
		execute_dirs(ls->dirs, ls->flags, ls->possible_files);
}
