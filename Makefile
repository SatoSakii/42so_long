# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 17:32:26 by albernar          #+#    #+#              #
#    Updated: 2024/10/16 17:33:17 by albernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
CC = cc
FLAGS = -Wall -Wextra -Werror -g

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# FOLDERS
OBJ_DIR = .objs

# SOURCES
GET_NEXT_LINE_PATH = ./lib/get_next_line/
FT_PRINTF_PATH = ./lib/ft_printf/
LIBFT_PATH = ./lib/libft/
LIBMLX_PATH = ./lib/MacroLibX
SRCS = \
main.c \
camera/camera.c \
game/game_init.c \
hooks/game_hooks.c \
map/map_init.c \
map/map_render.c \
map/map_wall.c \
map/map_floor.c \
map/map_others.c \
player/player_init.c \
player/player_render.c \
player/player_update.c \
enemy/enemy_init.c \
enemy/enemy_update.c \
enemy/enemy_render.c \
parsing/map_dimensions.c \
parsing/map_elements.c \
parsing/map_floodfill.c \
parsing/map_free.c \
parsing/map_parser.c \
parsing/map_utils.c \
errors/error_handler.c

# OBJECTS
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# EXECUTABLES
FT_PRINTF_LIB = $(addprefix $(FT_PRINTF_PATH), libftprintf.a)
GET_NEXT_LINE_LIB = $(addprefix $(GET_NEXT_LINE_PATH), libgnl.a)
LIBFT_LIB = $(addprefix $(LIBFT_PATH), libft.a)
NAME = so_long

# RULES
all: $(NAME)

bonus: $(NAME)

$(NAME): $(FT_PRINTF_LIB) $(GET_NEXT_LINE_LIB) $(LIBFT_LIB) $(LIBMLX_PATH)/libmlx.so $(OBJS)
	@echo "$(YELLOW)Creating $(NAME)...$(RESET)"
	@$(CC) $(FLAGS) $(OBJS) $(GET_NEXT_LINE_LIB) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(LIBMLX_PATH)/libmlx.so -lSDL2 -lm -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(LIBMLX_PATH)/libmlx.so:
	@echo "$(YELLOW)Compiling MLX42...$(RESET)"
	@make -j -C $(LIBMLX_PATH) -s
	@echo "$(GREEN)MLX42 created successfully!$(RESET)"

$(FT_PRINTF_LIB):
	@echo "$(YELLOW)Compiling FT_PRINTF...$(RESET)"
	@make -C $(FT_PRINTF_PATH) -s
	@echo "$(GREEN)FT_PRINTF created successfully!$(RESET)"
	
$(GET_NEXT_LINE_LIB):
	@echo "$(YELLOW)Compiling GET_NEXT_LINE...$(RESET)"
	@make -C $(GET_NEXT_LINE_PATH) -s
	@echo "$(GREEN)GET_NEXT_LINE created successfully!$(RESET)"

$(LIBFT_LIB):
	@echo "$(YELLOW)Compiling LIBFT...$(RESET)"
	@make -C $(LIBFT_PATH) -s
	@echo "$(GREEN)LIBFT created successfully!$(RESET)"
	
$(OBJ_DIR)/%.o: ./srcs/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) -I./includes -o $@ -c $<
	
clean:
	@echo "$(RED)Cleaning FT_PRINTF files...$(RESET)"
	@make clean -C $(FT_PRINTF_PATH) -s
	@echo "$(RED)Cleaning GET_NEXT_LINE files...$(RESET)"
	@make clean -C $(GET_NEXT_LINE_PATH) -s
	@echo "$(RED)Cleaning LIBFT files...$(RESET)"
	@make clean -C $(LIBFT_PATH) -s
	@echo "$(RED)Cleaning MLX42 files...$(RESET)"
	@make clean -C $(LIBMLX_PATH) -s
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@make fclean -C $(FT_PRINTF_PATH) -s
	@make fclean -C $(GET_NEXT_LINE_PATH) -s
	@make fclean -C $(LIBFT_PATH) -s
	@make fclean -C $(LIBMLX_PATH) -s
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re
