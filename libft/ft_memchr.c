/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:23:10 by zcadwyl           #+#    #+#             */
/*   Updated: 2018/11/30 16:06:09 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char*)mem)[i] == (unsigned char)c)
			return ((void*)((unsigned char*)mem + i));
		++i;
	}
	return (NULL);
}
