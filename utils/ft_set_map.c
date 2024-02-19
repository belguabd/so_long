/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:19:36 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/19 16:12:35 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *getstruntilnl(char *line)
{
    int i = 0;
    char *new;

    while (line[i] && line[i] != '\n')
        i++;
    new = (char *)malloc((i + 1) * sizeof(char));
    if (!new)
        return (NULL);
    i = 0;
    while (line[i] && line[i] != '\n')
    {
        new[i] = line[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}
void validate_file_and_get_line(char const *av, size_t height)
{
    char *line;
    int fd;
    size_t i;
    fd = open(av, O_RDWR);
    if (fd < 0)
        ft_putstr_fd("Error: The file does not exist\n", 2);
    line = get_next_line(fd);
    i = 0;
    while (i++ < height - 1)
        line = get_next_line(fd);
    i = 0;
    while (line[i])
        if (line[i++] == '\n')
            ft_putstr_fd("Invalid map: Newline is not allowed in the last line\n", 2);
    close(fd);
}
void read_and_store_map_data(t_data *data, int fd)
{
    char *line;
    int i = 0;
    line = get_next_line(fd);
    while (line)
    {
        data->t_map[i] = getstruntilnl(line);
        data->d_map[i] = getstruntilnl(line);
        line = get_next_line(fd);
        i++;
    }
    data->t_map[i] = NULL;
    data->d_map[i] = NULL;
}
void ft_set_map(t_data *data, size_t height, char const *av)
{
    int fd;
    size_t i;
    i = 0;
    validate_file_and_get_line(av, height);
    fd = open(av, O_RDWR);
    if (fd < 0)
        ft_putstr_fd("Error: The file does not exist\n", 2);
    data->t_map = (char **)malloc((height + 1) * sizeof(char *));
    if (!data->t_map)
    {
        data->t_map = NULL;
        return;
    }
    data->d_map = (char **)malloc((height + 1) * sizeof(char *));
    if (!data->d_map)
    {
        data->d_map = NULL;
        return;
    }
    read_and_store_map_data(data, fd);
    close(fd);
}
