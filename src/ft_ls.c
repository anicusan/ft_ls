#include "ft_ls.h"

void		destroy_t_dir(t_dir *it)
{
	if (it->next != NULL)
		destroy_t_dir(it->next);
	free(it->d_name);
	free(it);
}

void		reset_geninfo(t_geninfo *geninfo)
{
	geninfo->path = NULL;
	geninfo->firstd = NULL;
	geninfo->lastd = NULL;
	geninfo->max_blocks = 0;
	geninfo->max_uid = 0;
	geninfo->max_gid = 0;
	geninfo->max_size = 0;
	geninfo->max_nlink = 0;
	geninfo->is_files = 0;
	geninfo->is_valid = 1;
}

void		call_recursion(t_dir *iterator, t_args *args,
		t_geninfo *geninfo, char *path)
{
	char	*aux;

	if (S_ISDIR(iterator->dstat.st_mode) &&
			ft_strcmp(iterator->d_name, ".") != 0 &&
			ft_strcmp(iterator->d_name, "..") != 0)
	{
		aux = ft_strjoin(path, "/");
		geninfo->path = ft_strjoin(aux, iterator->d_name);
		free(aux);
		ft_putchar('\n');
		ft_putstr(geninfo->path);
		ft_putstr(":\n");
		ft_ls(args, geninfo);
	}
}

void		make_recursion(t_args *args, t_geninfo *geninfo)
{
	char	*path;
	t_dir	*iterator;
	t_dir	*list_begin;

	iterator = geninfo->firstd;
	if (args->r)
		iterator = geninfo->lastd;
	list_begin = geninfo->firstd;
	path = geninfo->path;
	reset_geninfo(geninfo);
	while (iterator != NULL)
	{
		call_recursion(iterator, args, geninfo, path);
		if (!args->r)
			iterator = iterator->next;
		else
			iterator = iterator->prev;
	}
	if (list_begin != NULL)
		destroy_t_dir(list_begin);
}

void		ft_ls(t_args *args, t_geninfo *geninfo)
{
	DIR			*dirp;
	char		*error_message;

	dirp = NULL;
	dirp = opendir(geninfo->path);
	if (dirp != NULL)
		generate_dir_list(dirp, args, geninfo);
	else
	{
		if (errno == ENOTDIR)
		{
			geninfo->is_valid = 0;
			return ;
		}
		if (ft_strchr(geninfo->path, '/') != NULL)
			error_message = ft_strjoin("ft_ls: ",
					ft_strrchr(geninfo->path, '/') + 1);
		else
			error_message = ft_strjoin("ft_ls: ",
					geninfo->path);
		perror(error_message);
		free(error_message);
		return ;
	}
	ls_display(args, geninfo);
	if (args->upp_r)
		make_recursion(args, geninfo);
}
