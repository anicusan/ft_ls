/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:22:52 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:23:08 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlenz(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(const char *s1)
{
	char	*s2;
	int		n;

	n = ft_strlenz(s1);
	s2 = (char*)malloc(n + 1);
	while (n >= 0)
	{
		s2[n] = s1[n];
		n--;
	}
	return (s2);
}
