# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 16:26:12 by belguabd          #+#    #+#              #
#    Updated: 2024/02/17 15:23:28 by belguabd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

#------Folder------#
GET_NEXT_LINE = get_next_line
UTILS = utils
PARSING = parsing

NAME = so_long
RM = rm -f

#------Sources------#
SRC = so_long.c \
    $(GET_NEXT_LINE)/get_next_line.c $(GET_NEXT_LINE)/get_next_line_utils.c \
	$(PARSING)/parsing.c $(PARSING)/parsing_utils.c\
	$(UTILS)/ft_putstr_fd.c $(UTILS)/flood_fill.c $(UTILS)/set_width_height.c $(UTILS)/ft_set_map.c\
	$(UTILS)/render_map.c $(UTILS)/initialize_data.c $(UTILS)/close_window.c
#------Objects------#
OBJ = $(SRC:.c=.o)

#------Colors------#
GREEN = \033[32m
RED = \033[31m


all : $(NAME)
#------Rules------#
$(NAME): $(OBJ) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)Run './$(NAME)' to execute"

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

#------Compilation------#
%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

#------Clean------#
clean:
	@$(RM) $(OBJ)
	@echo "$(RED)Objects removed : \033[1;31mOK\033[m"

#------fclean------#
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Program and MiniLibX objects removed : \033[1;31mOK\033[m"

#------re------#
re: fclean all
	@echo "$(GREEN)Program recompiled : \033[1;32mOK\033[m"

#------.PHONY------#
.PHONY: clean fclean all re
