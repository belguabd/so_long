/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:45:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 11:29:00 by belguabd         ###   ########.fr       */
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
    {
        free_map_data(data);
        ft_putstr_fd("Error\n The background image is not found\n", 2);
    }
    data->img_C = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/coll.xpm", &w, &h);
    if (!data->img_C)
    {
        free_map_data(data);
        ft_putstr_fd("Error\n The collectible image is not found\n", 2);
    }
    data->img_W = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/wall.xpm", &w, &h);
    if (!data->img_W)
    {
        free_map_data(data);
        ft_putstr_fd("Error\n The wall image is not found\n", 2);
    }
    data->img_P = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/player.xpm", &w, &h);
    if (!data->img_P)
    {
        free_map_data(data);
        ft_putstr_fd("Error\n The player image is not found\n", 2);
    }
    data->img_E = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/the_door_v1.xpm", &w, &h);
    if (!data->img_E)
    {
        free_map_data(data);
        ft_putstr_fd("Error\n The door image is not found\n", 2);
    }
    data->img_EO = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/open_door_v1.xpm", &w, &h);
    if (!data->img_EO)
    {
        free_map_data(data);
        ft_putstr_fd("Error\n The open door image is not found\n", 2);
    }
    data->img_D = mlx_xpm_file_to_image(data->mlx_ptr, "./bonus/textures/dragon.xpm", &w, &h);
    if (!data->img_D)
    {
        free_map_data(data);
        ft_putstr_fd("Error\n The dragon image is not found\n", 2);
    }
}
