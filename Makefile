# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 16:26:12 by belguabd          #+#    #+#              #
#    Updated: 2024/02/17 17:37:06 by belguabd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

#------Folder------#
GET_NEXT_LINE = get_next_line
UTILS = utils
PARSING = parsing

NAME = so_long
NAME_BONUS = so_long_bonus
BONUS=bonus
RM = rm -f

#------Sources------#
SRC = so_long.c \
    $(GET_NEXT_LINE)/get_next_line.c $(GET_NEXT_LINE)/get_next_line_utils.c \
	$(PARSING)/parsing.c $(PARSING)/parsing_utils.c\
	$(UTILS)/ft_putstr_fd.c $(UTILS)/flood_fill.c $(UTILS)/set_width_height.c $(UTILS)/ft_set_map.c\
	$(UTILS)/render_map.c $(UTILS)/initialize_data.c $(UTILS)/close_window.c
SRC_B = so_long.c \
    $(BONUS)/$(GET_NEXT_LINE)/get_next_line.c $(BONUS)/$(GET_NEXT_LINE)/get_next_line_utils.c \
	$(BONUS)/$(PARSING)/parsing.c $(BONUS)/$(PARSING)/parsing_utils.c\
	$(BONUS)/$(UTILS)/ft_putstr_fd.c $(BONUS)/$(UTILS)/flood_fill.c $(BONUS)/$(UTILS)/set_width_height.c $(BONUS)/$(UTILS)/ft_set_map.c\
	$(BONUS)/$(UTILS)/render_map.c $(BONUS)/$(UTILS)/initialize_data.c $(BONUS)/$(UTILS)/close_window.c
#------Objects------#
OBJ = $(SRC:.c=.o)
OBJB = $(SRC_B:.c=.o)
#------Colors------#
GREEN = \033[34m
RED = \033[31m


all : $(NAME)
#------Rules------#
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)Run './$(NAME)' to execute"

#------Bonus------#
bonus:$(OBJB)
	@$(CC) $(CFLAGS) $(OBJB) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "$(GREEN)Run './$(NAME_BONUS)' to execute"
	
	
#------Compilation------#
%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

#------Clean------#
clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJB)
	@echo "$(RED)Objects removed : \033[1;31mOK\033[m"

#------fclean------#
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo "$(RED)Program and MiniLibX objects removed : \033[1;31mOK\033[m"

#------re------#
re: fclean all
	@echo "$(GREEN)Program recompiled : \033[1;34mOK\033[m"

#------.PHONY------#
.PHONY: clean fclean all re
