#include "ft_ls.h"

void		print_size(struct stat dstat, t_geninfo *geninfo)
{
	off_t	lsize;
	off_t	lmax;
	off_t	i;

	lsize = ft_nbrlen(dstat.st_size);
	lmax = ft_nbrlen(geninfo->max_size);
	i = 0;
	while (i++ < lmax - lsize)
		ft_putchar(' ');
	ft_putnbr((int)dstat.st_size);
	ft_putchar(' ');
}

void		print_date(time_t date)
{
	char	*str1;
	char	*str2;
	time_t	actualtime;

	actualtime = time(0);
	str1 = ctime(&date);
	if ((actualtime - 15778463) > date || actualtime < date)
	{
		str2 = ft_memalloc(sizeof(char) * 6);
		str2 = ft_strsub(str1, 24, 5);
		str1 = ft_strsub(str1, 4, 6);
		str1 = ft_strjoin(str1, "  ");
		str1 = ft_strjoin(str1, str2);
		str1[13] = '\0';
		free(str2);
	}
	else
	{
		str1 = ft_strsub(str1, 4, 12);
		str1[12] = '\0';
	}
	ft_putstr(str1);
	ft_putchar(' ');
	free(str1);
}

void		print_lnkderef(char *dpath, t_geninfo *geninfo)
{
	int		psize;
	char	*deref;
	char	*lnpath;
	char	*aux;

	deref = (char*)malloc(sizeof(char) * 1024);
	aux = ft_strjoin(geninfo->path, "/");
	lnpath = ft_strjoin(aux, dpath);
	psize = readlink(lnpath, deref, 1024);
	if (psize > 0)
	{
		deref[psize] = '\0';
		ft_putstr(" -> ");
		ft_putstr(deref);
	}
	free(aux);
	free(deref);
	free(lnpath);
}

void		print_size_speshul(struct stat dstat)
{
	unsigned int	i;
	unsigned int	majmin;
	unsigned int	lsize;

	majmin = major(dstat.st_rdev);
	i = 0;
	lsize = ft_unsigned_nbrlen(majmin);
	while (i++ < 2 - lsize)
		ft_putchar(' ');
	ft_unsigned_putnbr(majmin);
	ft_putchar(',');
	majmin = minor(dstat.st_rdev);
	lsize = ft_unsigned_nbrlen(majmin);
	i = 0;
	while (i++ < 3 - lsize)
		ft_putchar(' ');
	ft_unsigned_putnbr(majmin);
	ft_putchar(' ');
}
