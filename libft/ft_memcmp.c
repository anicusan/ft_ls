/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:05:46 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:05:59 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*ps1;
	unsigned char		*ps2;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (n--)
		if (*(ps1++) != *(ps2++))
			return ((int)*(ps1 - 1) - (int)*(ps2 - 1));
	return (0);
}
