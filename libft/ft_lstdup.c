/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:02:46 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:02:58 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new;
	t_list	*new_temp;

	if (lst)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		new_temp = new->next;
		lst = lst->next;
	}
	else
		new = NULL;
	while (lst)
	{
		new_temp = ft_lstnew(lst->content, lst->content_size);
		new_temp = new_temp->next;
		lst = lst->next;
	}
	return (new);
}
