/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:45:45 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 19:59:45 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_non_specialchar(char c)
{
	return (c != '1' && c != 'C' && c != 'E');
}

bool	is_special_character(char c)
{
	return (c == '1' || c == 'C' || c == 'E');
}

void	update_enemy_direction(t_enemy *enemy, t_data *data, int i)
{
	char	c_right;
	char	c_left;

	c_right = data->t_map[enemy[i].d_y][enemy[i].d_x + 1];
	c_left = data->t_map[enemy[i].d_y][enemy[i].d_x - 1];
	if (enemy[i].enemy_dir == 0 && is_non_specialchar(c_right))
	{
		enemy[i].old_d_x = enemy[i].d_x;
		enemy[i].old_d_y = enemy[i].d_y;
		enemy[i].d_x++;
	}
	else if (enemy[i].enemy_dir == 0 && is_special_character(c_right))
		enemy[i].enemy_dir = 1;
	if (enemy[i].enemy_dir == 1 && is_non_specialchar(c_left))
	{
		enemy[i].old_d_x = enemy[i].d_x;
		enemy[i].old_d_y = enemy[i].d_y;
		enemy[i].d_x--;
	}
	else if (enemy[i].enemy_dir == 1 && is_special_character(c_left))
		enemy[i].enemy_dir = 0;
}

void	update_enemy_positon(t_enemy *enemies, t_data *data, int i)
{
	data->t_map[enemies[i].old_d_y][enemies[i].old_d_x] = '0';
	data->t_map[enemies[i].d_y][enemies[i].d_x] = 'D';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_l, enemies[i].old_d_x * 50, enemies[i].old_d_y * 50);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_d, enemies[i].d_x * 50, enemies[i].d_y * 50);
	if ((data->p_x == enemies[i].d_x && data->p_y == enemies[i].d_y)
		|| (data->p_x == enemies[i].old_d_x && data->p_y == enemies[i].old_d_y))
	{
		free_enemies(enemies);
		free_map_data(data);
		write(1, "LOSERR\n", 6);
		exit(0);
	}
}

int	animation(t_data *data)
{
	static t_enemy	*enemies = NULL;
	static int		sleep_d;
	int				i;

	if (!enemies)
	{
		enemies = (t_enemy *)malloc(data->nbr_enemy * sizeof(t_enemy));
		if (!enemies)
		{
			free_map_data(data);
			write(1, "Error\n", 6);
			exit(1);
		}
		init_enemies(enemies, data->nbr_enemy, *data);
	}
	i = -1;
	if (sleep_d++ % 2000 == 1)
	{
		while (++i < data->nbr_enemy)
		{
			update_enemy_direction(enemies, data, i);
			update_enemy_positon(enemies, data, i);
		}
	}
	return (0);
}
