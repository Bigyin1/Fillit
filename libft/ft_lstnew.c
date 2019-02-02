/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 23:54:47 by aezzeddi          #+#    #+#             */
/*   Updated: 2018/11/30 17:13:52 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	new->content = malloc(content_size);
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}
