/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:11 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/15 16:49:21 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mlx.h>
/*start get_next_line*/
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strdup(const char *s1);
char *ft_strjoin(char *line, char *buffer);
/*end get_next_line*/

typedef struct data
{
    size_t width;
    size_t height;
    char **t_map;
    char **d_map;
    size_t p_x;
    size_t p_y;
    void *mlx_ptr;
    void *win_ptr;
    size_t C_count;
    void *img_P;
    void *img_B;
    void *img_C;
    void *img_E;
} t_data;

/*libft*/
char *ft_strchr(const char *s, int c);

/*macro*/
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124
#endif