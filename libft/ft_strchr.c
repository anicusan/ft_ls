/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:19:19 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:20:09 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sc;
	char	ch;

	sc = (char*)s;
	ch = (char)c;
	while (*sc != ch && *sc != '\0')
		sc++;
	if (*sc == ch)
		return (sc);
	return (NULL);
}
