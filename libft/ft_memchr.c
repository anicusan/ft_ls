/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:05:18 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:05:34 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*ps;
	unsigned char		to_find;

	ps = (unsigned char*)s;
	to_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ps[i] == to_find)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
