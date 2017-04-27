#include "ft_ls.h"

int		name_compare(t_dir *node1, t_dir *node2)
{
	return (ft_strcmp(node1->d_name, node2->d_name));
}

int		time_accessed_compare(t_dir *node1, t_dir *node2)
{
	if (node2->dstat.st_atime != node1->dstat.st_atime)
		return (node2->dstat.st_atime - node1->dstat.st_atime);
	return (ft_strcmp(node1->d_name, node2->d_name));
}

int		time_modified_compare(t_dir *node1, t_dir *node2)
{
	if (node2->dstat.st_mtime != node1->dstat.st_mtime)
		return (node2->dstat.st_mtime - node1->dstat.st_mtime);
	return (ft_strcmp(node1->d_name, node2->d_name));
}

int		no_sort(t_dir *node1, t_dir *node2)
{
	(void)node1;
	(void)node2;
	return (-1);
}
