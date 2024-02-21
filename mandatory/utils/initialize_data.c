/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:45:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 16:36:56 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_imgs(t_imge *img)
{
	img->img_b = "./mandatory/textures/background.xpm";
	img->img_c = "./mandatory/textures/coll.xpm";
	img->img_w = "./mandatory/textures/wall.xpm";
	img->img_p = "./mandatory/textures/player.xpm";
	img->img_e = "./mandatory/textures/the_door_v1.xpm";
	img->img_eo = "./mandatory/textures/open_door_v1.xpm";
}

void	initialize_data(t_data *data)
{
	t_imge	img;
	int		w;
	int		h;

	init_imgs(&img);
	data->nbr_move = 1;
	data->img_b = mlx_xpm_file_to_image(data->mlx_ptr, img.img_b, &w, &h);
	if (!data->img_b)
		ft_free_main(data, "Error\nThe background image is not found\n");
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, img.img_c, &w, &h);
	if (!data->img_c)
		ft_free_main(data, "Error\nThe collectible image is not found\n");
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, img.img_w, &w, &h);
	if (!data->img_w)
		ft_free_main(data, "Error\nThe wall image is not found\n");
	data->img_p = mlx_xpm_file_to_image(data->mlx_ptr, img.img_p, &w, &h);
	if (!data->img_p)
		ft_free_main(data, "Error\nThe player image is not found\n");
	data->img_e = mlx_xpm_file_to_image(data->mlx_ptr, img.img_e, &w, &h);
	if (!data->img_e)
		ft_free_main(data, "Error\nThe door image is not found\n");
	data->img_eo = mlx_xpm_file_to_image(data->mlx_ptr, img.img_eo, &w, &h);
	if (!data->img_eo)
		ft_free_main(data, "Error\nThe open door image is not found\n");
}
