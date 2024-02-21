/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:18:25 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 20:00:12 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_enemies(t_enemy *enemies)
{
	free(enemies);
}

void	free_map_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->t_map[i] != NULL)
	{
		free(data->t_map[i]);
		free(data->d_map[i]);
		i++;
	}
	free(data->t_map);
	free(data->d_map);
}

void	ft_free_main(t_data *data, char *mes_error)
{
	free_map_data(data);
	ft_putstr_fd(mes_error, 2);
}
