/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:03:31 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:04:00 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*new_temp;

	if (lst)
	{
		new = f(lst);
		new_temp = new;
	}
	else
	{
		new = NULL;
		return (new);
	}
	while (lst->next)
	{
		new_temp->next = f(lst->next);
		new_temp = new_temp->next;
		lst = lst->next;
	}
	return (new);
}
