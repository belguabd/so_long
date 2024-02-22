/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:24:53 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/22 22:10:08 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_compare(char const *str, char *input)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == input[i])
		i++;
	return (str[i] - input[i]);
}

int	valid_file(char const *file)
{
	int	len;
	int	i;

	len = ft_strlen(file) - 1;
	if (len < 4)
		return (1);
	i = 0;
	while (file[len])
	{
		if (file[len] == '.')
			break ;
		i++;
		len--;
	}
	len = ft_strlen(file) - 1;
	return (ft_compare(file + (len - i), ".ber"));
}

void	validate_characters(t_data *data, size_t i)
{
	size_t	j;

	j = 0;
	while (data->t_map[i][j])
	{
		if (data->t_map[i][j] == 'P')
			data->p_count++;
		if (data->t_map[i][j] == 'C')
			data->c_count++;
		if (data->t_map[i][j] == 'E')
			data->e_count++;
		if (data->t_map[i][j] == 'D')
			data->nbr_enemy++;
		if (data->t_map[i][j] != 'P' && data->t_map[i][j] != 'E'
			&& data->t_map[i][j] != 'C' && data->t_map[i][j] != '1'
			&& data->t_map[i][j] != '0' && data->t_map[i][j] != 'D')
		{
			free_map_data(data);
			ft_putstr_fd("Error\nInvalid character in the map\n", 2);
		}
		j++;
	}
}

void	validate_map(t_data *data, size_t tmp_h)
{
	size_t	i;
	size_t	j;

	i = 1;
	data->c_count = 0;
	data->p_count = 0;
	data->e_count = 0;
	while (i < tmp_h - 1)
	{
		j = 0;
		validate_characters(data, i);
		i++;
	}
	if (data->p_count != 1)
		ft_free_main(data,
			"Error\n There should be exactly one 'P' character\n");
	if (data->c_count == 0)
		ft_free_main(data,
			"Error\n At least one 'C' character is required\n");
	if (data->e_count != 1)
		ft_free_main(data,
			"Error\n There should be exactly one 'E' character\n");
}

void	parsing(t_data *data, size_t height, size_t width)
{
	size_t	i;
	size_t	tmp_h;

	i = 0;
	tmp_h = height;
	while (data->t_map[i])
		if (ft_strlen(data->t_map[i++]) != width)
			ft_free_main(data, "Error\n Invalid border in map\n");
	i = 0;
	while (i < data->width)
		if (data->t_map[0][i++] != '1')
			ft_free_main(data, "Error\nThe map is not closed by 1\n");
	i = 0;
	while (data->t_map[height - 1][i])
		if (data->t_map[height - 1][i++] != '1')
			ft_free_main(data, "Error\nThe map is not closed by 1\n");
	i = 0;
	while (height--)
		if (data->t_map[i++][0] != '1')
			ft_free_main(data, "Error\nThe map is not closed by 1\n");
	while (i--)
		if (data->t_map[i][width - 1] != '1')
			ft_free_main(data, "Error\nThe map is not closed by 1\n");
	validate_map(data, tmp_h);
}
