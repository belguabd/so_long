/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:01:56 by belguabd          #+#    #+#             */
/*   Updated: 2023/11/14 17:23:19 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sourc;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	if (dest > sourc)
	{
		while (len--)
		{
			dest[len] = sourc[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = sourc[i];
			i++;
		}
	}
	return (dest);
}
