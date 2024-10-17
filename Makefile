# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 13:48:27 by hrischma          #+#    #+#              #
#    Updated: 2024/10/16 18:06:22 by hrischma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_FILE = libmlx.a

MLX_FLAG = -lX11 -lXext -lm

MLX_PATH = ./minilibx/

MLX_LIB = $(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX = $(MLX_LIB) $(MLX_FLAG)

SRC_DIR = ./src/

SRC_FILES = parsing/check_and_stock/args.c\
			parsing/check_and_stock/env.c\
			parsing/check_and_stock/open_file.c\
			parsing/clean/exit.c\
			parsing/clean/free.c\
			parsing/elements/col_and_text.c\
			parsing/elements/get_rgb.c\
			parsing/elements/parse_elements.c\
			parsing/elements/verif_elements.c\
			parsing/elements/verif_elements2.c\
			parsing/elements/get_textures.c\
			parsing/map/char_verif.c\
			parsing/map/get_map.c\
			parsing/map/get_new_map.c\
			parsing/map/parse_map.c\
			raycasting/floor_ceiling.c\
			raycasting/init_data.c\
			raycasting/init_vectors_utils.c\
			raycasting/init_vectors.c\
			raycasting/rays_calculs.c\
			raycasting/rays_casting.c\
			raycasting/draw.c\
			mlx_stuff/mlx_init.c\
			mlx_stuff/mlx_hooks.c\
			mlx_stuff/mlx_moves.c\
			main.c\

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

INC = -Iincludes/ -Ilibft -I/opt/homebrew/include

LDFLAGS = -Llibft -lft -L/opt/homebrew/lib -lreadline

OBJ_DIR = .obj/

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

LIBFT_LIB = ./libft/libft.a

MLX_LIB = ./minilibx/libmlx.a

RM = rm -rf

all: check_minilibx
	@if [ ! -f $(NAME) ] || [ `find $(OBJ) -newer $(NAME) | wc -l` -ne 0 ]; then \
		make --no-print-directory $(NAME); \
		printf "$(ERASE)$(GREEN)Program$(RESET) $(CYAN)$(BOLD)$(NAME)$(RESET) $(GREEN)created!\n$(RESET)"; \
	else \
		printf "$(ERASE)$(YELLOW)No relink needed for$(RESET) $(CYAN)$(BOLD)$(NAME)\n$(RESET)"; \
	fi

check_minilibx:
	@if [ ! -d $(MLX_PATH) ]; then \
		printf "$(ERASE)$(CYAN)$(BOLD)MLX$(RESET) not available in the directory. $(GREEN)Downloading...$(RESET)\n$(RESET)"; \
		git clone https://github.com/42Paris/minilibx-linux $(MLX_PATH) >/dev/null 2>&1; \
		printf "$(ERASE)$(CYAN)$(BOLD)MLX $(RESET)$(GREEN)was downloaded !$(RESET)\n$(RESET)"; \
	fi

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME) $(LDFLAGS) $(MLX_EX);

$(LIBFT_LIB):
	@$(MAKE) -sC libft
	@printf "$(ERASE)$(CYAN)$(BOLD)LIBFT$(RESET) $(GREEN)created!$(RESET) $(GREEN)\n$(RESET)"; \

$(MLX_LIB):
	@make -sC $(MLX_PATH) >/dev/null 2>&1
	@printf "$(ERASE)$(CYAN)$(BOLD)MLX$(RESET) $(GREEN)created!$(RESET) $(CYAN)$(BOLD)$(RESET) $(GREEN)\n$(RESET)"; \

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "$(ERASE)$(BLUE) > Compilation: $(RESET) $<"

clean:
	@printf "$(ERASE)$(GREEN)Cleaning up...$(RESET)"
	@$(MAKE) -sC libft clean
	@$(MAKE) -sC $(MLX_PATH) clean >/dev/null 2>&1
	@$(RM) ./.obj/
	@printf "$(ERASE)$(GREEN)Clean finished!\n$(RESET)"

fclean: clean
	@printf "$(ERASE)$(GREEN)Fcleaning up...$(RESET)"
	@$(RM) ${NAME}
	@$(RM) ${LIBFT_LIB} >/dev/null 2>&1
	@$(RM) ${MLX_LIB}
	@printf "$(ERASE)$(GREEN)Fclean finished!\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
.SILENT:

# COLORS
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
BOLD = \033[1m
ERASE = \033[2K\r
RESET = \033[0m