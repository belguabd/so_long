/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:38:46 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/16 18:36:33 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include "./mlx.h"
void initialize_data(t_data *data);
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
void ft_set_map(t_data *data, size_t height, char const *av)
{
	char *line;
	int fd;
	size_t i = 0;
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

	fd = open(av, O_RDWR);
	if (fd < 0)
		ft_putstr_fd("Error: The file does not exist\n", 2);
	line = get_next_line(fd);
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

	i = 0;
	while (line)
	{
		data->t_map[i] = getstruntilnl(line);
		data->d_map[i] = getstruntilnl(line);
		line = get_next_line(fd);
		i++;
	}
	data->t_map[i] = NULL;
	data->d_map[i] = NULL;
	close(fd);
}
void parsing(t_data *data, size_t height, size_t width)
{
	size_t i;
	size_t j;
	size_t tmp_h;
	i = 0;

	tmp_h = height;
	while (data->t_map[i])
		if (ft_strlen(data->t_map[i++]) != width)
			ft_putstr_fd("Error: Invalid border in map\n", 2);
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
	i = 1;
	data->C_count = 0;
	size_t P_count = 0;
	size_t E_count = 0;
	while (i < tmp_h - 1)
	{
		j = 0;
		while (data->t_map[i][j])
		{
			if (data->t_map[i][j] == 'P')
				P_count++;
			if (data->t_map[i][j] == 'C')
				data->C_count++;
			if (data->t_map[i][j] == 'E')
				E_count++;
			if (data->t_map[i][j] != 'P' && data->t_map[i][j] != 'E' && data->t_map[i][j] != 'C' &&
				data->t_map[i][j] != '1' && data->t_map[i][j] != '0')
				ft_putstr_fd("Error: Invalid character in the map\n", 2);
			j++;
		}
		i++;
	}
	if (P_count != 1)
		ft_putstr_fd("Error: There should be exactly one 'P' character\n", 2);
	if (data->C_count == 0)
		ft_putstr_fd("Error: At least one 'C' character is required\n", 2);
	if (E_count != 1)
		ft_putstr_fd("Error: There should be exactly one 'E' character\n", 2);
}
void render_map(void *mlx_ptr, void *win_ptr, t_data *data)
{
	int x = 0;
	int y = 0;

	while (data->t_map[y])
	{
		x = 0;
		while (data->t_map[y][x])
		{
			if (data->t_map[y][x] == '1')
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_W, x * 50, y * 50);
			}
			else if (data->t_map[y][x] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_E, x * 50, y * 50);
			else if (data->t_map[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_C, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_P, data->p_x * 50, data->p_y * 50);
}
void update_position_and_map(t_data *data, size_t new_y, size_t new_x)
{

	char *element = &data->t_map[new_y][new_x];
	if (*element == 'C' || *element == '0' || *element == 'P' || *element == 'E')
	{
		if (*element == 'C')
		{
			data->C_count--;
			*element = '0';
		}

		data->p_y = new_y;
		data->p_x = new_x;
		printf("%zu\n", data->nbr_move++);
	}
	if (data->C_count == 0)
	{
		data->img_E = data->img_EO;
		if (*element == 'E')
		{
			write(1, "YOU WIN\n", 9);
			exit(0);
		}
	}
}
int key_handler(int keycode, t_data *data)
{

	size_t new_y = data->p_y;
	size_t new_x = data->p_x;
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	else if (keycode == KEY_DOWN)
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
	render_map(data->mlx_ptr, data->win_ptr, data);
	return (0);
}
void display(t_data data)
{
	int x = 0;
	int y = 0;
	while (data.d_map[y])
	{
		x = 0;
		while (data.d_map[y][x])
		{
			printf("%c", data.d_map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
void flood_fill(t_data data, size_t y, size_t x)
{
	if (data.d_map[y][x] == '1' || data.d_map[y][x] == 'v')
		return;
	data.d_map[y][x] = 'v';
	flood_fill(data, y + 1, x);
	flood_fill(data, y - 1, x);
	flood_fill(data, y, x + 1);
	flood_fill(data, y, x - 1);
}
bool has_elements(t_data data)
{

	bool check = false;
	int x = 0;
	int y = 0;
	while (data.d_map[y])
	{
		x = 0;
		while (data.d_map[y][x])
		{
			if (data.d_map[y][x] == 'C' || data.d_map[y][x] == 'E')
				check = true;
			x++;
		}
		y++;
	}
	return (check);
}
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
void initialize_data(t_data *data)
{
	int w;
	int h;
	data->C_count = 0;
	data->nbr_move = 0;
	data->img_B = mlx_xpm_file_to_image(data->mlx_ptr, "./background.xpm", &w, &h);
	if (!data->img_B)
		ft_putstr_fd("Error: The background image is not found\n", 2);
	data->img_C = mlx_xpm_file_to_image(data->mlx_ptr, "./coll.xpm", &w, &h);
	if (!data->img_C)
		ft_putstr_fd("Error: The collectible image is not found\n", 2);
	data->img_W = mlx_xpm_file_to_image(data->mlx_ptr, "./wall.xpm", &w, &h);
	if (!data->img_W)
		ft_putstr_fd("Error: The wall image is not found\n", 2);
	data->img_P = mlx_xpm_file_to_image(data->mlx_ptr, "./player.xpm", &w, &h);
	if (!data->img_P)
		ft_putstr_fd("Error: The player image is not found\n", 2);
	data->img_E = mlx_xpm_file_to_image(data->mlx_ptr, "./the_door_v1.xpm", &w, &h);
	if (!data->img_E)
		ft_putstr_fd("Error: The door image is not found\n", 2);
	data->img_EO = mlx_xpm_file_to_image(data->mlx_ptr, "./open_door_v1.xpm", &w, &h);
	if (!data->img_EO)
		ft_putstr_fd("Error: The open door image is not found\n", 2);
}
int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}
int main(int ac, char const *av[])
{
	if (ac != 2)
		ft_putstr_fd("Error: The number of arguments is invalid\n", 2);
	if (valid_file(av[1]))
		ft_putstr_fd("Error: The file is not a .ber file\n", 2);
	t_data data;
	set_width_height(&data, av[1]);
	if (data.height > 28 || data.width > 51)
		ft_putstr_fd("Error: The map is too large\n", 2);
	data.mlx_ptr = mlx_init();
	initialize_data(&data);
	set_width_height(&data, av[1]);
	ft_set_map(&data, data.height, av[1]);
	if (!data.t_map[0][0])
		ft_putstr_fd("Error: The map is empty\n", 2);

	parsing(&data, data.height, data.width);
	size_t win_width = data.width * 50;
	size_t win_height = data.height * 50;

	data.win_ptr = mlx_new_window(data.mlx_ptr, win_width, win_height, "so_long");
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
	flood_fill(data, data.p_y, data.p_x);
	if (has_elements(data))
		ft_putstr_fd("Invalid map\n", 2);
	flood_fill(data, data.p_y, data.p_x);
	mlx_hook(data.win_ptr, 2, 0, key_handler, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	render_map(data.mlx_ptr, data.win_ptr, &data);

	mlx_loop(data.mlx_ptr);
	return (0);
}