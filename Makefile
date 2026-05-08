MAKE = make
MAKEFLAGS += --no-print-directory
RED = $(shell tput setaf 1)
GREEN = $(shell tput setaf 2)
CYAN = $(shell tput setaf 6)
RESET = $(shell tput setaf 255)

CC = cc

CFLAG = -Wall -Werror -Wextra

SRCS = receive_and_open.c \
	  colors.c \
	  julia.c \
	  mandelbrot.c \
	  math.c \
	  complex_math.c \
	  events_and_errors.c \
	  moves.c \
	  zoom.c

HEADER = fract_ol.h

SRC_DIR = srcs

OBJ_DIR = build

HEADER_DIR = includes


OBJS = $(SRCS:%.c=${OBJ_DIR}/%.o)

INCLUDE = -I ${HEADER_DIR}/

LIBFT = libft/libft.a

NAME = fractol

MINILIBX_URL = https://github.com/42Paris/minilibx-linux 
MINILIX_PATH = $(CURDIR)/minilibx

all: $(NAME)

libft:
	@${MAKE} -C libft/

setup-mlx: $(MINILIX_PATH)/build/mlx.a
	@echo "MiniLibXalready built."

$(MINILIBX_PATH)/build/mlx.a: setup-mlx | $(MINILIBX_PATH)
	@echo "--- Cloning external repository ---"
	git clone --depth 1 $(MINILIBX_URL) $(CURDIR)/external-lib-src-temp \
		&& rm -rf $(EXTERNAL_PATH)/build mlx.a \
		&& mv external-lib-src-temp $(MINILIBX_PATH) \
		@echo "--- Compiling external library ---"
	$(MAKE) -C $(MINILIBX_PATH)

$(NAME): $(OBJS)
	@${MAKE} libft
	@${MAKE} minilibx
	$(CC) $(CFLAG) -L$(MINILIBX) -lmlx -lXext -lX11 -lm -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX)libmlx_Linux.a

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) $(INCLUDE) -I libft/ -I mlx/ -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(EXTERNAL_PATH)/build libs/external-lib-src-temp

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
