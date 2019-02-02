/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:31:35 by zcadwyl           #+#    #+#             */
/*   Updated: 2018/11/30 16:10:06 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char *)memptr1)[i] \
		!= ((unsigned char *)memptr2)[i])
		{
			return (((unsigned char *)memptr1)[i] \
			- ((unsigned char *)memptr2)[i]);
		}
		++i;
	}
	return (0);
}
