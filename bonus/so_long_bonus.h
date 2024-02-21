/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:21:51 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/21 19:58:56 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <mlx.h>
/*start get_next_line*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *line, char *buffer);
/*end get_next_line*/
typedef struct data
{
	size_t	width;
	size_t	height;
	char	**t_map;
	char	**d_map;
	size_t	p_x;
	size_t	p_y;
	void	*mlx_ptr;
	void	*win_ptr;
	size_t	nbr_move;
	void	*img_p;
	void	*img_b;
	void	*img_c;
	void	*img_w;
	void	*img_e;
	void	*img_eo;
	void	*img_d;
	void	*img_l;
	size_t	c_count;
	size_t	p_count;
	size_t	e_count;
	size_t	enemy_dir;
	size_t	d_x;
	size_t	d_y;
	size_t	old_d_x;
	size_t	old_d_y;
	int		nbr_enemy;
	int		w;
	int		h;
}	t_data;

/*struct enemy*/
typedef struct enemies_solong
{
	size_t	enemy_dir;
	size_t	d_x;
	size_t	d_y;
	size_t	old_d_x;
	size_t	old_d_y;

}	t_enemy;
/*libft*/
char	*ft_strchr(const char *s, int c);

/*macro*/
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define ESC 53

/*parsing*/
void	parsing(t_data *data, size_t height, size_t width);
void	validate_and_set_params(t_data *data, char const *av, int ac);
int		valid_file(char const *file);
/*utils*/
void	ft_putstr_fd(char *s, int fd);
void	flood_fill(t_data data, size_t y, size_t x);
bool	has_elements(t_data data);
void	set_width_height(t_data *data, char const *av);
void	ft_set_map(t_data *data, size_t height, char const *av);
void	render_map(t_data *data);
void	initialize_data(t_data *data, int w, int h);
int		close_window(t_data *data);

/*functions for animation*/
int		animation(t_data *data);
void	find_pos_mld(t_data data, t_enemy *enemies, int *i);
void	init_enemies(t_enemy *enemies, int max_enemy, t_data data);

/*print moves*/
void	ft_itoa(int n, char **nbr, char *word, t_data *data);
/*free*/
void	free_enemies(t_enemy *enemies);
void	free_map_data(t_data *data);
void	ft_free_main(t_data *data, char *mes_error);
/*struct for inti images*/
typedef struct list_imgs
{
	char	*img_b;
	char	*img_c;
	char	*img_w;
	char	*img_p;
	char	*img_e;
	char	*img_eo;
	char	*img_l;
	char	*img_d;

}	t_imge;
/*find location player*/
void	locate_player_in_map(t_data *data);

/*check map is empty*/
void	ft_check_empty_map(t_data *data);
/*function you win*/
void	ft_you_win(t_data *data);
#endif
