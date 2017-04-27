#include "ft_ls.h"

int		set_rest_flags(char c, t_args *args)
{
	if (c == 'f')
		return ((args->f = 1));
	if (c == 'g')
		return ((args->g = 1));
	if (c == 'G')
		return ((args->upp_g = 1));
	if (c == '1')
	{
		args->l = 0;
		return ((args->one = 1));
	}
	return (-1);
}

int		is_set_flag(char c, t_args *args)
{
	if (c == 'l')
	{
		args->one = 0;
		return ((args->l = 1));
	}
	if (c == 'r')
		return ((args->r = 1));
	if (c == 'R')
		return ((args->upp_r = 1));
	if (c == 'a')
		return ((args->a = 1));
	if (c == 't')
		return ((args->t = 1));
	if (c == 'u')
		return ((args->u = 1));
	return (set_rest_flags(c, args));
}

int		flag_err(char c)
{
	char	*str;
	int		len;

	str = (char*)malloc(sizeof(char) * 50);
	ft_strcpy(str, "ls: illegal option -- ");
	len = ft_strlen(str);
	str[len] = c;
	str[len + 1] = '\0';
	ft_strcat(str, "\nusage: ls [-lrRatufgd1] [file ...]\n");
	ft_putstr_fd(str, 2);
	return (-1);
}

int		argstring(char *s, t_args *args)
{
	int		i;

	i = 1;
	while (s[i] != '\0')
	{
		if (is_set_flag(s[i], args) < 0)
			return (flag_err(s[i]));
		i++;
	}
	return (1);
}

int		set_args(t_args *args, char **av, int ac)
{
	int		i;

	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] != '\0')
	{
		if (av[i][1] == '-')
		{
			i++;
			break ;
		}
		if (argstring(av[i], args) < 0)
			return (-1);
		i++;
	}
	if (i == ac)
		return (0);
	else
		return (i);
}
