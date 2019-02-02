/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:44:46 by zcadwyl           #+#    #+#             */
/*   Updated: 2018/11/30 16:06:03 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destptr, const void *srcptr, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)destptr)[i] = ((unsigned char*)srcptr)[i];
		if (((unsigned char*)srcptr)[i] == (unsigned char)c)
		{
			return ((void*)((unsigned char*)destptr + i + 1));
		}
		++i;
	}
	return (NULL);
}
