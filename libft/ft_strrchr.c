/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:33:20 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:33:43 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sc;
	char	ch;

	sc = (char*)s;
	ch = (char)c;
	while (*sc != '\0')
		sc++;
	while (*sc != ch && sc != (char*)s)
		sc--;
	if (*sc == ch)
		return (sc);
	return (NULL);
}
