/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:45:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/19 16:32:09 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void initialize_data(t_data *data)
{
    int w;
    int h;
    data->nbr_move = 0;
    data->enemy_dir = 0;
    data->d_x = 0;
    data->d_y = 0;

    data->img_L = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/land.xpm", &w, &h);
    if (!data->img_L)
        ft_putstr_fd("Error: The background image is not found\n", 2);
    data->img_C = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/coll.xpm", &w, &h);
    if (!data->img_C)
        ft_putstr_fd("Error: The collectible image is not found\n", 2);
    data->img_W = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/wall.xpm", &w, &h);
    if (!data->img_W)
        ft_putstr_fd("Error: The wall image is not found\n", 2);
    data->img_P = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/player.xpm", &w, &h);
    if (!data->img_P)
        ft_putstr_fd("Error: The player image is not found\n", 2);
    data->img_E = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/the_door_v1.xpm", &w, &h);
    if (!data->img_E)
        ft_putstr_fd("Error: The door image is not found\n", 2);
    data->img_EO = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/open_door_v1.xpm", &w, &h);
    if (!data->img_EO)
        ft_putstr_fd("Error: The open door image is not found\n", 2);
    data->img_D = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/dragon.xpm", &w, &h);
    if (!data->img_D)
        ft_putstr_fd("Error: The dragon image is not found\n", 2);
}
