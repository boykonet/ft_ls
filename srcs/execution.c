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

int	to_fileinfo(t_fileinfo ***files, char **filenames, char *path)
{
	size_t	i;
	int		ecode;

	i = 0;
	if (files == NULL || filenames == NULL)
		return (ERR_CODE_NULL_PARAMETER);
	while (filenames[i])
	{
		t_fileinfo *file = new_fileinfo(path, filenames[i]);
		if (file == NULL)
		{
			free_2array_content((void **)(*files));
			return (ERR_CODE_MALLOC_ERROR);
		}
		ecode = add_2array((void***)files, file);
		if (ecode != 0)
		{
			free(file);
			file = NULL;
			free_2array_content((void **)(*files));
			return (ERR_CODE_MALLOC_ERROR);
		}
		i++;
	}
	return (0);
}

static int	set_to_fileinfo(t_fileinfo ***files, char **filenames, char *path, unsigned char flags)
{
	int		ecode;
	size_t	i;

	*files = (t_fileinfo**)ft_calloc(1, sizeof(t_fileinfo*));
	if (*files == NULL)
		return (ERR_CODE_MALLOC_ERROR);
	ecode = to_fileinfo(files, filenames, path);
	if (ecode != 0)
	{
		free_2array((void**)*files);
		files = NULL;
		return (ecode);
	}
	i = 0;
	while ((*files)[i])
	{
		ecode = set_fileinfo((*files)[i], NULL);
		if (ecode != 0)
		{
			free_2array((void**)*files);
			files = NULL;
			return (ecode);
		}
		i++;
	}

	sort_by_flags(*files, flags);
	return (0);
}

static int handle_dirs(char *path, unsigned char flags, int counter, int possible_files)
{
	t_fileinfo 		**files;
	char 			**filenames;
	char			newdir[512 + 1];
	long long		total;
	int				ecode;
	char			**dirs;
	size_t			i, flen;

	files = NULL;
	ecode = openreaddir(&filenames, path, is_flag(flags, A_FLAG_SHIFT, A_FLAG_NUM));
	if (ecode != 0)
		return (ecode);

	ecode = to_fileinfo(&files, filenames, path);
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
	i = 0;
	flen = len_2array((const void **)files);
	while (i < flen)
	{
		ecode = set_fileinfo(files[i], &total);
		if (ecode != 0)
		{
			free_2array((void**)files);
			files = NULL;
			return (ecode);
		}
		i++;
	}
	sort_by_flags(files, flags);

	print_files_from_dirs(files, total, is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM));

	dirs = copy_dirs(files);
	free_2array((void**)files);
	files = NULL;
	if (dirs == NULL)
		return (ERR_CODE_MALLOC_ERROR);

	if (is_flag(flags, REC_FLAG_SHIFT, REC_FLAG_NUM) == 1)
	{
		i = 0;
		while (dirs[i])
		{
			if (rec_checks(dirs[i], flags) != 0)
			{
				i++;
				continue ;
			}
			set_path(path, dirs[i], newdir);
			ft_putchar_fd('\n', 1);
			handle_dirs(newdir, flags, counter + 1, possible_files);
			i++;
		}
	}
	free_2array((void**)dirs);
	dirs = NULL;
	return (0);
}

static int handle_files(char **filenames, unsigned char flags)
{
	t_fileinfo 		**files;
	int				ecode;

	if (filenames == NULL)
		return (ERR_CODE_NULL_PARAMETER);
	ecode = set_to_fileinfo(&files, filenames, "", flags);
	if (ecode != 0)
		return (ecode);
	print_files_from_files(files, is_flag(flags, L_FLAG_SHIFT, L_FLAG_NUM));
	free_2array((void**)files);
	files = NULL;
	return (0);
}

static int	execute_files(char **files, unsigned char flags, t_pattern p[MAX_ERROR_PATTERNS])
{
	int		ecode;

	if (files == NULL)
		return (ERR_CODE_NULL_PARAMETER);
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
	t_fileinfo	**dirinfo;
	char 		**sorted_dirs;
	size_t		i;
	int			ecode;

	i = 0;
	dirinfo = NULL;
	if (dirs == NULL)
		return (ERR_CODE_NULL_PARAMETER);
	ecode = set_to_fileinfo(&dirinfo, dirs, "", flags);
	if (ecode != 0)
	{
		handle_ecodes(ecode, NULL, p);
		return (ecode);
	}
	sorted_dirs = copy_dirs(dirinfo);
	free_2array((void**)dirinfo);
	dirinfo = NULL;
	if (sorted_dirs == NULL)
	{
		handle_ecodes(ecode, NULL, p);
		return (ERR_CODE_MALLOC_ERROR);
	}
	while (sorted_dirs[i])
	{
		ecode = handle_dirs(sorted_dirs[i], flags, 0, possible_files);
		if (ecode != 0)
		{
			free_2array((void**)sorted_dirs);
			sorted_dirs = NULL;
			handle_ecodes(ecode, NULL, p);
			return (ecode);
		}
		if (dirs[i + 1] != NULL)
			ft_putchar_fd('\n', 1);
		i++;
	}
	free_2array((void**)sorted_dirs);
	sorted_dirs = NULL;
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
