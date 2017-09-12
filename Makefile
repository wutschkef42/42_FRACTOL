

NAME = fractol

#directories
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj
LIBFT_DIR = ./lib/libft
MLX_DIR = ./lib/mlx

# src / obj files

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/colorize.c \
		$(SRC_DIR)/fractal_exists.c \
		$(SRC_DIR)/generate_fractal.c \
		$(SRC_DIR)/julia.c \
		$(SRC_DIR)/mandelbrot.c \
		$(SRC_DIR)/plot_point.c \
		$(SRC_DIR)/print_man.c \
		$(SRC_DIR)/quadratic_iterator.c

OBJ =	$(SRC:.c=.o)


# compiler and flags

CC =		gcc


# frameworks

FRM =		-framework AppKit -framework OpenGL

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(FRM)