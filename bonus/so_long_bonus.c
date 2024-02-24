/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:38:46 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/24 14:56:47 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_position_and_map(t_data *data, size_t new_y, size_t new_x)
{
	char	*element;

	element = &data->t_map[new_y][new_x];
	if (*element == 'C' || *element == '0' || *element == 'P'
		|| *element == 'E' || *element == 'D')
	{
		if (*element == 'C')
		{
			data->c_count--;
			*element = '0';
		}
		data->p_y = new_y;
		data->p_x = new_x;
		data->nbr_move++;
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
	char	*nbr;
	size_t	new_y;
	size_t	new_x;

	data->keycode = keycode;
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
	render_map(data);
	ft_itoa(data->nbr_move, &nbr, "player moves = ", data);
	mlx_string_put(data->mlx_ptr,
		data->win_ptr, 1 * 30, 0, 0xFFFFFF, nbr);
	return (free(nbr), 0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 0, key_handler, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx_ptr, animation, data);
}

int	main(int ac, char const *av[])
{
	t_data	data;

	validate_and_set_params(&data, av[1], ac);
	set_width_height(&data, av[1]);
	ft_set_map(&data, data.height, av[1]);
	ft_check_empty_map(&data);
	locate_player_in_map(&data);
	parsing(&data, data.height, data.width);
	flood_fill(data, data.p_y, data.p_x);
	if (has_elements(data))
		ft_free_main(&data, "Error\nInvalid map\n");
	ft_set_map(&data, data.height, av[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		ft_free_main(&data, "Error\nmlx_init failed\n");
	initialize_data(&data, data.w, data.h);
	initialize_window(&data);
	hooks(&data);
	render_map(&data);
	mlx_string_put(data.mlx_ptr,
		data.win_ptr, 1 * 30, 0, 0xFFFFFF, "player moves = 0");
	mlx_loop(data.mlx_ptr);
}
