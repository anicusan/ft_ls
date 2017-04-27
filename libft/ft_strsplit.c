/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 19:11:32 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:35:07 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(char const *s, char c)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (i && (s[i] == c || s[i] != '\0') && s[i - 1] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

static size_t	ft_strlenz(const char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

static char		*ft_strdupz(const char *s1)
{
	char	*s2;
	int		n;

	n = ft_strlenz(s1) + 1;
	s2 = (char*)malloc(n);
	while (n >= 0)
	{
		s2[n] = s1[n];
		n--;
	}
	return (s2);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**lst;
	int		i;
	int		j;
	char	*ds;

	ds = ft_strdupz(s);
	lst = (char**)malloc(count(s, c) + 1);
	lst[0] = NULL;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	j = 0;
	if (s[i] == '\0')
		return (lst);
	while (s[i])
	{
		if (s[i] == c)
			ds[i] = '\0';
		else if (i == 0 || s[i - 1] == c)
			lst[j++] = ds + i;
		i++;
	}
	lst[j] = NULL;
	return (lst);
}
