/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:59:08 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/22 12:13:26 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_pos_mld(t_data data, t_enemy *enemies, int *i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_enemies(t_enemy *enemies, int max_enemy, t_data data)
{
	int	i;

	i = 0;
	(void)max_enemy;
	while (i < max_enemy)
	{
		find_pos_mld(data, enemies, &i);
		i++;
	}
}

void	locate_player_in_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->t_map[y])
	{
		x = 0;
		while (data->t_map[y][x])
		{
			if (data->t_map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	ft_you_win(t_data *data)
{
	free_map_data(data);
	write(1, "YOU WIN\n", 9);
	exit(0);
}

void	initialize_window(t_data *data)
{
	size_t	win_width;
	size_t	win_height;

	win_width = data->width * 50;
	win_height = data->height * 50;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			win_width, win_height, "so_long");
	if (!data->win_ptr)
		ft_free_main(data, "Error\nmlx_new_window failed\n");
}
