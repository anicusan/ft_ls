/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 22:52:25 by anicusan          #+#    #+#             */
/*   Updated: 2016/07/12 00:38:43 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	int x;
	int y;
	int z;

	x = 0;
	z = 0;
	if (*(to_find) == '\0')
		return (str);
	while (*(str + x) != '\0' && x < (int)n)
	{
		y = x;
		z = 0;
		while (*(str + y) == *(to_find + z) && y < (int)n)
		{
			y++;
			z++;
			if (*(to_find + z) == '\0')
				return ((str + x));
		}
		x++;
	}
	return (NULL);
}
