#########################
######  STRUCTURE  ######
#########################

SRC_DIR			=	srcs
INC_DIR			=	includes

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

HEADERS			=	colors.h \
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

OBJS			=	${SRCS:%.c=${OBJ_DIR}/%.o}
DEPS			=	${SRCS:%.c=${DEP_DIR}/%.d}
GET_DEP_PATH	=	${@:${OBJ_DIR}/%.o=${DEP_DIR}/.%d}

MINILIBX_DIR	=	minilibx-linux
MINILIBX		=	$(MINILIBX_DIR)/libmlx.a

CC				=	cc
CFLAG			=	-Wall -Werror -Wextra \
					-MMD -MP
MINILIBX_FLAGS	=	-lXext -lX11
MATH_FLAGS		=	-lm

MKDIR			=	@mkdir -vp
RM				=	@rm -vrf

NAME			=	fractol

#####################
######  RULES  ######
#####################

all: $(MINILIBX) $(NAME)

-include $(DEPS)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(MINILIBX_FLAGS) $(MATH_FLAGS) $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	$(MKDIR) $(dir $@) $(dir $(GET_DEP_PATH))
	$(CC) $(CFLAG) $(MINILIBX_FLAGS) $(MATH_FLAGS) -I $(INC_DIR) \
		-c $< -o $@ \
		-MF $(DEP_DIR)/$(notdir $(basename $<)).d -MT $@

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re setup-mlx
