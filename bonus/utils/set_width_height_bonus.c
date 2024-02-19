/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_height_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:15:18 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/19 16:32:16 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void set_width_height(t_data *data, char const *av)
{
    int fd;
    char *line;

    data->height = 0;
    data->width = 0;
    fd = open(av, O_RDWR);
    if (fd < 0)
        ft_putstr_fd("Error: The file does not exist\n", 2);
    line = get_next_line(fd);
    if (!line)
        ft_putstr_fd("Error: The map is empty\n", 2);

    data->width = ft_strlen(line) - 1;
    while (line)
    {
        data->height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
