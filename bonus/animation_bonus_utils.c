/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:59:08 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/20 15:01:02 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void find_pos_mld(t_data data, Enemy *enemies, int *i)
{
    int x = 0;
    int y = 0;
    while (data.d_map[y])
    {
        x = 0;
        while (data.d_map[y][x])
        {
            if (data.d_map[y][x] == 'D')
            {
                enemies[(*i)].d_x = x;
                enemies[(*i)].d_y = y;
                enemies[(*i)].enemy_dir = 0;
                enemies[(*i)].old_d_x = enemies[(*i)].d_x;
                enemies[(*i)].old_d_y = enemies[(*i)].d_y;
                data.d_map[y][x] = '0';
                return;
            }
            x++;
        }
        y++;
    }
}
void init_enemies(Enemy *enemies, int max_enemy, t_data data)
{

    int i = 0;
    (void)max_enemy;
    while (i < max_enemy)
    {
        find_pos_mld(data, enemies, &i);
        i++;
    }
}