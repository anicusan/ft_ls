#include "ft_ls.h"
#include <stdio.h>

void	get_more_info(t_dir *file, t_geninfo *geninfo)
{
	char	*path;
	char	*aux;

	aux = ft_strjoin(geninfo->path, "/");
	path = ft_strjoin(aux, file->d_name);
	free(aux);
	(void)lstat(path, &(file->dstat));
	if ((file->dstat).st_nlink > geninfo->max_nlink)
		geninfo->max_nlink = (file->dstat).st_nlink;
	if ((S_ISCHR((file->dstat).st_mode) || S_ISBLK((file->dstat).st_mode))
			&& geninfo->max_size < 10000000)
		geninfo->max_size = 10000000;
	else if ((file->dstat).st_size > geninfo->max_size)
		geninfo->max_size = (file->dstat).st_size;
	if (getpwuid((file->dstat).st_uid) == NULL)
		geninfo->max_uid = ft_strlen(ft_itoa(file->dstat.st_uid));
	else if (ft_strlen(getpwuid((file->dstat).st_uid)->pw_name) > geninfo->max_uid)
		geninfo->max_uid = ft_strlen(getpwuid((file->dstat).st_uid)->pw_name);
	if (ft_strlen(getgrgid((file->dstat).st_gid)->gr_name) > geninfo->max_gid)
		geninfo->max_gid = ft_strlen(getgrgid((file->dstat).st_gid)->gr_name);
	geninfo->max_blocks += (file->dstat).st_blocks;
	free(path);
}

void	ft_insert(t_geninfo *info, t_dir *node, t_dir *it, t_dir *prev)
{
	if (it == NULL)
	{
		node->prev = info->lastd;
		info->lastd->next = node;
		info->lastd = node;
	}
	else if (it->prev == NULL)
	{
		node->next = info->firstd;
		info->firstd->prev = node;
		info->firstd = node;
	}
	else
	{
		prev = it->prev;
		prev->next = node;
		node->next = it;
		it->prev = node;
		node->prev = prev;
	}
}

void	sort_insert(t_geninfo *info, t_dir *node,
		int (*cmp)(t_dir *, t_dir *))
{
	t_dir	*it;
	t_dir	*prev;

	prev = NULL;
	if (info->firstd == NULL)
	{
		info->firstd = node;
		info->lastd = node;
	}
	else {
		it = info->firstd;
		while (it != NULL && cmp(it, node) < 0)
			it = it->next;
		ft_insert(info, node, it, prev);
	}
}

void	insert_file(t_geninfo *info, t_args *args, t_dir *node)
{
	int		(*cmp)(t_dir *, t_dir *);
	
	cmp = name_compare;
	if (args->t)
	{
		cmp = time_modified_compare;
		if (args->u)
			cmp = time_accessed_compare;
	}
	if (args->f)
		cmp = no_sort;
	sort_insert(info, node, cmp);
}

void	insert_list(t_geninfo *info, struct dirent *dp, t_args *args)
{
	t_dir	*node;

	node = (t_dir*)malloc(sizeof(t_dir));
	node->d_name = (char*)malloc(sizeof(char) * (dp->d_namlen + 1));
	ft_strcpy(node->d_name, dp->d_name);
	if (args->l || args->t || args->u || args->upp_g || args->upp_r
			|| args->g)
		get_more_info(node, info);
	node->next = NULL;
	node->prev = NULL;
	insert_file(info, args, node);
}

void	generate_dir_list(DIR *dirp, t_args *args, t_geninfo *geninfo)
{
	struct dirent	*dp;

	while ((dp = readdir(dirp)) != NULL)
	{
		if (!(dp->d_name[0] == '.' && !args->a && !args->f))
			insert_list(geninfo, dp, args);
	}
	(void)closedir(dirp);
}
