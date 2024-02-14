/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:38:46 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/14 10:58:47 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include "./mlx.h"
void ft_putstr_fd(char *s, int fd)
{
	int i;

	if (!s)
		return;
	if (fd < 0)
		return;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	exit(1);
}
void set_width_height(t_data *data)
{
	int fd;
	char *line;

	data->height = 0;
	data->width = 0;
	fd = open("map.ber", O_RDWR);
	line = get_next_line(fd);
	if (!line)
		ft_putstr_fd("Error: The map is empty\n", 2);

	data->width = ft_strlen(line) - 1;
	while (line)
	{
		data->height++;
		line = get_next_line(fd);
	}
	close(fd);
}
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
void ft_set_map(t_data *data, size_t height)
{
	char *line;
	int fd;
	size_t i = 0;
	fd = open("map.ber", O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (i++ < height - 1)
		line = get_next_line(fd);
	i = 0;
	while (line[i])
		if (line[i++] == '\n')
			ft_putstr_fd("Invalid map: Newline is not allowed in the last line\n", 2);
	close(fd);

	fd = open("map.ber", O_RDWR);
	line = get_next_line(fd);
	data->t_map = (char **)malloc((height + 1) * sizeof(char *));
	if (!data->t_map)
	{
		data->t_map = NULL;
		return;
	}
	i = 0;
	while (line)
	{
		data->t_map[i] = getstruntilnl(line);
		line = get_next_line(fd);
		i++;
	}
	data->t_map[i] = NULL;
	close(fd);
}
void parsing(t_data data, size_t height, size_t width)
{
	size_t i;
	size_t j;
	size_t tmp_h;
	i = 0;

	tmp_h = height;
	while (data.t_map[i])
		if (ft_strlen(data.t_map[i++]) != width)
			ft_putstr_fd("Error: Invalid border in map\n", 2);
	while (data.t_map[0][i])
		if (data.t_map[0][i++] != '1')
			ft_putstr_fd("Error: The map is not closed/surrounded by walls\n", 2);
	i = 0;
	while (data.t_map[height - 1][i])
		if (data.t_map[height - 1][i++] != '1')
			ft_putstr_fd("Error: The map is not closed/surrounded by walls\n", 2);
	i = 0;
	while (height--)
		if (data.t_map[i++][0] != '1')
			ft_putstr_fd("Error: The map is not closed/surrounded by walls\n", 2);
	while (i--)
		if (data.t_map[i][width - 1] != '1')
			ft_putstr_fd("Error: The map is not closed/surrounded by walls\n", 2);
	i = 1;
	size_t C_count = 0;
	size_t P_count = 0;
	size_t E_count = 0;
	while (i < tmp_h - 1)
	{
		j = 0;
		while (data.t_map[i][j])
		{
			if (data.t_map[i][j] == 'P')
				P_count++;
			if (data.t_map[i][j] == 'C')
				C_count++;
			if (data.t_map[i][j] == 'E')
				E_count++;
			if (data.t_map[i][j] != 'P' && data.t_map[i][j] != 'E' && data.t_map[i][j] != 'C' &&
				data.t_map[i][j] != '1' && data.t_map[i][j] != '0')
				ft_putstr_fd("Error: Invalid character in the map\n", 2);
			j++;
		}
		i++;
	}
	if (P_count != 1)
		ft_putstr_fd("Error: There should be exactly one 'P' character\n", 2);
	if (C_count == 0)
		ft_putstr_fd("Error: At least one 'C' character is required\n", 2);
	if (E_count != 1)
		ft_putstr_fd("Error: There should be exactly one 'E' character\n", 2);
}
int main()
{
	t_data data;
	void *img;
	int w;
	int h;
	set_width_height(&data);
	ft_set_map(&data, data.height);
	if (!data.t_map[0][0])
		ft_putstr_fd("Error: The map is empty\n", 2);
	parsing(data, data.height, data.width);
	void *mlx_ptr;
	void *win_ptr;

	size_t win_width = data.width * 50;
	size_t win_height = data.height * 50;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_width, win_height, "so_long");
	img = mlx_xpm_file_to_image(mlx_ptr, "./wall.xpm", &w, &h);
	size_t size_width = win_width / 50;
	size_t size_height = win_height / 50;
	printf("%d\n", size_width);
	printf("%d\n", size_height);
	int x = 0;
	int y = 0;
	while (size_height--)
	{
		size_width = win_width / 50;
		x = 0;
		while (size_width--)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, x * 50, y * 50);
			x++;
		}
		y++;
	}

	mlx_loop(mlx_ptr);

	return 0;
}