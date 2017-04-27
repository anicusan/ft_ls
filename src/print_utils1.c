#include "ft_ls.h"

void		print_total(t_geninfo *geninfo)
{
	if (!geninfo->is_files && geninfo->firstd != NULL)
	{
		ft_putstr("total ");
		ft_putnbr(geninfo->max_blocks);
		ft_putchar('\n');
	}
}

void		print_access(struct stat dstat)
{
	(S_ISFIFO(dstat.st_mode)) ? ft_putchar('p') : NULL;
	(S_ISCHR(dstat.st_mode)) ? ft_putchar('c') : NULL;
	(S_ISDIR(dstat.st_mode)) ? ft_putchar('d') : NULL;
	(S_ISBLK(dstat.st_mode)) ? ft_putchar('b') : NULL;
	(S_ISREG(dstat.st_mode)) ? ft_putchar('-') : NULL;
	(S_ISLNK(dstat.st_mode)) ? ft_putchar('l') : NULL;
	(S_ISSOCK(dstat.st_mode)) ? ft_putchar('s') : NULL;
	ft_putchar((dstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((dstat.st_mode & S_IWUSR) ? 'w' : '-');
	usrspecial(dstat);
	ft_putchar((dstat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((dstat.st_mode & S_IWGRP) ? 'w' : '-');
	grpspecial(dstat);
	ft_putchar((dstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((dstat.st_mode & S_IWOTH) ? 'w' : '-');
	othspecial(dstat);
	ft_putstr("  ");
}

void		print_links(struct stat dstat, t_geninfo *geninfo)
{
	int	lsize;
	int	lmax;
	int	i;

	lsize = ft_nbrlen((int)dstat.st_nlink);
	lmax = ft_nbrlen((int)geninfo->max_nlink);
	i = 0;
	while (i++ < lmax - lsize)
		ft_putchar(' ');
	ft_putnbr((int)dstat.st_nlink);
	ft_putchar(' ');
}

void		print_uid(struct stat dstat, t_geninfo *geninfo)
{
	size_t	lsize;
	size_t	i;

	if (getpwuid(dstat.st_uid) != NULL)
	{
		lsize = ft_strlen(getpwuid(dstat.st_uid)->pw_name);
		ft_putstr(getpwuid(dstat.st_uid)->pw_name);
	}
	else
	{
		lsize = ft_strlen(ft_itoa(dstat.st_uid));
		ft_putnbr(dstat.st_uid);
	}
	i = 0;
	while (i++ < geninfo->max_uid - lsize)
		ft_putchar(' ');
	ft_putstr("  ");
}

void		print_gid(struct stat dstat, t_geninfo *geninfo)
{
	size_t	lsize;
	size_t	i;

	lsize = ft_strlen(getgrgid(dstat.st_gid)->gr_name);
	ft_putstr(getgrgid(dstat.st_gid)->gr_name);
	i = 0;
	while (i++ < geninfo->max_gid - lsize)
		ft_putchar(' ');
	ft_putstr("  ");
}
