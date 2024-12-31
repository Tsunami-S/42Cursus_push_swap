NAME = push_swap
CC = cc
RM = rm -rf
WFLAG = -Wall -Wextra -Werror

SRCS = push_swap.c main.c \
	command_push.c command_reverse.c command_rotate.c command_swap.c \
	init_list.c list_utils.c sort.c ft_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(WFLAG) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

%.o:%.c
	$(CC) -c $(WFLAG) -c $< -o $@

.PHONY: all clean fclean re
