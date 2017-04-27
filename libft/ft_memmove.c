/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:06:57 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:07:34 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ptrlt(char *d, char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		if (s + i == d)
			return (1);
		i++;
	}
	return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	if (ptrlt(d, s, n))
		while (n--)
			*(d + n) = *(s + n);
	else
		while (n--)
			*(d++) = *(s++);
	return (dst);
}
