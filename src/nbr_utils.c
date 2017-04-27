#include "ft_ls.h"

int			ft_nbrlen(int nb)
{
	int		i;

	i = 0;
	while (nb /= 10)
		i++;
	return (i);
}

int			ft_unsigned_nbrlen(unsigned int nb)
{
	unsigned int		i;

	i = 0;
	while (nb /= 10)
		i++;
	return (i);
}

void		ft_unsigned_putnbr(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = nb % 10;
	ft_putchar(nb + '0');
}
