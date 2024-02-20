/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:38:46 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/20 11:17:20 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include "./mlx.h"

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
		printf("%zu\n", data->nbr_move++);
	}
	if (data->C_count == 0)
	{
		data->img_E = data->img_EO;
		if (*element == 'E')
		{
			// int i;
			// i = 0;
			// while (data->t_map[i])
			// {
			// 	free(data->t_map[i]);
			// 	free(data->d_map[i]);
			// 	i++;
			// }
			// free(data->t_map[i]);
			// free(data->d_map[i]);
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
	if (keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_UP || keycode == KEY_RIGHT)
		update_position_and_map(data, new_y, new_x);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_B, 50, 50);
	render_map(data);
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
void display(t_data *data)
{
	int y = 0;
	int x = 0;
	while (data->d_map[y][x])
	{
		x = 0;
		while (data->d_map[y][x])
		{
			printf("%c", data->d_map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
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
	data.mlx_ptr = mlx_init();
	initialize_data(&data);
	size_t win_width = data.width * 50;
	size_t win_height = data.height * 50;
	data.win_ptr = mlx_new_window(data.mlx_ptr, win_width, win_height, "so_long");
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_B, 50, 50);
	mlx_hook(data.win_ptr, 2, 0, key_handler, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	render_map(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}