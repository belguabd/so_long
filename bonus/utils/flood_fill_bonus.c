/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:09:25 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/20 14:29:50 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void flood_fill(t_data data, size_t y, size_t x)
{
    if (data.d_map[y][x] == '1' || data.d_map[y][x] == 'v' || data.d_map[y][x] == 'D')
        return;
    data.d_map[y][x] = 'v';
    flood_fill(data, y + 1, x);
    flood_fill(data, y - 1, x);
    flood_fill(data, y, x + 1);
    flood_fill(data, y, x - 1);
}
bool has_elements(t_data data)
{

    bool check = false;
    int x = 0;
    int y = 0;
    while (data.d_map[y])
    {
        x = 0;
        while (data.d_map[y][x])
        {
            if (data.d_map[y][x] == 'C' || data.d_map[y][x] == 'E')
                check = true;
            x++;
        }
        y++;
    }
    return (check);
}

