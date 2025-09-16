# **************************************************************************** #
#                                   SO_LONG                                    #
# **************************************************************************** #

NAME        = so_long

# Compilador y flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I./libft -I./src -I./minilibx-linux
MLXFLAGS	= -L minilibx-linux -lmlx -lX11 -lXext -lbsd -lm

# Directorios
SRC_DIR     = src
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

# Archivos
SRCS        = $(wildcard $(SRC_DIR)/*.c)
OBJS        = $(SRCS:.c=.o)

# Librerías
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a
LIBS        = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Reglas
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) $(MLX) -lX11 -lXext -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
