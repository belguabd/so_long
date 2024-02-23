/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:45:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/23 21:41:07 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_imgs(t_imge *img)
{
	img->img_l = "./bonus/textures/land.xpm";
	img->img_c = "./bonus/textures/coll.xpm";
	img->img_w = "./bonus/textures/wall.xpm";
	img->img_lft = "./bonus/textures/left.xpm";
	img->img_rt ="./bonus/textures/right.xpm";
	img->img_up ="./bonus/textures/up.xpm";
	img->img_dwn ="./bonus/textures/down.xpm";
	// img->img_p = "./bonus/textures/player1.xpm";
	// img->img_p_r = "./bonus/textures/player2.xpm";
	img->img_e = "./bonus/textures/the_door_v1.xpm";
	img->img_eo = "./bonus/textures/open_door_v1.xpm";
	img->img_d = "./bonus/textures/dragon.xpm";
}

void	init_data(t_data *data)
{
	data->nbr_move = 0;
	data->enemy_dir = 0;
	data->d_x = 0;
	data->d_y = 0;
}

void	initialize_data(t_data *data, int w, int h)
{
	t_imge	img;

	init_imgs(&img);
	init_data(data);
	data->img_l = mlx_xpm_file_to_image(data->mlx_ptr, img.img_l, &w, &h);
	if (!data->img_l)
		ft_free_main(data, "Error\nThe background image is not found\n");
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, img.img_c, &w, &h);
	if (!data->img_c)
		ft_free_main(data, "Error\nThe collectible image is not found\n");
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, img.img_w, &w, &h);
	if (!data->img_w)
		ft_free_main(data, "Error\nThe wall image is not found\n");
	data->img_rt = mlx_xpm_file_to_image(data->mlx_ptr, img.img_rt, &w, &h);
	if (!data->img_rt)
		ft_free_main(data, "Error\nThe player image is not found\n");
	data->img_lft = mlx_xpm_file_to_image(data->mlx_ptr, img.img_lft, &w, &h);
	if (!data->img_lft)
		ft_free_main(data, "Error\nThe player image is not found\n");
	data->img_dwn = mlx_xpm_file_to_image(data->mlx_ptr, img.img_dwn, &w, &h);
	if (!data->img_dwn)
		ft_free_main(data, "Error\nThe player image is not found\n");
	data->img_up = mlx_xpm_file_to_image(data->mlx_ptr, img.img_up, &w, &h);
	if (!data->img_up)
		ft_free_main(data, "Error\nThe player image is not found\n");
	data->img_e = mlx_xpm_file_to_image(data->mlx_ptr, img.img_e, &w, &h);
	if (!data->img_e)
		ft_free_main(data, "Error\nThe door image is not found\n");
	data->img_eo = mlx_xpm_file_to_image(data->mlx_ptr, img.img_eo, &w, &h);
	if (!data->img_eo)
		ft_free_main(data, "Error\nThe door image is not found\n");
	data->img_d = mlx_xpm_file_to_image(data->mlx_ptr, img.img_d, &w, &h);
	if (!data->img_d)
		ft_free_main(data, "Error\n The dragon image is not found\n");
}
