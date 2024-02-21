/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:45:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 10:43:56 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void initialize_data(t_data *data)
{
    int w;
    int h;
    data->nbr_move = 1;
    data->img_B = mlx_xpm_file_to_image(data->mlx_ptr, "./mandatory/textures/background.xpm", &w, &h);
    if (!data->img_B)
    {
        free_map_data(data);
        ft_putstr_fd("Error: The background image is not found\n", 2);
    }
    data->img_C = mlx_xpm_file_to_image(data->mlx_ptr, "./mandatory/textures/coll.xpm", &w, &h);
    if (!data->img_C)
    {
        free_map_data(data);
        ft_putstr_fd("Error: The collectible image is not found\n", 2);
    }
    data->img_W = mlx_xpm_file_to_image(data->mlx_ptr, "./mandatory/textures/wall.xpm", &w, &h);
    if (!data->img_W)
    {
        free_map_data(data);
        ft_putstr_fd("Error: The wall image is not found\n", 2);
    }
    data->img_P = mlx_xpm_file_to_image(data->mlx_ptr, "./mandatory/textures/player.xpm", &w, &h);
    if (!data->img_P)
    {
        free_map_data(data);
        ft_putstr_fd("Error: The player image is not found\n", 2);
    }
    data->img_E = mlx_xpm_file_to_image(data->mlx_ptr, "./mandatory/textures/the_door_v1.xpm", &w, &h);
    if (!data->img_E)
    {
        free_map_data(data);
        ft_putstr_fd("Error: The door image is not found\n", 2);
    }
    data->img_EO = mlx_xpm_file_to_image(data->mlx_ptr, "./mandatory/textures/open_door_v1.xpm", &w, &h);
    if (!data->img_EO)
    {
        free_map_data(data);
        ft_putstr_fd("Error: The open door image is not found\n", 2);
    }
}
