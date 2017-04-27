/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 16:07:59 by anicusan          #+#    #+#             */
/*   Updated: 2016/12/28 20:49:57 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb >= 10 || nb <= -10)
		ft_putnbr_fd(nb / 10, fd);
	if (nb < 0 && nb > -10)
	{
		ft_putchar_fd('-', fd);
	}
	nb = nb % 10;
	if (nb > 0)
		ft_putchar_fd(nb + '0', fd);
	else
		ft_putchar_fd(-nb + '0', fd);
}
