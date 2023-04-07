#include "../ls.h"

int	rec_checks(char *dir, unsigned char flags)
{
	size_t	ldname;

	ldname = ft_strlen(dir);
	if (is_flag(flags, A_FLAG_SHIFT, A_FLAG_NUM) == 0 && ft_strncmp(dir, ".", 1) == 0)
		return (1);

	if (ft_strncmp(dir, ".", ldname > 1 ? ldname : 1) == 0 || ft_strncmp(dir, "..", ldname > 2 ? ldname : 2) == 0)
		return (1);
	return (0);
}

void	set_path(char *path, char *dir, char newdir[512 + 1])
{
	ft_bzero(newdir, sizeof(char) * (512 + 1));
	ft_strlcat(newdir, path, 512);
	ft_strlcat(newdir, "/", 512);
	ft_strlcat(newdir, dir, 512);
}

int	filenames_to_fileinfo(t_fileinfo ***files, char **filenames, char *path)
{
	size_t	i;
	int		ecode;

	i = 0;
	if (files == NULL || filenames == NULL)
		return (-2);
	while (filenames[i])
	{
		t_fileinfo *file = new_fileinfo(path, filenames[i]);
		if (file == NULL)
		{
			free_2array_content((void **)(*files));
			return (-1);
		}
		ecode = add_2array((void***)files, file);
		if (ecode != 0)
		{
			free(file);
			file = NULL;
			free_2array_content((void **)(*files));
			return (-1);
		}
		i++;
	}
	return (0);
}

int handle_dirs(char *path, unsigned char flags, int counter, int possible_files)
{
	t_fileinfo 		**files;
	char 			**filenames;
	char			newdir[512 + 1];
	long long		total;
	int				ecode;
	char			**dirs;

	files = NULL;
	ecode = openreaddir(&filenames, path, is_flag(flags, A_FLAG_SHIFT, A_FLAG_NUM));
	if (ecode != 0)
		return (ecode);

	ecode = filenames_to_fileinfo(&files, filenames, path);
	free_2array((void**)filenames);
	filenames = NULL;
	if (ecode != 0)
	{
		free_2array((void**)files);
		files = NULL;
		return (ecode);
	}

	if (counter > 0 || possible_files > 1)
	{
		ft_putstr_fd(path, 1);
		ft_putendl_fd(":", 1);
	}

	total = 0;
	for (int i = 0; files[i]; i++)
	{
		ecode = set_fileinfo(files[i], &total);
		if (ecode != 0)
		{
			free_2array((void**)files);
			files = NULL;
			return (ecode);
		}
	}

	sort_by_flags(files, flags);

	print_files_from_dirs(files, total, is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM));

	dirs = copy_dirs(files);
	free_2array((void**)files);
	files = NULL;
	if (dirs == NULL)
		return (-1);

	size_t i;
	if (is_flag(flags, REC_FLAG_SHIFT, REC_FLAG_NUM) == 1)
	{
		i = 0;
		while (dirs[i])
		{
			if (counter >= 0 && dirs[i] != NULL)
				ft_putchar_fd('\n', 1);
			if (rec_checks(dirs[i], flags) != 0)
			{
				i++;
				continue ;
			}
			set_path(path, dirs[i], newdir);
			handle_dirs(newdir, flags, counter + 1, possible_files);
			i++;
		}
	}
	free_2array((void**)dirs);
	dirs = NULL;
	return (0);
}

int handle_files(char **filenames, unsigned char flags)
{
	t_fileinfo 		**files;
	size_t			i;
	int				ecode;

	if (filenames == NULL)
		return (-2);
	files = (t_fileinfo**)ft_calloc(1, sizeof(t_fileinfo*));
	if (files == NULL)
		return (-1);
	ecode = filenames_to_fileinfo(&files, filenames, ".");
	if (ecode != 0)
	{
		free_2array((void**)files);
		files = NULL;
		return (ecode);
	}
	i = 0;
	while (files[i])
	{
		ecode = set_fileinfo(files[i], NULL);
		if (ecode != 0)
		{
			free_2array((void**)files);
			files = NULL;
			return (ecode);
		}
		i++;
	}

	sort_by_flags(files, flags);

	print_files_from_files(files, is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM));

	free_2array((void**)files);
	files = NULL;
	return (0);
}

void	handle_ecodes(int ecode, char *filename, t_pattern p[MAX_ERROR_PATTERNS])
{
	if (ecode == -1)
		add_pattern(p, PATTERN_MALLOC_ERROR, strerror(errno));
	else if (ecode == -3)
		add_pattern(p, PATTERN_STRERROR_MESSAGE, strerror(errno));
	else if (ecode == -5 && filename != NULL)
	{
		add_pattern(&p[0], PATTERN_FILE_ERROR_FILENAME, filename);
		add_pattern(&p[1], PATTERN_FILE_ERROR_MESSAGE, strerror(errno));
	}
}

static int	execute_files(char **files, unsigned char flags, t_pattern p[MAX_ERROR_PATTERNS])
{
	int		ecode;

	if (files == NULL)
		return (-2);
	ecode = handle_files(files, flags);
	if (ecode != 0)
	{
		handle_ecodes(ecode, NULL, p);
		return (ecode);
	}
	return (0);
}

static int	execute_dirs(char **dirs, unsigned char flags, int possible_files, t_pattern p[MAX_ERROR_PATTERNS])
{
	size_t	i;
	int		ecode;

	i = 0;
	if (dirs == NULL)
		return (-2);
	while (dirs[i])
	{
		ecode = handle_dirs(dirs[i], flags, 0, possible_files);
		if (ecode != 0)
		{
			handle_ecodes(ecode, NULL, p);
			return (ecode);
		}
		if (dirs[i + 1] != NULL)
			ft_putchar_fd('\n', 1);
		i++;
	}
	return (0);
}

void	execution(t_ls *ls)
{
	size_t	flen, dlen;
	int 	ecode;

	flen = len_2array((const void**)ls->files);
	dlen = len_2array((const void**)ls->dirs);
	if (flen > 0)
	{
		ecode = execute_files(ls->files, ls->flags, ls->epatterns);
		handle_error(ecode, ls->epatterns, &ls->global_ecode);
	}
	if (dlen > 0 && flen > 0)
		ft_putchar_fd('\n', 1);
	if (dlen > 0)
	{
		ecode = execute_dirs(ls->dirs, ls->flags, ls->possible_files, ls->epatterns);
		handle_error(ecode, ls->epatterns, &ls->global_ecode);
	}
}
