/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicusan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:04:10 by anicusan          #+#    #+#             */
/*   Updated: 2017/01/22 20:04:19 by anicusan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*content_cpy;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		content_cpy = malloc(content_size);
		content_cpy = ft_memcpy(content_cpy, content, content_size);
		new->content = content_cpy;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
