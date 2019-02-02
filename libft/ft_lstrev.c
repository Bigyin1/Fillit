/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:04:30 by zcadwyl           #+#    #+#             */
/*   Updated: 2019/02/02 18:05:43 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **alst)
{
	t_list	*last;
	t_list	*cur;
	t_list	*next;

	last = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = last;
		last = cur;
		cur = next;
	}
	*alst = last;
}
