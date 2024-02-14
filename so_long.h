/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:11 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/13 16:35:37 by belguabd         ###   ########.fr       */
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
} t_data;

/*libft*/
char	*ft_strchr(const char *s, int c);

#endif