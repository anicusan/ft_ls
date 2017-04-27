/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 20:24:06 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 19:41:30 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(int n, char *nbr)
{
	int		i;

	if (n > 9 || n < -9)
		rec(n / 10, nbr);
	n = n % 10;
	if (n < 0)
		n = -n;
	i = 0;
	while (nbr[i] != '\0')
		i++;
	nbr[i] = '0' + n;
}

char		*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	if (!(nbr = (char*)malloc(12)))
		return (NULL);
	i = 0;
	while (i < 12)
		nbr[i++] = '\0';
	if (n < 0)
		nbr[0] = '-';
	rec(n, nbr);
	return (nbr);
}
