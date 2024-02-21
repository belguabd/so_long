/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:24:53 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 11:27:53 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
        {

            free_map_data(data);
            ft_putstr_fd("Error\nInvalid character in the map\n", 2);
        }
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
    {
        free_map_data(data);
        ft_putstr_fd("Error\n There should be exactly one 'P' character\n", 2);
    }
    if (data->C_count == 0)
    {
        free_map_data(data);
        ft_putstr_fd("Error\n At least one 'C' character is required\n", 2);
    }
    if (data->E_count != 1)
    {
        free_map_data(data);
        ft_putstr_fd("Error\n There should be exactly one 'E' character\n", 2);
    }
}
void parsing(t_data *data, size_t height, size_t width)
{
    size_t i;
    size_t tmp_h;

    i = 0;
    tmp_h = height;
    while (data->t_map[i])
    {
        if (ft_strlen(data->t_map[i++]) != width)
        {
            free_map_data(data);
            ft_putstr_fd("Error\n Invalid border in map\n", 2);
        }
    }
    i = 0;
    while (i < data->width)
    {

        if (data->t_map[0][i++] != '1')
        {
            free_map_data(data);
            ft_putstr_fd("Error\n The map is not closed/surrounded by walls\n", 2);
        }
    }
    i = 0;
    while (data->t_map[height - 1][i])
    {

        if (data->t_map[height - 1][i++] != '1')
        {
            free_map_data(data);
            ft_putstr_fd("Errorn\n The map is not closed/surrounded by walls\n", 2);
        }
    }
    i = 0;
    while (height--)
    {

        if (data->t_map[i++][0] != '1')
        {
            free_map_data(data);
            ft_putstr_fd("Error\n The map is not closed/surrounded by walls\n", 2);
        }
    }
    while (i--)
    {

        if (data->t_map[i][width - 1] != '1')
        {
            free_map_data(data);
            ft_putstr_fd("Error\n The map is not closed/surrounded by walls\n", 2);
        }
    }
    validate_map(data, tmp_h);
}
