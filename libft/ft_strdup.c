/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:10:28 by zcadwyl           #+#    #+#             */
/*   Updated: 2018/11/30 16:04:04 by zcadwyl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*res;
	char	*ret;

	len = 0;
	while (str[len])
		len++;
	res = (char*)malloc(len + 1);
	if (!res)
		return (NULL);
	ret = res;
	while (*str)
		*res++ = *str++;
	*res = '\0';
	return (ret);
}
