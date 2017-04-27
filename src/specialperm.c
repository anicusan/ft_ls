#include "ft_ls.h"

void	usrspecial(struct stat dstat)
{
    if (dstat.st_mode & S_IXUSR)
    {
        if (dstat.st_mode & S_ISUID)
            ft_putchar('s');
        else
            ft_putchar('x');
    }
    else
    {
        if (dstat.st_mode & S_ISUID)
            ft_putchar('S');
        else
            ft_putchar('-');
    }
}

void	grpspecial(struct stat dstat)
{
    if (dstat.st_mode & S_IXGRP)
    {
        if (dstat.st_mode & S_ISGID)
            ft_putchar('s');
        else
            ft_putchar('x');
    }
    else
    {
        if (dstat.st_mode & S_ISGID)
            ft_putchar('S');
        else
            ft_putchar('-');
    }
}

void	othspecial(struct stat dstat)
{
    if (dstat.st_mode & S_IXOTH)
    {
        if (dstat.st_mode & S_ISVTX)
            ft_putchar('t');
        else
            ft_putchar('x');
    }
    else
    {
        if (dstat.st_mode & S_ISVTX)
            ft_putchar('T');
        else
            ft_putchar('-');
    }
}