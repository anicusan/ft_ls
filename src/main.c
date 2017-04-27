#include "ft_ls.h"

t_args		*init_args(void)
{
	t_args	*args_zero;

	args_zero = (t_args*)malloc(sizeof(t_args));
	args_zero->l = 0;
	args_zero->r = 0;
	args_zero->upp_r = 0;
	args_zero->a = 0;
	args_zero->t = 0;
	args_zero->u = 0;
	args_zero->f = 0;
	args_zero->g = 0;
	args_zero->one = 0;
	return (args_zero);
}

t_geninfo	*init_geninfo(void)
{
	t_geninfo	*newgen;

	newgen = (t_geninfo*)malloc(sizeof(t_geninfo));
	newgen->max_size = 0;
	newgen->max_uid = 0;
	newgen->max_gid = 0;
	newgen->max_nlink = 0;
	newgen->max_blocks = 0;
	newgen->onepath = 0;
	newgen->firstd = NULL;
	newgen->lastd = NULL;
	newgen->is_files = 0;
	newgen->is_valid = 1;
	return (newgen);
}

void		sort_params(char **files, int size)
{
	int		ok;
	int		i;
	char	*aux;

	ok = 1;
	while (ok)
	{
		ok = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(files[i], files[i + 1]) > 0)
			{
				ok = 1;
				aux = files[i];
				files[i] = files[i + 1];
				files[i + 1] = aux;
			}
			i++;
		}
	}
}

void		verify_files(char **files, t_dto *dto)
{
	int			i;
	struct stat	dstat;
	t_dir		*node;

	i = 0;
	dto->size_dir = 0;
	dto->geninfo->path = ft_strdup(".");
	dto->geninfo->is_files = 1;
	while (i < dto->size)
	{
		if (lstat(files[i], &dstat) == 0 && !S_ISDIR(dstat.st_mode))
		{
			node = (t_dir*)malloc(sizeof(t_dir));
			node->d_name = ft_strdup(files[i]);
			node->next = NULL;
			node->prev = NULL;
			get_more_info(node, dto->geninfo);
			insert_file(dto->geninfo, dto->args, node);
		}
		else if (S_ISDIR(dstat.st_mode))
			dto->size_dir += 1;
		i++;
	}
	if (dto->geninfo->firstd != NULL)
		ls_display(dto->args, dto->geninfo);
}

void		more_paths(t_dto dto)
{
	char	**files;
	int		i;

	i = 0;
	files = (char**)malloc(sizeof(char*) * (dto.argc - dto.first_path + 1));
	while (dto.first_path < dto.argc)
		files[i++] = dto.argv[dto.first_path++];
	dto.size = i;
	i = 0;
	verify_files(files, &dto);
	if (dto.geninfo->firstd != NULL && dto.size_dir > 0)
		ft_putchar('\n');
	reset_geninfo(dto.geninfo);
	sort_params(files, dto.size);
	while (i < dto.size)
	{
		dto.geninfo->path = files[i];
		ft_ls(dto.args, dto.geninfo);
		if (dto.geninfo->is_valid && (dto.size_dir)-- > 1)
			ft_putchar('\n');
		reset_geninfo(dto.geninfo);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_args		*args;
	t_geninfo	*geninfo;
	t_dto		dto;

	args = init_args();
	dto.first_path = set_args(args, argv, argc);
	geninfo = init_geninfo();
	dto.geninfo = geninfo;
	dto.argc = argc;
	dto.argv = argv;
	dto.args = args;
	if (dto.first_path == argc - 1 || dto.first_path == 0)
		geninfo->onepath = 1;
	if (dto.first_path < 0)
		return (0);
	if (dto.first_path)
		more_paths(dto);
	else
	{
		geninfo->path = ".";
		ft_ls(args, geninfo);
	}
	return (0);
}
