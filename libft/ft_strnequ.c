/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:10:54 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:32:15 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*d1;
	char	*d2;

	d1 = (char*)s1;
	d2 = (char*)s2;
	while (*d1 && *d2 && n)
	{
		if (*d1++ != *d2++)
			return (0);
		n--;
	}
	if (n && *d1 != *d2)
		return (0);
	return (1);
}
