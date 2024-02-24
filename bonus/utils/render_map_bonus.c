/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:50 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/24 14:59:42 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	render_helper(t_data *data, int y)
{
	int	x;

	x = 0;
	while (data->t_map[y][x])
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img_l, x * 50, y * 50);
		if (data->t_map[y][x] == 'D')
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->img_d, x * 50, y * 50);
		if (data->t_map[y][x] == '1')
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->img_w, x * 50, y * 50);
		else if (data->t_map[y][x] == 'E')
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->img_e, x * 50, y * 50);
		else if (data->t_map[y][x] == 'C')
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->img_c, x * 50, y * 50);
		x++;
	}
}

void	render_map(t_data *data)
{
	int	y;

	y = 0;
	while (data->t_map[y])
	{
		render_helper(data, y);
		y++;
	}
	if (data->keycode == KEY_RIGHT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_lft, data->p_x * 50, data->p_y * 50);
	else if (data->keycode == KEY_LEFT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_rt, data->p_x * 50, data->p_y * 50);
	else if (data->keycode == KEY_UP)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_up, data->p_x * 50, data->p_y * 50);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_dwn, data->p_x * 50, data->p_y * 50);
}
