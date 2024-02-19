/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:24:53 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/19 10:38:02 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int ft_compare(char const *str, char *input)
{
    int i = 0;
    while (str[i] && str[i] == input[i])
        i++;
    return (str[i] - input[i]);
}
int valid_file(char const *file)
{
    size_t len = ft_strlen(file) - 1;
    int i;
    i = 0;
    while (file[len])
    {
        if (file[len] == '.')
            break;
        i++;
        len--;
    }
    len = ft_strlen(file) - 1;
    return (ft_compare(file + (len - i), ".ber"));
}
void validate_characters(t_data *data, size_t i)
{

    size_t j;
    j = 0;
    while (data->t_map[i][j])
    {
        if (data->t_map[i][j] == 'P')
            data->P_count++;
        if (data->t_map[i][j] == 'C')
            data->C_count++;
        if (data->t_map[i][j] == 'E')
            data->E_count++;
        if (data->t_map[i][j] == 'D')
            data->nbr_enemy++;
        if (data->t_map[i][j] != 'P' && data->t_map[i][j] != 'E' && data->t_map[i][j] != 'C' &&
            data->t_map[i][j] != '1' && data->t_map[i][j] != '0' && data->t_map[i][j] != 'D')
            ft_putstr_fd("Error: Invalid character in the map\n", 2);
        j++;
    }
    
}
void validate_map(t_data *data, size_t tmp_h)
{
    size_t i;
    size_t j;

    i = 1;
    data->C_count = 0;
    data->P_count = 0;
    data->E_count = 0;
    while (i < tmp_h - 1)
    {
        j = 0;
        validate_characters(data, i);

        i++;
    }
    if (data->P_count != 1)
        ft_putstr_fd("Error: There should be exactly one 'P' character\n", 2);
    if (data->C_count == 0)
        ft_putstr_fd("Error: At least one 'C' character is required\n", 2);
    if (data->E_count != 1)
        ft_putstr_fd("Error: There should be exactly one 'E' character\n", 2);
}
#include <stdio.h>
void parsing(t_data *data, size_t height, size_t width)
{
    size_t i;
    size_t tmp_h;

    i = 0;
    tmp_h = height;
    while (data->t_map[i])
        if (ft_strlen(data->t_map[i++]) != width)
            ft_putstr_fd("Error: Invalid border in map\n", 2);
    i = 0;
    while (i < data->width)
        if (data->t_map[0][i++] != '1')
            ft_putstr_fd("Error: The map is not closed/surrounded by walls\n", 2);
    i = 0;
    while (data->t_map[height - 1][i])
        if (data->t_map[height - 1][i++] != '1')
            ft_putstr_fd("Error: The map is not closed/surrounded by walls\n", 2);
    i = 0;
    while (height--)
        if (data->t_map[i++][0] != '1')
            ft_putstr_fd("Error: The map is not closed/surrounded by walls\n", 2);
    while (i--)
        if (data->t_map[i][width - 1] != '1')
            ft_putstr_fd("Error: The map is not closed/surrounded by walls\n", 2);
    validate_map(data, tmp_h);
}
