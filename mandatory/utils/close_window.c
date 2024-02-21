/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:47:01 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 14:58:39 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *data)
{
	free_map_data(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}
