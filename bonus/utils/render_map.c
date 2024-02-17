/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:50 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/17 17:33:55 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void render_map(void *mlx_ptr, void *win_ptr, t_data *data)
{
	int x = 0;
	int y = 0;

	while (data->t_map[y])
	{
		x = 0;
		while (data->t_map[y][x])
		{
			if (data->t_map[y][x] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_W, x * 50, y * 50);
			else if (data->t_map[y][x] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_E, x * 50, y * 50);
			else if (data->t_map[y][x] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_C, x * 50, y * 50);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_P, data->p_x * 50, data->p_y * 50);
}
