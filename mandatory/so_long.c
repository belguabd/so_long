/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:38:46 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/22 11:45:29 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position_and_map(t_data *data, size_t new_y, size_t new_x)
{
	char	*element;
	char	*nbr;

	element = &data->t_map[new_y][new_x];
	if (*element == 'C' || *element == '0'
		|| *element == 'P' || *element == 'E')
	{
		if (*element == 'C')
		{
			data->c_count--;
			*element = '0';
		}
		data->p_y = new_y;
		data->p_x = new_x;
		ft_itoa(data->nbr_move++, &nbr, "move = ", data);
		write(1, nbr, ft_strlen(nbr));
		write(1, "\n", 1);
		free(nbr);
	}
	if (data->c_count == 0)
	{
		data->img_e = data->img_eo;
		if (*element == 'E')
			ft_you_win(data);
	}
}

void	handle_escape_key(t_data *data, int keycode)
{
	if (keycode == ESC)
	{
		free_map_data(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
}

int	key_handler(int keycode, t_data *data)
{
	size_t	new_y;
	size_t	new_x;

	new_y = data->p_y;
	new_x = data->p_x;
	handle_escape_key(data, keycode);
	if (keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_RIGHT)
		new_x++;
	if (keycode == KEY_DOWN || keycode == KEY_LEFT
		|| keycode == KEY_UP || keycode == KEY_RIGHT)
		update_position_and_map(data, new_y, new_x);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_b, 50, 50);
	render_map(data);
	return (0);
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

int	main(int ac, char const *av[])
{
	t_data	data;

	validate_and_set_params(&data, av[1], ac);
	set_width_height(&data, av[1]);
	ft_set_map(&data, data.height, av[1]);
	if (!data.t_map[0][0])
		ft_free_main(&data, "Error\n The map is empty\n");
	locate_player_in_map(&data);
	parsing(&data, data.height, data.width);
	flood_fill(data, data.p_y, data.p_x);
	if (has_elements(data))
		ft_free_main(&data, "Error\nInvalid map\n");
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		ft_free_main(&data, "Error\nmlx_init failed\n");
	initialize_data(&data);
	initialize_window(&data);
	render_map(&data);
	mlx_hook(data.win_ptr, 2, 0, key_handler, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
