#########################
######  STRUCTURE  ######
#########################

SRC_DIR			=	srcs
INC_DIRS		=	includes

BUILD_DIR		=	build
OBJ_DIR			=	${BUILD_DIR}/obj
DEP_DIR			=	${BUILD_DIR}/dep

#######################
######  SOURCES  ######
#######################

SRCS 			=	colors.c \
				  	complex_math.c \
				  	events.c \
				  	julia.c \
				  	libft.c \
				  	main.c \
					mandelbrot.c \
					math.c \
					moves.c \
					zoom.c

HEADER			=	colors.h \
					complex_nb.h \
					events.h \
					julia.h \
					libft.h \
					main.h \
					mandelbrot.h \
					moves.h \
					zoom.h 

###########################
######  COMPILATION  ######
###########################

MAKE			=	make
MAKEFLAGS 		+=	--no-print-directory
RED 			=	$(shell tput setaf 1)
GREEN			=	$(shell tput setaf 2)
CYAN			=	$(shell tput setaf 6)
RESET			=	$(shell tput setaf 255)

OBJS			=	${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
DEPS			=	${SRCS:${SRC_DIR}/%.c=${DEP_DIR}/%.d}
GET_DEP_PATH	=	${@:${OBJ_DIR}/%.o=${DEP_DIR}/.%d}

CC				=	cc
CFLAG			=	-Wall -Werror -Wextra \
					-MMD -MF $(GET_DEP_PATH)
MINILIBX_FLAGS	=	-lmlx -lXext -lX11

MKDIR			=	@mkdir -vp
RM				=	@rm -vrf

NAME			=	fractol

MINILIBX_PATH	=	minilibx-linux

#####################
######  RULES  ######
#####################

all: $(NAME)

setup-mlx: $(MINILIBX_PATH)/build/mlx.a
	@echo "MiniLibXalready built."

$(NAME): $(OBJS)
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

.PHONY: all clean fclean re setup-mlx
