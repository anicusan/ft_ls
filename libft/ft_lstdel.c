/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:01:19 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:01:36 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = *alst;
	while (aux1 != NULL)
	{
		aux2 = aux1->next;
		ft_lstdelone(&aux1, del);
		aux1 = aux2;
	}
	if (*alst)
		*alst = NULL;
}
