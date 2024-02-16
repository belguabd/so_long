# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 16:26:12 by belguabd          #+#    #+#              #
#    Updated: 2024/02/16 15:25:00 by belguabd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

#------Folder------#
GET_NEXT_LINE = get_next_line
UTILS = utils

NAME_PROG = so_long
RM = rm -f

#------Sources------#
SRC = so_long.c \
    $(GET_NEXT_LINE)/get_next_line.c $(GET_NEXT_LINE)/get_next_line_utils.c \

#------Objects------#
OBJ = $(SRC:.c=.o)

#------Colors------#
GREEN = \033[32m
RED = \033[31m



#------Rules------#
$(NAME_PROG): $(OBJ) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME_PROG)
	@echo "$(GREEN)Run './$(NAME_PROG)' to execute"

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
	@$(RM) $(NAME_PROG)
	@echo "$(RED)Program and MiniLibX objects removed : \033[1;31mOK\033[m"

#------re------#
re: fclean all
	@echo "$(GREEN)Program recompiled : \033[1;32mOK\033[m"

#------.PHONY------#
.PHONY: clean fclean all re
