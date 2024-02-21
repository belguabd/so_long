/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:49:56 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 19:37:06 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	validate_and_set_params(t_data *data, char const *av, int ac)
{
	if (ac != 2)
		ft_putstr_fd("Error\n The number of arguments is invalid\n", 2);
	if (valid_file(av))
		ft_putstr_fd("Error\n The file is not a .ber file\n", 2);
	set_width_height(data, av);
	if (data->height > 28 || data->width > 51)
		ft_putstr_fd("Error\n The map is too large\n", 2);
}

void	ft_check_empty_map(t_data *data)
{
	if (!data->t_map[0][0])
		ft_free_main(data, "Error\n The map is empty\n");
}
