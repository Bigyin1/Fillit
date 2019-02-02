/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:11:20 by zcadwyl           #+#    #+#             */
/*   Updated: 2018/11/30 16:04:34 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int val, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		((unsigned char*)b)[i] = (unsigned char)val;
		++i;
	}
	return (b);
}
