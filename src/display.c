#include "ft_ls.h"
#include <stdio.h>

void		simple_print(t_dir *cdir, t_args *args)
{
	if (args->upp_g)
	{
		S_ISREG((cdir->dstat).st_mode) ? ft_putstr(C_NONE) : NULL;
		(cdir->dstat).st_mode & S_IXUSR ? ft_putstr(C_RED) : NULL;
		S_ISBLK((cdir->dstat).st_mode) ? ft_putstr(C_RED) : NULL;
		S_ISCHR((cdir->dstat).st_mode) ? ft_putstr(C_BLUE) : NULL;
		S_ISDIR((cdir->dstat).st_mode) ? ft_putstr(C_CYAN) : NULL;
		S_ISFIFO((cdir->dstat).st_mode) ? ft_putstr(C_BROWN) : NULL;
		S_ISLNK((cdir->dstat).st_mode) ? ft_putstr(C_GREEN) : NULL;
		S_ISSOCK((cdir->dstat).st_mode) ? ft_putstr(C_MAGENTA) : NULL;
		ft_putstr(cdir->d_name);
		ft_putstr(C_NONE);
	}
	else
		ft_putstr(cdir->d_name);
	if (!args->l)
		ft_putchar('\n');
}

void		long_print(t_args *args, t_geninfo *geninfo, t_dir *cdir)
{
	print_access(cdir->dstat);
	print_links(cdir->dstat, geninfo);
	if (!args->g)
		print_uid(cdir->dstat, geninfo);
	print_gid(cdir->dstat, geninfo);
	if (S_ISCHR(cdir->dstat.st_mode) || S_ISBLK(cdir->dstat.st_mode))
		print_size_speshul(cdir->dstat);
	else
		print_size(cdir->dstat, geninfo);
	if (args->t && args->u)
		print_date((cdir->dstat).st_atime);
	else
		print_date((cdir->dstat).st_mtime);
	simple_print(cdir, args);
	if (S_ISLNK((cdir->dstat).st_mode))
		print_lnkderef(cdir->d_name, geninfo);
	if (!args->g || args->l)
		ft_putchar('\n');
}

void		ft_call_print(t_dir *cdir, t_args *args, t_geninfo *geninfo)
{
	if (args->l || args->g)
		long_print(args, geninfo, cdir);
	else
		simple_print(cdir, args);
}

void		list_print(t_args *args, t_geninfo *geninfo)
{
	t_dir	*cdir;

	if (args->l || args->g)
		print_total(geninfo);
	if (args->r)
	{
		cdir = geninfo->lastd;
		while (cdir != NULL)
		{
			ft_call_print(cdir, args, geninfo);
			cdir = cdir->prev;
		}
	}
	else
	{
		cdir = geninfo->firstd;
		while (cdir != NULL)
		{
			ft_call_print(cdir, args, geninfo);
			cdir = cdir->next;
		}
	}
}

void		ls_display(t_args *args, t_geninfo *geninfo)
{
	if (!geninfo->onepath && !geninfo->is_files)
	{
		ft_putstr(geninfo->path);
		ft_putstr(":\n");
	}
	list_print(args, geninfo);
}
