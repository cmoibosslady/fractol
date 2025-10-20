CC = cc

CFLAG = -Wall -Werror -Wextra

SRC = receive_and_open.c colors.c julia.c mandelbrot.c math.c complex_math.c events_and_errors.c moves.c zoom.c

OBJDIR = build

OBJS = $(SRC:.c=$(OBJDIR).o)

NAME = fractol

all: $(NAME)

libft:
	make -C libft/

$(NAME): $(OBJS)
	make libft
	$(CC) $(CFLAG) -lmlx -L mlx/ -lXext -lX11 -o $(NAME) $(OBJS) $(LIBFT) mlx/libmlx_Linux.a

$(OBJDIR)/%.o: %.c
	mkdir $(OBJDIR)
	$(CC) $(CFLAG) -I mlx/ -c $< -o $@

clean:
	cd libft && make clean
	rm -f $(OBJS)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
