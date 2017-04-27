/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:29:54 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:36:36 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_strlenz(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	char	*d;
	int		i;

	if (!(new = (char*)malloc(ft_strlenz(s) + 1)))
		return (NULL);
	i = 0;
	d = (char*)s;
	while ((*d == ' ' || *d == '\t' || *d == '\n') && *d != '\0')
		d++;
	while (*d != '\0')
		new[i++] = *d++;
	new[i] = '\0';
	i--;
	while (new[i] == ' ' || new[i] == '\n' || new[i] == '\t')
		new[i--] = '\0';
	return (new);
}
