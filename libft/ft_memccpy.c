/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:04:55 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:05:06 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	while (n--)
	{
		*d = *s;
		if (*s == c)
			return ((void*)(d + 1));
		d++;
		s++;
	}
	return (NULL);
}
