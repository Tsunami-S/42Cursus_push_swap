NAME = push_swap
SRCDIR = srcs
INCDIR = inc
CC = cc
RM = rm -rf
IFLAG = -I $(INCDIR)
WFLAG = -Wall -Wextra -Werror

SRCS = $(addprefix $(SRCDIR)/, push_swap.c main.c \
	compress_commands.c command_push.c command_reverse.c command_rotate.c command_swap.c \
	sort_algorithm_stack_a.c sort_algorithm_stack_b.c sort_small_back_to_a.c sort_small_stack_a.c \
	sort_utils.c ft_utils.c issorted.c \
	make_stacks.c list_utils.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(WFLAG) $(IFLAG) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

%.o:%.c
	$(CC) -c $(WFLAG) $(IFLAG) $< -o $@

.PHONY: all clean fclean re
