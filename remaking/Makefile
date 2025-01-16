NAME = push_swap
BNS_NAME = checker

CC = cc

# directories
SRCDIR = srcs
OBJDIR = objs
BNSDIR = bonus
INCDIR = inc

# sources
SRCS_MAIN =  main.c
SRCS_FILES =  push_swap.c \
	init_stacks.c free_stacks.c\
	compress_cmds.c cmd_push.c cmd_reverse.c cmd_rotate.c cmd_swap.c \
	sort_elems.c split_elems.c sort_few_elems.c \
	sort_utils.c ft_utils.c
SRCS = $(addprefix $(SRCDIR)/, $(SRCS_MAIN) $(SRCS_FILES))
BNS_MAIN = main_bonus.c
BNS_FILES = checker_bonus.c
BNS_SRCS = $(addprefix $(BNSDIR)/, $(BNS_MAIN) $(BNS_FILES)) \
	$(addprefix $(SRCDIR)/, $(SRCS_FILES))

# objects
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
BNS_OBJS = $(addprefix $(OBJDIR)/, $(BNS_SRCS:.c=.o))

# flags
IFLAG = -I $(INCDIR)
WFLAG = -Wall -Wextra -Werror

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(WFLAG) $(IFLAG) $(OBJS) -o $(NAME)

$(BNS_NAME): $(BNS_OBJS)
	$(CC) $(WFLAG) $(IFLAG) $(BNS_OBJS) -o $(BNS_NAME)

clean:
	$(RM) -r $(OBJDIR) $(BNS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BNS_NAME)

re: fclean all

bonus: $(NAME) $(BNS_NAME)

$(OBJDIR)/%.o:%.c
	mkdir -p $(@D)
	$(CC) -c $(WFLAG) $(IFLAG) $< -o $@

.PHONY: all clean fclean re bonus
