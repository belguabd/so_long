/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:11 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/24 14:59:54 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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
	size_t	c_count;
	size_t	p_count;
	size_t	e_count;
}	t_data;
/*struct for inti images*/
typedef struct list_imgs
{
	char	*img_b;
	char	*img_c;
	char	*img_w;
	char	*img_p;
	char	*img_e;
	char	*img_eo;

}	t_imge;

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
void	initialize_data(t_data *data);
int		close_window(t_data *data);
/*print moves*/
void	ft_itoa(int n, char **nbr, char *word, t_data *data);
/*free*/
void	free_map_data(t_data *data);
void	ft_free_main(t_data *data, char *mes_error);
/*function you win*/
void	ft_you_win(t_data *data);
/*initialize window*/
void	initialize_window(t_data *data);
#endif