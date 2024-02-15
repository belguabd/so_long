/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:38:46 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/15 08:54:25 by belguabd         ###   ########.fr       */
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
void render_map(void *mlx_ptr, void *win_ptr, t_data *data, void *img)
{
	int x = 0;
	int y = 0;
	int w;
	int h;
	while (data->t_map[y])
	{
		x = 0;
		while (data->t_map[y][x])
		{
			if (data->t_map[y][x] == '1')
			{
				img = mlx_xpm_file_to_image(mlx_ptr, "./wall.xpm", &w, &h);
				mlx_put_image_to_window(mlx_ptr, win_ptr, img, x * 50, y * 50);
			}
			else if (data->t_map[y][x] == 'P')
			{
				img = mlx_xpm_file_to_image(mlx_ptr, "./player.xpm", &w, &h);
				mlx_put_image_to_window(mlx_ptr, win_ptr, img, data->p_x * 50, data->p_y * 50);
			}
			else if (data->t_map[y][x] == 'C')
			{
				img = mlx_xpm_file_to_image(mlx_ptr, "./coll.xpm", &w, &h);
				mlx_put_image_to_window(mlx_ptr, win_ptr, img, x * 50, y * 50);
			}
			else if (data->t_map[y][x] == 'E')
			{
				img = mlx_xpm_file_to_image(mlx_ptr, "./door.xpm", &w, &h);
				mlx_put_image_to_window(mlx_ptr, win_ptr, img, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}
void update_position_and_map(t_data *data, size_t new_y, size_t new_x)
{
	char *element = &data->t_map[new_y][new_x];
	if (*element == 'C' || *element == '0')
	{
		if (*element == 'C')
		{
			*element = '0';
		}
		data->p_y = new_y;
		data->p_x = new_x;
	}
}
int key_handler(int keycode, t_data *data)
{
	size_t new_y = data->p_y;
	size_t new_x = data->p_x;

	if (keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_LEFT)
		new_x--;

	else if (keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_RIGHT)
		new_x++;
	update_position_and_map(data, new_y, new_x);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_B, 50, 50);
	render_map(data->mlx_ptr, data->win_ptr, data, data->img_B);
	return (0);
}
int main()
{
	t_data data;

	int w;
	int h;
	set_width_height(&data);
	ft_set_map(&data, data.height);
	if (!data.t_map[0][0])
		ft_putstr_fd("Error: The map is empty\n", 2);
	parsing(data, data.height, data.width);

	size_t win_width = data.width * 50;
	size_t win_height = data.height * 50;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, win_width, win_height, "so_long");
	data.img_B = mlx_xpm_file_to_image(data.mlx_ptr, "./background.xpm", &w, &h);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_B, 50, 50);
	int x = 0;
	int y = 0;
	while (data.t_map[y])
	{
		x = 0;
		while (data.t_map[y][x])
		{
			if (data.t_map[y][x] == 'P')
			{
				data.p_x = x;
				data.p_y = y;
				break;
			}
			x++;
		}
		y++;
	}
	mlx_hook(data.win_ptr, 2, 0, key_handler, &data);
	render_map(data.mlx_ptr, data.win_ptr, &data, data.img_B);
	mlx_loop(data.mlx_ptr);
	return (0);
}
