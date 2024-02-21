/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:05:54 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 10:12:07 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_map_data(t_data *data)
{
    int i = 0;
    while (data->t_map[i] != NULL)
    {
        free(data->t_map[i]);
        free(data->d_map[i]);
        i++;
    }
    free(data->t_map);
    free(data->d_map);
}