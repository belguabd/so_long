/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:15:18 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 16:41:09 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_width_height(t_data *data, char const *av)
{
	char	*line;
	int		fd;

	data->height = 0;
	data->width = 0;
	fd = open(av, O_RDWR);
	if (fd < 0)
		ft_putstr_fd("Error\n: The file does not exist\n", 2);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_putstr_fd("Error\n: The map is empty\n", 2);
	}
	data->width = ft_strlen(line) - 1;
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
