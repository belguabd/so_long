/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:38:46 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/19 15:11:47 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>
#include "./mlx.h"
int animation(t_data *data);
void update_position_and_map(t_data *data, size_t new_y, size_t new_x)
{

	char *element = &data->t_map[new_y][new_x];
	if (*element == 'C' || *element == '0' || *element == 'P' || *element == 'E')
	{
		if (*element == 'C')
		{
			data->C_count--;
			*element = '0';
		}

		data->p_y = new_y;
		data->p_x = new_x;
		data->nbr_move++;
		// printf("%zu\n", data->nbr_move++);
	}
	if (data->C_count == 0)
	{
		data->img_E = data->img_EO;
		if (*element == 'E')
		{
			write(1, "YOU WIN\n", 9);
			exit(0);
		}
	}
}
int key_handler(int keycode, t_data *data)
{

	size_t new_y = data->p_y;
	size_t new_x = data->p_x;
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	else if (keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_LEFT)
		new_x--;

	else if (keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_RIGHT)
		new_x++;
	update_position_and_map(data, new_y, new_x);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render_map(data);
	char *nbr;
	ft_itoa(data->nbr_move, &nbr, "player moves = ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1 * 30, 0, 0xFFFFFF, nbr);
	free(nbr);
	return (0);
}
void locate_player_in_map(t_data *data)
{
	int x = 0;
	int y = 0;
	while (data->t_map[y])
	{
		x = 0;
		while (data->t_map[y][x])
		{
			if (data->t_map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
				break;
			}
			x++;
		}
		y++;
	}
}
void find_pos_d(t_data *data)
{
	int x = 0;
	int y = 0;

	while (data->t_map[y])
	{
		x = 0;
		while (data->t_map[y][x])
		{
			if (data->t_map[y][x] == 'D')
			{
				data->d_x = x;
				data->d_y = y;
				data->old_d_x = x;
				data->old_d_y = y;
			}
			x++;
		}
		y++;
	}
}
typedef struct enemies_solong
{
	size_t enemy_dir;
	size_t d_x;
	size_t d_y;
	size_t old_d_x;
	size_t old_d_y;

} Enemy;

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
int animation(t_data *data)
{
	static int sleep_d;
	static int max_enemy = 3;
	static Enemy *enemies = NULL;
	if (!enemies)
	{
		enemies = (Enemy *)malloc(data->nbr_enemy * sizeof(Enemy));
		if (!enemies)
			exit(1);
		init_enemies(enemies, max_enemy, *data);
	}
	int i = 0;
	if (sleep_d % 2000 == 1)
	{
		while (i < data->nbr_enemy)
		{
			if (enemies[i].enemy_dir == 0 && (data->t_map[enemies[i].d_y][enemies[i].d_x + 1] != '1' &&
											  data->t_map[enemies[i].d_y][enemies[i].d_x + 1] != 'C' &&
											  data->t_map[enemies[i].d_y][enemies[i].d_x + 1] != 'E'))
			{
				enemies[i].old_d_x = enemies[i].d_x;
				enemies[i].old_d_y = enemies[i].d_y;
				enemies[i].d_x++;
			}
			else if (enemies[i].enemy_dir == 0 && (data->t_map[enemies[i].d_y][enemies[i].d_x + 1] == '1' || data->t_map[enemies[i].d_y][enemies[i].d_x + 1] == 'C' || data->t_map[enemies[i].d_y][enemies[i].d_x + 1] == 'E'))
				enemies[i].enemy_dir = 1;
			if (enemies[i].enemy_dir == 1 && (data->t_map[enemies[i].d_y][enemies[i].d_x - 1] != '1' && data->t_map[enemies[i].d_y][enemies[i].d_x - 1] != 'C' && data->t_map[enemies[i].d_y][enemies[i].d_x - 1] != 'E'))
			{
				enemies[i].old_d_x = enemies[i].d_x;
				enemies[i].old_d_y = enemies[i].d_y;
				enemies[i].d_x--;
			}
			else if (enemies[i].enemy_dir == 1 && (data->t_map[enemies[i].d_y][enemies[i].d_x - 1] == '1' || data->t_map[enemies[i].d_y][enemies[i].d_x - 1] == 'C' || data->t_map[enemies[i].d_y][enemies[i].d_x - 1] == 'E'))
				enemies[i].enemy_dir = 0;

			data->t_map[enemies[i].old_d_y][enemies[i].old_d_x] = '0';
			data->t_map[enemies[i].d_y][enemies[i].d_x] = 'D';
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_L, enemies[i].old_d_x * 50, enemies[i].old_d_y * 50);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_D, enemies[i].d_x * 50, enemies[i].d_y * 50);
			if (data->p_x == enemies[i].d_x && data->p_y == enemies[i].d_y)
			{
				write(1, "I lost\n", 6);
				exit(0);
			}
			i++;
		}
	}
	sleep_d++;
	return (0);
}
int main(int ac, char const *av[])
{
	t_data data;
	
	validate_and_set_params(&data, av[1], ac);
	set_width_height(&data, av[1]);
	ft_set_map(&data, data.height, av[1]);
	if (!data.t_map[0][0])
		ft_putstr_fd("Error: The map is empty\n", 2);
	locate_player_in_map(&data);
	parsing(&data, data.height, data.width);
	flood_fill(data, data.p_y, data.p_x);
	if (has_elements(data))
		ft_putstr_fd("Invalid map\n", 2);
	ft_set_map(&data, data.height, av[1]);
	data.mlx_ptr = mlx_init();
	initialize_data(&data);
	size_t win_width = data.width * 50;
	size_t win_height = data.height * 50;
	data.win_ptr = mlx_new_window(data.mlx_ptr, win_width, win_height, "so_long");
	mlx_hook(data.win_ptr, 2, 0, key_handler, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop_hook(data.mlx_ptr, animation, &data);
	render_map(&data);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 1 * 30, 0, 0xFFFFFF, "player moves = ");
	mlx_loop(data.mlx_ptr);
	return (0);
}
