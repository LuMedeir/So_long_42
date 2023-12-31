# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 14:45:33 by lumedeir          #+#    #+#              #
#    Updated: 2023/08/23 09:51:32 by lumedeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the executable
NAME = so_long
NAME_BONUS = so_long_bonus
# Compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 
LFLAGS = -lmlx -lXext -lX11
BUILD = ./objs/
BUILD_BONUS = ./objs_bonus/

# Libft
INCLUDE = -I./includes
LIBFT = ./src/Libft/

# Source files mandatory
SRC =	get_map.c check_path.c \
		valid_map.c so_long.c \
		init_game.c render_map.c \
		get_img.c destroy.c \
		play.c update_player.c\

# Source files bonus
SRC_BONUS = get_map.c check_path.c \
			valid_map_bonus.c so_long.c \
			init_game.c render_map_bonus.c \
			get_img.c destroy.c \
			play.c update_player.c\

# Building object files
$(BUILD)%.o:src/%.c
		@mkdir -p $(BUILD) 
		@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(BUILD_BONUS)%.o:src/%.c
		@mkdir -p $(BUILD_BONUS) 
		@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

# Object files
OBJ = $(addprefix $(BUILD), $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(BUILD_BONUS), $(SRC_BONUS:.c=.o))

# Color codes for terminal output
PURPLE = \033[1;35m
WHITE = \033[1;37m
CYAN= \033[0;36m

# The default target calling for the executable mandatory
all: $(NAME)

# The target to build the mandatory part
$(NAME) : $(OBJ)
		@make -C $(LIBFT)
		@$(CC) $(OBJ) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME) $(LFLAGS)
		@echo "$(PURPLE)The Makefile of [$(CYAN)SO_LONG$(PURPLE)] has been compiled!🤠"

# The default target calling for the executable bonus
bonus : $(NAME_BONUS)

# The target to build the bonus part
$(NAME_BONUS) : $(OBJ_BONUS)
		@make -C $(LIBFT)
		@$(CC) $(OBJ_BONUS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME_BONUS) $(LFLAGS)
		@echo "$(PURPLE)The Makefile of [$(CYAN)SO_LONG_BONUS$(PURPLE)] has been compiled!🤠"

# Cleans object files and dependencies
clean:
		@make fclean -C $(LIBFT)
		@rm -rf $(BUILD) $(BUILD_BONUS)

# Cleans object files and dependencies
fclean: clean
		@echo "$(WHITE)   Cleaning all... 🧹"
		@make fclean -C $(LIBFT)
		@rm -f $(NAME) $(NAME_BONUS)
		@echo "$(WHITE)✨ Cleaning complete! ✨"

# Cleans everything generated by the Makefile and rebuild all
re: fclean all
rebonus: fclean bonus

# Phony targets
.PHONY: all clean fclean re rebonus