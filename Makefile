MAKE = make

MAKEFLAGS = 

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


SRC_DIR = sources

OBJ_DIR = build

HEADER_DIR = includes


OBJS = $(SRCS:%.c=${OBJ_DIR}/%.o)


INCLUDE = -I${HEADER_DIR}/ -Ilibft/include/

NAME = fractol

all: $(NAME)

libft:
	@${MAKE} -C libft/

$(NAME): $(OBJS)
	@${MAKE} libft
	$(CC) $(CFLAG) -lmlx -L mlx/ -lXext -lX11 -o $(NAME) $(OBJS) $(LIBFT) mlx/libmlx_Linux.a

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) $(INCLUDE) -I mlx/ -c $< -o $@

clean:
	cd libft && ${MAKE} clean
	rm -df $(OBJ_DIR)

fclean: clean
	cd libft && ${MAKE} fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
