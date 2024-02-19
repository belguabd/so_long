/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:19:52 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/19 15:03:43 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
static size_t get_len(int n)
{
    size_t len;

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

void ft_itoa(int n, char **nbr, char *word)
{
    size_t len;
    size_t i;
    long num;

    i = 0;
    while (word[i])
        i++;
    len = get_len(n) + i;
    *nbr = (char *)malloc(len + 1);
    if (!*nbr)
        exit(1);
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
