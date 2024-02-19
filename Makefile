# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 16:26:12 by belguabd          #+#    #+#              #
#    Updated: 2024/02/19 21:28:59 by belguabd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast

#------Folder------#
GET_NEXT_LINE = get_next_line
UTILS = utils
PARSING = parsing

NAME = so_long
NAME_BONUS = so_long_bonus
BONUS=bonus
RM = rm -f

#------Sources------#
SRC = ./mandatory/so_long.c \
	./mandatory/$(GET_NEXT_LINE)/get_next_line.c ./mandatory/$(GET_NEXT_LINE)/get_next_line_utils.c \
	./mandatory/$(PARSING)/parsing.c ./mandatory/$(PARSING)/parsing_utils.c\
	./mandatory/$(UTILS)/ft_putstr_fd.c ./mandatory/$(UTILS)/flood_fill.c ./mandatory/$(UTILS)/set_width_height.c ./mandatory/$(UTILS)/ft_set_map.c\
	./mandatory/$(UTILS)/render_map.c ./mandatory/$(UTILS)/initialize_data.c ./mandatory/$(UTILS)/close_window.c ./mandatory/$(UTILS)/ft_itoa.c

SRC_B =  $(BONUS)/so_long_bonus.c \
    $(BONUS)/$(GET_NEXT_LINE)/get_next_line_bonus.c $(BONUS)/$(GET_NEXT_LINE)/get_next_line_utils_bonus.c \
	$(BONUS)/$(PARSING)/parsing_bonus.c $(BONUS)/$(PARSING)/parsing_utils_bonus.c\
	$(BONUS)/$(UTILS)/ft_putstr_fd_bonus.c $(BONUS)/$(UTILS)/flood_fill_bonus.c $(BONUS)/$(UTILS)/set_width_height_bonus.c $(BONUS)/$(UTILS)/ft_set_map_bonus.c\
	$(BONUS)/$(UTILS)/render_map_bonus.c $(BONUS)/$(UTILS)/initialize_data_bonus.c $(BONUS)/$(UTILS)/close_window_bonus.c $(BONUS)/$(UTILS)/ft_itoa_bonus.c
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
./mandatory/%.o: ./mandatory/%.c ./mandatory/so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

./bonus/%.o: ./bonus/%.c ./bonus/so_long_bonus.h
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
re: fclean all bonus
	@echo "$(GREEN)Program recompiled : \033[1;34mOK\033[m"

#------.PHONY------#
.PHONY: clean fclean all re