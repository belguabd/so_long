/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:17:56 by belguabd          #+#    #+#             */
/*   Updated: 2023/11/11 23:18:20 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newstr;

	newstr = (t_list *)malloc(sizeof(t_list));
	if (!newstr)
		return (NULL);
	newstr->content = content;
	newstr->next = NULL;
	return (newstr);
}
