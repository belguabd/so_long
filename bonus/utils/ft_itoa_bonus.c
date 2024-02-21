/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:19:52 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 17:29:34 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_pr_e(t_data *data, char *msg_error)
{
	free_map_data(data);
	write(2, msg_error, ft_strlen(msg_error));
	exit(1);
}

void	ft_itoa(int n, char **nbr, char *word, t_data *data)
{
	long	num;
	size_t	len;
	size_t	i;

	i = 0;
	while (word[i])
		i++;
	len = get_len(n) + i;
	*nbr = (char *)malloc(len + 1);
	if (!*nbr)
		ft_pr_e(data, "Error\n: Memory allocation failure using malloc");
	i = 0;
	while (word[i])
	{
		(*nbr)[i] = word[i];
		i++;
	}
	(*nbr)[len] = '\0';
	num = n;
	while (len-- > i)
	{
		(*nbr)[len] = (num % 10) + '0';
		num /= 10;
	}
}
