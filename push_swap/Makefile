# -=-=-=-=-    NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

NAME		= 	push_swap

# -=-=-=-=-    PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

INCLUDES	=	includes/

# -=-=-=-=-    FILES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRCS		=	srcs/push_swap.c	\
				srcs/check_format.c	\
				srcs/free_stacks.c	\
				srcs/get_args.c		\
				srcs/stack_utils.c	\
				srcs/stack_utils2.c	\
				srcs/swap.c			\
				srcs/push.c			\
				srcs/rotate.c		\
				srcs/rotate2.c		\
				srcs/reverse.c		\
				srcs/sort_small.c	\
				srcs/sort_big.c

HEADER		=	includes/push_swap.h

MAKE		=	Makefile

OBJS		=	$(SRCS:.c=.o)

# -=-=-=-=-    FLAGS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

CC			=	-cc
CFLAGS		=	-Werror -Wextra -Wall -g# -fsanitize=address
INCLUDE		=	-I/

# -=-=-=-=-    TARGETS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: $(NAME) make_libft

$(NAME): $(OBJS) $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE)$(HEADER) libft/libft.a -o $(NAME)

make_libft:
	make -C libft

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDE)$(HEADER) -c $< -o $@

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY:  all clean fclean re make_libft
