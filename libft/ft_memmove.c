/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:09:31 by zcadwyl           #+#    #+#             */
/*   Updated: 2018/12/06 11:51:49 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*csrc;
	unsigned char	*cdst;
	size_t			i;

	i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	if (csrc < cdst)
		while (len--)
			*(cdst + len) = *(csrc + len);
	else
		while (i < len)
		{
			*(cdst + i) = *(csrc + i);
			i++;
		}
	return (dst);
}
