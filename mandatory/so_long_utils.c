/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:38:38 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/22 11:45:14 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	data->win_ptr = mlx_new_window(data->mlx_ptr, win_width,
			win_height, "so_long");
	if (!data->win_ptr)
		ft_free_main(data, "Error\nmlx_new_window failed\n");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_b, 50, 50);
}
