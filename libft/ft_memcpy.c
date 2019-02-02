/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:36:44 by zcadwyl           #+#    #+#             */
/*   Updated: 2018/11/30 16:05:09 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		((unsigned char*)destptr)[i] = ((unsigned char*)srcptr)[i];
		++i;
	}
	return (destptr);
}
