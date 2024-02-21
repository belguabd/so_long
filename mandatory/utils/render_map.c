/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:50 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 16:40:10 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_data *data)
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
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img_p, data->p_x * 50, data->p_y * 50);
}
