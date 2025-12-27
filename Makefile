GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
# SAN = -g -O0 -fno-omit-frame-pointer -fsanitize=address

NAME = cub3D

SRC = main.c \
	cleanup.c \
	rendering/init.c \
	rendering/rendering.c \
	rendering/input.c \
	rendering/utils.c \
	rendering/ray_init.c \
	rendering/dda.c \
	rendering/dda_utils.c \
	rendering/draw.c \
	rendering/movement.c \
	rendering/rotation.c \
	rendering/collision.c \
	rendering/player_dir.c \
	rendering/floor_ceiling.c

OBJ = $(SRC:.c=.o)

MLX = ./mlx
MFLAGS = -lX11 -lXext -lm -lz

PARS_DIR = parsing
LIBFT_DIR = $(PARS_DIR)/libft

MLX_LIB = $(MLX)/libmlx_Linux.a
PARS_LIB = $(PARS_DIR)/MST.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(MLX_LIB) $(PARS_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(SAN) $(OBJ) $(PARS_LIB) $(LIBFT_LIB) $(MLX_LIB) $(MFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ cub3D compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX) -I$(PARS_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) 

$(PARS_LIB): $(LIBFT_LIB)
	@make -C $(PARS_DIR) 

$(MLX_LIB):
	@make -C $(MLX) 

clean:
	@rm -f $(OBJ)
	@make -C $(PARS_DIR) clean 
	@make -C $(LIBFT_DIR) clean 
	@make -C $(MLX) clean
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(PARS_DIR) fclean 
	@make -C $(LIBFT_DIR) fclean 
	@echo "$(RED)Cleaned everything.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
