/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:47:54 by belguabd          #+#    #+#             */
/*   Updated: 2023/11/07 01:51:16 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	int				to_find;
	size_t			len_str;
	int				i;

	len_str = ft_strlen(s);
	str = (unsigned char *)s;
	if ((const char)c == 0)
		return ((char *)(str + len_str));
	i = 0;
	to_find = -1;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			to_find = i;
		i++;
	}
	if (to_find == -1)
		return (0);
	return ((char *)(str + to_find));
}
